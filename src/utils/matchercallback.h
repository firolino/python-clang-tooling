#pragma once

#include <clang/ASTMatchers/ASTMatchers.h>
#include <boost/python/object.hpp>
#include <vector>

struct DeclMatcherCallback
{
    clang::ast_matchers::DeclarationMatcher matcher;
    boost::python::object fn;
};

struct TypeMatcherCallback
{
    clang::ast_matchers::TypeMatcher matcher;
    boost::python::object fn;
};

struct StmtMatcherCallback
{
    clang::ast_matchers::StatementMatcher matcher;
    boost::python::object fn;
};

struct NnsMatcherCallback
{
    clang::ast_matchers::NestedNameSpecifierMatcher matcher;
    boost::python::object fn;
};

struct NnslMatcherCallback
{
    clang::ast_matchers::NestedNameSpecifierLocMatcher matcher;
    boost::python::object fn;
};

struct TypelocMatcherCallback
{
    clang::ast_matchers::TypeLocMatcher matcher;
    boost::python::object fn;
};

struct CxxInitMatcherCallback
{
    clang::ast_matchers::CXXCtorInitializerMatcher matcher;
    boost::python::object fn;
};

struct MatcherCallbackCollection
{
    std::vector<DeclMatcherCallback> decl_matchers;
    std::vector<TypeMatcherCallback> type_matchers;
    std::vector<StmtMatcherCallback> stmt_matchers;
    std::vector<NnsMatcherCallback> nns_matchers;
    std::vector<NnslMatcherCallback> nnsl_matchers;
    std::vector<TypelocMatcherCallback> typeloc_matchers;
    std::vector<CxxInitMatcherCallback> cxxinit_matchers;
};