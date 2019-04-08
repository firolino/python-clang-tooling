#pragma once

#include <clang/AST/ASTContext.h>
#include <clang/AST/ASTConsumer.h>
#include <clang/Rewrite/Core/Rewriter.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>

#include "../utils/matchercallback.h"


namespace clang
{
    class ASTContext;
}

class XConsumer : public clang::ASTConsumer 
{
    private:
    
        clang::Rewriter rewriter;
        const MatcherCallbackCollection matchers;

    public:

        explicit XConsumer(clang::ASTContext &context, const MatcherCallbackCollection &matchers);
        virtual void HandleTranslationUnit(clang::ASTContext &context) override;
};

class MMatcher : public clang::ast_matchers::MatchFinder::MatchCallback
{
    protected:

        clang::ASTContext &context;
        clang::Rewriter &rewriter;

    public:

        explicit MMatcher(clang::ASTContext &context, clang::Rewriter &rewriter);
        
        virtual void start(const MatcherCallbackCollection &matchers);
        virtual void run(const clang::ast_matchers::MatchFinder::MatchResult &result) override;

};

