#ifndef FRONTEND_ACTION_HPP
#define FRONTEND_ACTION_HPP

#include <llvm/ADT/StringRef.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/ASTMatchers/ASTMatchers.h>

#include <memory>
#include <vector>
#include <string>

#include "../utils/utils.h"


namespace clang
{
    class CompilerInstance;
}

class XFrontendAction : public clang::ASTFrontendAction 
{
    private:
        const std::vector<MCB> matchers;

    public:
        XFrontendAction(const std::vector<MCB> &matchers)
            : matchers(matchers) {}
        virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &compiler, llvm::StringRef inFile) override;
};

#endif
