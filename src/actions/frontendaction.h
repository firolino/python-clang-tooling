#pragma once

#include <llvm/ADT/StringRef.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/ASTMatchers/ASTMatchers.h>

#include <memory>
#include <vector>
#include <string>

#include "../utils/matchercallback.h"


namespace clang
{
    class CompilerInstance;
}

class XFrontendAction : public clang::ASTFrontendAction 
{
    private:
        const MatcherCallbackCollection matchers;

    public:
        XFrontendAction(const MatcherCallbackCollection &matchers);
        virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &compiler, llvm::StringRef inFile) override;
};
