#include <llvm/Support/CommandLine.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/ASTMatchers/ASTMatchers.h>

#include "actions/frontendaction.h"
#include "utils/utils.h"

#include <string>
#include <vector>
#include <boost/python.hpp>

using namespace std;
using namespace llvm;

template<typename From, typename T, typename... Args>
struct implicitly_convertible_helper_run
{
    using Runner = implicitly_convertible_helper_run<From, Args...>;

    implicitly_convertible_helper_run()
    {
        boost::python::implicitly_convertible<From, clang::ast_matchers::internal::Matcher<T>>();
        Runner run;
    }
};

template<typename From, typename T>
struct implicitly_convertible_helper_run<From, T>
{
    implicitly_convertible_helper_run()
    {
        boost::python::implicitly_convertible<From, clang::ast_matchers::internal::Matcher<T>>();
    }
};

template<typename From, typename... To>
struct implicitly_convertible_helper_impl;

template<typename From, typename... To>
struct implicitly_convertible_helper_impl<From, clang::ast_matchers::internal::TypeList<To...>>
{
    using Runner = implicitly_convertible_helper_run<From, To...>;

    implicitly_convertible_helper_impl()
    {
        Runner run;
    }
};

template<typename MatcherType>
struct implicitly_convertible_helper
{
    using Impl = implicitly_convertible_helper_impl<MatcherType, typename MatcherType::ReturnTypes>;

    implicitly_convertible_helper()
    {
        Impl run;
    }
};

namespace pywrappers
{

#define GENERATE_CLANG_WRAPPER(name, func)                                      \
struct name                                                                     \
{                                                                               \
    auto callSimple()                                                           \
    {                                                                           \
        return clang::ast_matchers::func();                                     \
    }                                                                           \
                                                                                \
    template<typename T>                                                        \
    auto callExtended(const clang::ast_matchers::internal::Matcher<T>& o)       \
    {                                                                           \
        return clang::ast_matchers::func(o);                                    \
    }                                                                           \
}

GENERATE_CLANG_WRAPPER(NamedDecl, namedDecl);
GENERATE_CLANG_WRAPPER(DeclRefExpr, declRefExpr);
GENERATE_CLANG_WRAPPER(CXXMethodDecl, cxxMethodDecl);
GENERATE_CLANG_WRAPPER(FunctionDecl, functionDecl);
GENERATE_CLANG_WRAPPER(VarDecl, varDecl);
GENERATE_CLANG_WRAPPER(Decl, decl);
GENERATE_CLANG_WRAPPER(UsingDecl, usingDecl);

GENERATE_CLANG_WRAPPER(AccessSpecDecl, accessSpecDecl);



}

#define STRINGIFY(str) #str

#define EXPOSE_MATCHER(name)                                                        \
    class_<Matcher<name>>(STRINGIFY(name), init<MatcherInterface<name>*>())         \
        .def(init<const Matcher<name>&>())

#define EXPOSE_BINDABLE_MATCHER(name)                                               \
    class_<BindableMatcher<name>, bases<Matcher<name>>>(                            \
        "BindableMatcher_" STRINGIFY(name), init<const Matcher<name>&>())           \
            .def("bind",                                                            \
                +[](BindableMatcher<name> &self, const std::string &id)             \
                {                                                                   \
                    return self.bind(id);                                           \
                }                                                                   \
            )                                                                       \
        ;                                                                           \

#define EXPOSE_POLY_MATCHER(name, paramT, arg)                                      \
        def(STRINGIFY(name),                                                        \
        +[](const paramT &param1)                                                   \
    {                                                                               \
            return name(param1);                                                    \
        }                                                                           \
    );                                                                              \
                                                                                    \
    class_<decltype(name(arg))>("matcher_" STRINGIFY(name), init<const paramT&>()); \
    implicitly_convertible_helper<decltype(name(arg))>()

#define EXPOSE_MATCHER_P1(name, paramT, arg)                                        \
    def(STRINGIFY(name), name);                                                     \
    class_<decltype(name(arg))>("matcher_" STRINGIFY(name), init<const paramT&>())  \
    

class Tooling
{
    private:
        const std::string filename;

        std::vector<MCB> matchers;

    public:
        Tooling()
        {}

        Tooling(const std::string &filename)
            : filename(filename)
        {}

