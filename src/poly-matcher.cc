#include "poly-matcher.h"
#include <boost/python.hpp>
#include <clang/ASTMatchers/ASTMatchers.h>

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


#define STRINGIFY(str) #str

#define EXPOSE_POLY_MATCHER(name, paramT)                                      \
    def(STRINGIFY(name),                                                        \
        +[](const paramT &param1)                                                   \
        {                                                                           \
            return name(param1);                                                    \
        }                                                                           \
    );                                                                              \
                                                                                    \
    class_<decltype(name(make_callable_arg<paramT>::arg()))>("matcher_" STRINGIFY(name), init<const paramT&>()); \
    implicitly_convertible_helper<decltype(name(make_callable_arg<paramT>::arg()))>()


#define EXPOSE_POLY_MATCHER_P2(name, paramT1, paramT2)                                      \
    def(STRINGIFY(name),                                                        \
        +[](const paramT1 &param1, const paramT2 &param2)                                                   \
        {                                                                           \
            return name(param1, param2);                                                    \
        }                                                                           \
    );                                                                              \
                                                                                    \
    class_<decltype(name(make_callable_arg<paramT1>::arg(), make_callable_arg<paramT2>::arg()))>("matcher_" STRINGIFY(name), init<const paramT1&,const paramT2&>()); \
    implicitly_convertible_helper<decltype(name(make_callable_arg<paramT1>::arg(), make_callable_arg<paramT2>::arg()))>()

void expose_poly_matcher()
{
    using namespace boost::python;

    using namespace clang;
    using namespace clang::ast_matchers;
    using namespace clang::ast_matchers::internal;

    EXPOSE_POLY_MATCHER(argumentCountIs, unsigned int);
    EXPOSE_POLY_MATCHER(equals, bool);
    EXPOSE_POLY_MATCHER(equalsBoundNode, std::string);
    EXPOSE_POLY_MATCHER(equals, double);
    EXPOSE_POLY_MATCHER(equals, unsigned int);
    EXPOSE_POLY_MATCHER(hasAnyArgument, Matcher<Expr>);
    EXPOSE_POLY_MATCHER(hasAnyParameter, Matcher<ParmVarDecl>);
    EXPOSE_POLY_MATCHER(hasAnySubstatement, Matcher<Stmt>);
    EXPOSE_POLY_MATCHER(hasAnyTemplateArgument, Matcher<TemplateArgument>);
    EXPOSE_POLY_MATCHER(hasBody, Matcher<Stmt>);
    EXPOSE_POLY_MATCHER(hasCondition, Matcher<Expr>);
    EXPOSE_POLY_MATCHER(hasLHS, Matcher<Expr>);
    EXPOSE_POLY_MATCHER(hasObjectExpression, Matcher<Expr>);
    EXPOSE_POLY_MATCHER(hasOperatorName, std::string);
    EXPOSE_POLY_MATCHER(hasRHS, Matcher<Expr>);
    EXPOSE_POLY_MATCHER(hasSize, unsigned int);
    EXPOSE_POLY_MATCHER(hasSourceExpression, Matcher<Expr>);
    EXPOSE_POLY_MATCHER(hasType, Matcher<Decl>);
    EXPOSE_POLY_MATCHER(hasType, Matcher<QualType>);
    EXPOSE_POLY_MATCHER(isExpansionInFileMatching, std::string);
    EXPOSE_POLY_MATCHER(parameterCountIs, unsigned int);
    EXPOSE_POLY_MATCHER(templateArgumentCountIs, unsigned int);

    EXPOSE_POLY_MATCHER_P2(hasTemplateArgument, unsigned int, Matcher<TemplateArgument>);
    EXPOSE_POLY_MATCHER_P2(hasArgument, unsigned int, Matcher<Expr>);
    EXPOSE_POLY_MATCHER_P2(hasParameter, unsigned int, Matcher<ParmVarDecl>);
    EXPOSE_POLY_MATCHER_P2(forEachArgumentWithParam, Matcher<Expr>, Matcher<ParmVarDecl>);
}