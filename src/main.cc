#include <string>
#include <boost/python.hpp>
#include <clang/ASTMatchers/ASTMatchers.h>

#include "tooling/tooling.h"

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
GENERATE_CLANG_WRAPPER(AddrLabelExpr, addrLabelExpr);
GENERATE_CLANG_WRAPPER(ArraySubscriptExpr, arraySubscriptExpr);
GENERATE_CLANG_WRAPPER(IntegerLiteral, integerLiteral);


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
    

BOOST_PYTHON_MODULE(libtooling)
{
    using namespace boost::python;

    void (Tooling::*add_decl)(clang::ast_matchers::DeclarationMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_type)(clang::ast_matchers::TypeMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_stmt)(clang::ast_matchers::StatementMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_nns)(clang::ast_matchers::NestedNameSpecifierMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_nnsl)(clang::ast_matchers::NestedNameSpecifierLocMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_typeloc)(clang::ast_matchers::TypeLocMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_cxxinit)(clang::ast_matchers::CXXCtorInitializerMatcher, boost::python::object) = &Tooling::add;

    class_<Tooling>("Tooling", init<>())
        .def(init<const std::string&>())
        .def("add", add_decl)
        .def("add", add_type)
        .def("add", add_stmt)
        .def("add", add_nns)
        .def("add", add_nnsl)
        .def("add", add_typeloc)
        .def("add", add_cxxinit)
        .def("run", &Tooling::run)
        .def("run_from_source", &Tooling::run_from_source)
    ;

    {
        using namespace clang;
        using namespace clang::ast_matchers;
        using namespace clang::ast_matchers::internal;

        EXPOSE_MATCHER(AccessSpecDecl);
        EXPOSE_MATCHER(AddrLabelExpr);
        EXPOSE_MATCHER(ArraySubscriptExpr);
        EXPOSE_MATCHER(IntegerLiteral);

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
        EXPOSE_POLY_MATCHER(equals, bool, false);
        EXPOSE_POLY_MATCHER(equals, unsigned int, 1u);
        EXPOSE_POLY_MATCHER(equals, double, 0.0);
        
        implicitly_convertible<BindableMatcher<Stmt>, Matcher<Expr>>();
        implicitly_convertible<Matcher<NamedDecl>, Matcher<ParmVarDecl>>();

        def("asString", asString);
        def("refersToType", refersToType);
        def("isInteger", isInteger);
        def("hasName", hasName);
        def("matchesName", matchesName);
        def("isPublic", isPublic);
        def("hasIndex", hasIndex);


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

    class_<clang::AddrLabelExpr>("AddrLabelExprImpl", init<const clang::AddrLabelExpr&>());
    class_<AddrLabelExpr>("AddrLabelExpr")
        .def("__call__", &AddrLabelExpr::callSimple)
    ;

    class_<clang::ArraySubscriptExpr>("ArraySubscriptExprImpl", init<const clang::ArraySubscriptExpr&>());
    class_<ArraySubscriptExpr>("ArraySubscriptExpr")
        .def("__call__", &ArraySubscriptExpr::callSimple)
        .def("__call__", 
            +[](ArraySubscriptExpr &self, clang::ast_matchers::internal::Matcher<clang::ArraySubscriptExpr> decl)
            {
                return self.callExtended(decl);
            }
        )
    ;

    class_<clang::IntegerLiteral, boost::noncopyable>("IntegerLiteralImpl", no_init);
    class_<IntegerLiteral>("IntegerLiteral")
        .def("__call__", &IntegerLiteral::callSimple)
        .def("__call__", 
            +[](IntegerLiteral &self, clang::ast_matchers::internal::Matcher<clang::IntegerLiteral> decl)
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

    AddrLabelExpr addrLabelExpr;
    scope().attr("addrLabelExpr") = addrLabelExpr;

    ArraySubscriptExpr arraySubscriptExpr;
    scope().attr("arraySubscriptExpr") = arraySubscriptExpr;

    IntegerLiteral integerLiteral;
    scope().attr("integerLiteral") = integerLiteral;

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