        void add(clang::ast_matchers::internal::Matcher<clang::Decl> m, boost::python::object cb)
        {
            matchers.push_back({m, cb});
        }

        void run()
        {
            using namespace clang;
            using namespace clang::tooling;
            llvm::cl::OptionCategory ctCategory("clang-tool options");

            const char *argv[] = {"exec", filename.c_str(), "--", "-std=c++11"};
            int argc = 4;
            CommonOptionsParser optionsParser(argc, argv, ctCategory);
            for(auto &sourceFile : optionsParser.getSourcePathList())
            {
                if(utils::fileExists(sourceFile) == false)
                {
                    llvm::errs() << "File: " << sourceFile << " does not exist!\n";
                    return;
                }

                auto sourceTxt = utils::getSourceCode(sourceFile);                
                auto compileCommands = optionsParser.getCompilations().getCompileCommands(getAbsolutePath(sourceFile));

                std::vector<std::string> compileArgs = utils::getCompileArgs(compileCommands);
                // TODO compileArgs.push_back("-I" + utils::getClangBuiltInIncludePath(argv[0]));
                compileArgs.push_back("-I/usr/lib/clang/7.0.1/include");
                //for(auto &s : compileArgs)
                  //  llvm::outs() << s << "\n";

                auto xfrontendAction = new XFrontendAction(matchers);
                utils::customRunToolOnCodeWithArgs(xfrontendAction, sourceTxt, compileArgs, sourceFile);
            }
        }

        void run_from_source(const std::string &sourceTxt)
        {
            using namespace clang;
            using namespace clang::tooling;

            /*if(sourceTxt.empty())
            {
                llvm::errs() << "Source is empty!\n";
                return;
            }*/

            std::vector<std::string> compileArgs;
            // TODO compileArgs.push_back("-I" + utils::getClangBuiltInIncludePath(argv[0]));
            compileArgs.push_back("-I/usr/lib/clang/7.0.1/include");
            //for(auto &s : compileArgs)
                //  llvm::outs() << s << "\n";

            auto xfrontendAction = new XFrontendAction(matchers);
            utils::customRunToolOnCodeWithArgs(xfrontendAction, sourceTxt, compileArgs, "empty.cc");
        }

};

