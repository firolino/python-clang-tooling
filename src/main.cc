#include <string>
#include <boost/python.hpp>
#include <clang/ASTMatchers/ASTMatchers.h>

#include "node-matcher.h"
#include "bound-nodes.h"
#include "wrapper-expose.h"
#include "poly-matcher.h"
#include "tooling/tooling.h"

using namespace std;

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

template<typename T>
struct make_callable_arg
{
    static auto arg() { return T(); }
};

template<typename U>
struct make_callable_arg<clang::ast_matchers::internal::Matcher<U>>
{
    static auto arg() { return clang::ast_matchers::internal::Matcher<U>(nullptr); }
};

#define EXPOSE_TYPE_TRAVERSE_MATCHER(name, arg)                                                   \
    def(STRINGIFY(name),                                                            \
        +[]()                                                                       \
        {                                                                           \
            return name();                                                          \
        }                                                                           \
    );                                                                              \
    def(STRINGIFY(name),                                                            \
        +[](Matcher<QualType> bm)                                                             \
        {                                                                           \
            return name(bm);                                                          \
        }                                                                           \
    );\
    def(STRINGIFY(name),                                                            \
        +[](Matcher<QualType> arg1, Matcher<QualType> arg2)                                                             \
        {                                                                           \
            return name(arg1, arg2);                                                          \
        }                                                                           \
    );\
    class_<decltype(name(arg))>("typematcher_" STRINGIFY(name), init<ArrayRef<const Matcher<QualType>*>>());\
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

        expose_node_matcher();
        expose_poly_matcher();        

        implicitly_convertible<BindableMatcher<Stmt>, Matcher<Expr>>();
        implicitly_convertible<BindableMatcher<Type>, Matcher<QualType>>();
        implicitly_convertible<Matcher<NamedDecl>, Matcher<ParmVarDecl>>();
        implicitly_convertible<Matcher<Type>, Matcher<QualType>>();
        implicitly_convertible<Matcher<Stmt>, Matcher<Expr>>();


        def("asString", asString);
        def("refersToType", refersToType);
        def("isInteger", isInteger);
        def("hasName", hasName);
        def("matchesName", matchesName);
        def("isPublic", isPublic);
        def("hasIndex", hasIndex);
        def("isConstQualified", isConstQualified);
        def("isImplicit", isImplicit);

        def("unless", 
            +[](Matcher<QualType> &arg1)
            {
                return Matcher<QualType>(unless(arg1));
            }
        );  
        def("unless", 
            +[](Matcher<Decl> &arg1)
            {
                return Matcher<Decl>(unless(arg1));
            }
        );

        EXPOSE_TYPE_TRAVERSE_MATCHER(hasElementType, builtinType());        
        EXPOSE_TYPE_TRAVERSE_MATCHER(hasValueType, isInteger()); 

        expose_bound_nodes();
    }

    expose_wrapper();
}



