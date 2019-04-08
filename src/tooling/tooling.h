#pragma once

#include <string>
#include <vector>
#include <boost/python/object.hpp>
#include <clang/ASTMatchers/ASTMatchers.h>
#include "../utils/matchercallback.h"

class Tooling
{
    private:
        const std::string filename;
        MatcherCallbackCollection matchers;

    public:
        Tooling();
        Tooling(const std::string &filename);

        void add(clang::ast_matchers::DeclarationMatcher matcher, boost::python::object cb);
        void add(clang::ast_matchers::TypeMatcher matcher, boost::python::object cb);
        void add(clang::ast_matchers::StatementMatcher matcher, boost::python::object cb);
        void add(clang::ast_matchers::NestedNameSpecifierMatcher matcher, boost::python::object cb);
        void add(clang::ast_matchers::NestedNameSpecifierLocMatcher matcher, boost::python::object cb);
        void add(clang::ast_matchers::TypeLocMatcher matcher, boost::python::object cb);
        void add(clang::ast_matchers::CXXCtorInitializerMatcher matcher, boost::python::object cb);

        void run();
        void run_from_source(const std::string &sourceTxt);
};