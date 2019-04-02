#ifndef UTILS_HPP
#define UTILS_HPP

#include <fstream>
#include <vector>
#include <string>

#include <llvm/ADT/StringRef.h>
#include <llvm/ADT/Twine.h>

#include <clang/Tooling/Tooling.h>
#include <clang/Frontend/FrontendActions.h>
#include "clang/Tooling/CompilationDatabase.h"

#include <clang/ASTMatchers/ASTMatchers.h>
#include <boost/python.hpp>


namespace utils
{
    std::vector<std::string> getSyntaxOnlyToolArgs(const std::vector<std::string> &ExtraArgs, llvm::StringRef FileName);

    bool customRunToolOnCodeWithArgs(clang::FrontendAction *frontendAction, const llvm::Twine &Code,
                                     const std::vector<std::string> &Args, const llvm::Twine &FileName,
                                     const clang::tooling::FileContentMappings &VirtualMappedFiles = clang::tooling::FileContentMappings());


    bool fileExists(const std::string &file);
    std::vector<std::string> getCompileArgs(const std::vector<clang::tooling::CompileCommand> &compileCommands);
    std::string getSourceCode(const std::string &sourceFile);

    std::string getClangBuiltInIncludePath(const std::string &fullCallPath);
}

enum DeclType
{
    nDecl,
    nFunctionDecl,
    nNamedDecl
};

struct MCB
{
    DeclType ctype;
    clang::ast_matchers::internal::Matcher<clang::Decl> m;
    boost::python::object cb;

    MCB(DeclType ctype, clang::ast_matchers::internal::Matcher<clang::Decl> m,boost::python::object cb)
        : ctype(ctype), m(m), cb(cb)
    {}
        
};



#endif
