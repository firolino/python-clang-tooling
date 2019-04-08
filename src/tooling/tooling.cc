#include "tooling.h"
#include <llvm/Support/CommandLine.h>
#include <clang/Tooling/CommonOptionsParser.h>

#include "../utils/utils.h"
#include "../actions/frontendaction.h"

Tooling::Tooling()
{}

Tooling::Tooling(const std::string &filename)
    : filename(filename)
{}

void Tooling::add(clang::ast_matchers::DeclarationMatcher matcher, boost::python::object cb)
{
    matchers.decl_matchers.push_back({matcher, cb});
}

void Tooling::add(clang::ast_matchers::TypeMatcher matcher, boost::python::object cb)
{
    matchers.type_matchers.push_back({matcher, cb});
}

void Tooling::add(clang::ast_matchers::StatementMatcher matcher, boost::python::object cb)
{
    matchers.stmt_matchers.push_back({matcher, cb});
}

void Tooling::add(clang::ast_matchers::NestedNameSpecifierMatcher matcher, boost::python::object cb)
{
    matchers.nns_matchers.push_back({matcher, cb});
}

void Tooling::add(clang::ast_matchers::NestedNameSpecifierLocMatcher matcher, boost::python::object cb)
{
    matchers.nnsl_matchers.push_back({matcher, cb});
}

void Tooling::add(clang::ast_matchers::TypeLocMatcher matcher, boost::python::object cb)
{
    matchers.typeloc_matchers.push_back({matcher, cb});
}

void Tooling::add(clang::ast_matchers::CXXCtorInitializerMatcher matcher, boost::python::object cb)
{
    matchers.cxxinit_matchers.push_back({matcher, cb});
}

void Tooling::run()
{
    using namespace clang;
    using namespace clang::tooling;
    llvm::cl::OptionCategory ctCategory("clang-tool options");

    const char *argv[] = {"exec", filename.c_str(), "--", "-std=c++11"};
    int argc = 4;
    CommonOptionsParser optionsParser(argc, argv, ctCategory);
    for(auto &sourceFile : optionsParser.getSourcePathList())
    {
        if(utils::fileExists(sourceFile) == false)
        {
            llvm::errs() << "File: " << sourceFile << " does not exist!\n";
            return;
        }

        auto sourceTxt = utils::getSourceCode(sourceFile);                
        auto compileCommands = optionsParser.getCompilations().getCompileCommands(getAbsolutePath(sourceFile));

        std::vector<std::string> compileArgs = utils::getCompileArgs(compileCommands);
        // TODO compileArgs.push_back("-I" + utils::getClangBuiltInIncludePath(argv[0]));
        compileArgs.push_back("-I/usr/lib/clang/7.0.1/include");
        //for(auto &s : compileArgs)
            //  llvm::outs() << s << "\n";

        auto xfrontendAction = new XFrontendAction(matchers);
        utils::customRunToolOnCodeWithArgs(xfrontendAction, sourceTxt, compileArgs, sourceFile);
    }
}

void Tooling::run_from_source(const std::string &sourceTxt)
{
    using namespace clang;
    using namespace clang::tooling;

    /*if(sourceTxt.empty())
    {
        llvm::errs() << "Source is empty!\n";
        return;
    }*/

    std::vector<std::string> compileArgs;
    // TODO compileArgs.push_back("-I" + utils::getClangBuiltInIncludePath(argv[0]));
    compileArgs.push_back("-I/usr/lib/clang/7.0.1/include");
    //for(auto &s : compileArgs)
        //  llvm::outs() << s << "\n";

    auto xfrontendAction = new XFrontendAction(matchers);
    utils::customRunToolOnCodeWithArgs(xfrontendAction, sourceTxt, compileArgs, "empty.cc");
}