BOOST_PYTHON_MODULE(libtooling)
{
    using namespace boost::python;

    class_<Tooling>("Tooling", init<>())
        .def(init<const std::string&>())
        .def("add", &Tooling::add)
        .def("run", &Tooling::run)
        .def("run_from_source", &Tooling::run_from_source)
    ;

    {
        using namespace clang;
        using namespace clang::ast_matchers;
        using namespace clang::ast_matchers::internal;

        EXPOSE_MATCHER(AccessSpecDecl);

        EXPOSE_MATCHER(Stmt);
        EXPOSE_MATCHER(NamedDecl);
        EXPOSE_MATCHER(Decl);
        EXPOSE_MATCHER(ParmVarDecl);
        EXPOSE_MATCHER(Expr);
        EXPOSE_MATCHER(QualType);
        EXPOSE_MATCHER(TemplateArgument);
        EXPOSE_MATCHER(FunctionDecl);

        EXPOSE_BINDABLE_MATCHER(Stmt);
        EXPOSE_BINDABLE_MATCHER(FunctionDecl);
        EXPOSE_BINDABLE_MATCHER(Decl);
        
        EXPOSE_POLY_MATCHER(hasType, Matcher<QualType>, isInteger());
        EXPOSE_POLY_MATCHER(isExpansionInFileMatching, std::string, "");
        EXPOSE_POLY_MATCHER(hasAnyTemplateArgument, Matcher<TemplateArgument>, refersToType(asString("int")));
        EXPOSE_POLY_MATCHER(parameterCountIs, unsigned int, 0);
        EXPOSE_POLY_MATCHER(templateArgumentCountIs, unsigned int, 0);
        EXPOSE_POLY_MATCHER(argumentCountIs, unsigned int, 0);
        EXPOSE_POLY_MATCHER(hasAnyArgument, Matcher<Expr>, declRefExpr());
        EXPOSE_POLY_MATCHER(hasAnyParameter, Matcher<ParmVarDecl>, hasName(""));
        
        implicitly_convertible<BindableMatcher<Stmt>, Matcher<Expr>>();
        implicitly_convertible<Matcher<NamedDecl>, Matcher<ParmVarDecl>>();

        def("asString", asString);
        def("refersToType", refersToType);
        def("isInteger", isInteger);
        def("hasName", hasName);
        def("matchesName", matchesName);
        def("isPublic", isPublic);


        class_<BoundNodes>("BoundNodes", init<const BoundNodes&>())
            
            .def("getFunctionDecl", 
                +[](BoundNodes &self, const std::string &id)
                {
                    return self.getNodeAs<FunctionDecl>(id);
                }, 
                return_value_policy<reference_existing_object>()
            )
            
            .def("getVarDecl", 
                +[](BoundNodes &self, const std::string &id)
                {
                    return self.getNodeAs<VarDecl>(id);
                }, 
                return_value_policy<reference_existing_object>()
            )
        ;
    }


    using namespace pywrappers;

    class_<clang::AccessSpecDecl>("AccessSpecDeclImpl", init<const clang::AccessSpecDecl&>());
    class_<AccessSpecDecl>("AccessSpecDecl")
        .def("__call__", &AccessSpecDecl::callSimple)
        .def("__call__", 
            +[](AccessSpecDecl &self, clang::ast_matchers::internal::Matcher<clang::Decl> decl)
            {
                return self.callExtended(decl);
            }
        )
    ;

    class_<clang::CXXMethodDecl>("CxxMethodDeclImpl", init<const clang::CXXMethodDecl&>());
    class_<CXXMethodDecl>("CxxMethodDecl")
        .def("__call__", &CXXMethodDecl::callSimple)
    ;

    class_<clang::DeclRefExpr>("DeclRefExprImpl", init<const clang::DeclRefExpr&>());
    class_<DeclRefExpr>("DeclRefExpr")
        .def("__call__", &DeclRefExpr::callSimple)
    ;

    class_<Decl>("Decl")
        .def("__call__", &Decl::callSimple)
        .def("__call__", 
            +[](Decl &self, clang::ast_matchers::internal::Matcher<clang::Decl> decl)
            {
                return self.callExtended(decl);
            }
        )
    ;

    class_<UsingDecl>("UsingDecl")
        .def("__call__", &UsingDecl::callSimple)        
    ;

    class_<clang::FunctionDecl>("FunctionDeclImpl", init<const clang::FunctionDecl&>());
    class_<FunctionDecl>("FunctionDecl")
        .def("__call__", &FunctionDecl::callSimple)
        .def("__call__", 
            +[](FunctionDecl &self, clang::ast_matchers::internal::Matcher<clang::NamedDecl> namedDecl)
            {
                return self.callExtended(namedDecl);
            }
        )
    ;

    class_<clang::VarDecl>("VarDeclImpl", init<const clang::VarDecl&>());
    class_<VarDecl>("VarDecl")
        .def("__call__", &VarDecl::callSimple)
        .def("__call__", 
            +[](VarDecl &self, clang::ast_matchers::internal::Matcher<clang::ValueDecl> namedDecl)
            {
                return self.callExtended(namedDecl);
            }
        )
    ;

    class_<clang::NamedDecl>("NamedDeclImpl", init<const clang::NamedDecl&>());
    class_<NamedDecl>("NamedDecl")
        .def("__call__", &NamedDecl::callSimple)
        .def("__call__", 
            +[](NamedDecl &self, clang::ast_matchers::internal::Matcher<clang::NamedDecl> namedDecl)
            {
                return self.callExtended(namedDecl);
            }
        )
    ;

    AccessSpecDecl accessSpecDecl;
    scope().attr("accessSpecDecl") = accessSpecDecl;

    DeclRefExpr declRefExpr;
    scope().attr("declRefExpr") = declRefExpr;

    CXXMethodDecl cxxMethodDecl;
    scope().attr("cxxMethodDecl") = cxxMethodDecl;

    FunctionDecl functionDecl;
    scope().attr("functionDecl") = functionDecl;

    VarDecl varDecl;
    scope().attr("varDecl") = varDecl;

    NamedDecl namedDecl;
    scope().attr("namedDecl") = namedDecl;

    Decl decl;
    scope().attr("decl") = decl;
    
    UsingDecl usingDecl;
    scope().attr("usingDecl") = usingDecl;
}



