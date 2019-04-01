#ifndef CONSUMER_HPP
#define CONSUMER_HPP

#include <clang/AST/ASTContext.h>
#include <clang/AST/ASTConsumer.h>
#include <clang/Rewrite/Core/Rewriter.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>

#include "../utils/utils.h"


namespace clang
{
    class ASTContext;
}

class XConsumer : public clang::ASTConsumer 
{
    private:
    
        clang::Rewriter rewriter;
        const std::vector<MCB> matchers;

    public:

        explicit XConsumer(clang::ASTContext &context, const std::vector<MCB> &matchers);
        virtual void HandleTranslationUnit(clang::ASTContext &context) override;
};

class MMatcher : public clang::ast_matchers::MatchFinder::MatchCallback
{
    protected:

        clang::ASTContext &context;
        clang::Rewriter &rewriter;

    public:

        explicit MMatcher(clang::ASTContext &context, clang::Rewriter &rewriter);
        
        virtual void start(const std::vector<MCB> &matchers);
        virtual void run(const clang::ast_matchers::MatchFinder::MatchResult &result) override;

};

#endif
