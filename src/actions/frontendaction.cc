#include "frontendaction.h"

#include <clang/AST/ASTContext.h>
#include <clang/AST/ASTConsumer.h>
#include <clang/Frontend/CompilerInstance.h>

#include "../consumer/consumer.h"

XFrontendAction::XFrontendAction(const MatcherCallbackCollection &matchers)
            : matchers(matchers) 
{}

std::unique_ptr<clang::ASTConsumer> XFrontendAction::CreateASTConsumer(clang::CompilerInstance &compiler, llvm::StringRef inFile)
{
    return std::unique_ptr<clang::ASTConsumer>(new XConsumer(compiler.getASTContext(), matchers));
}

