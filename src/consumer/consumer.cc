#include "consumer.h"
#include <clang/ASTMatchers/ASTMatchers.h>

struct PyMatcher : public clang::ast_matchers::MatchFinder::MatchCallback
{
    clang::ast_matchers::MatchFinder finder;
    boost::python::object callback;

    clang::ASTContext &context;
    clang::Rewriter &rewriter;

    PyMatcher(DeclMatcherCallback mcb, clang::ASTContext &context, clang::Rewriter &rewriter)
        : callback(mcb.fn), context(context), rewriter(rewriter)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    PyMatcher(TypeMatcherCallback mcb, clang::ASTContext &context, clang::Rewriter &rewriter)
        : callback(mcb.fn), context(context), rewriter(rewriter)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    PyMatcher(StmtMatcherCallback mcb, clang::ASTContext &context, clang::Rewriter &rewriter)
        : callback(mcb.fn), context(context), rewriter(rewriter)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    PyMatcher(NnsMatcherCallback mcb, clang::ASTContext &context, clang::Rewriter &rewriter)
        : callback(mcb.fn), context(context), rewriter(rewriter)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    PyMatcher(NnslMatcherCallback mcb, clang::ASTContext &context, clang::Rewriter &rewriter)
        : callback(mcb.fn), context(context), rewriter(rewriter)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    PyMatcher(TypelocMatcherCallback mcb, clang::ASTContext &context, clang::Rewriter &rewriter)
        : callback(mcb.fn), context(context), rewriter(rewriter)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    PyMatcher(CxxInitMatcherCallback mcb, clang::ASTContext &context, clang::Rewriter &rewriter)
        : callback(mcb.fn), context(context), rewriter(rewriter)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    void matchAST()
    {
        finder.matchAST(context);
    }

    void run(const clang::ast_matchers::MatchFinder::MatchResult &result)
    {
        callback(result.Nodes);
    }
};

XConsumer::XConsumer(clang::ASTContext &context, const MatcherCallbackCollection &matchers)
    : matchers(matchers)
{}

void XConsumer::HandleTranslationUnit(clang::ASTContext &context)
{
    rewriter.setSourceMgr(context.getSourceManager(), context.getLangOpts());

    using namespace clang::ast_matchers;

    std::vector<PyMatcher> finders;
    for(auto m : matchers.decl_matchers)
        finders.push_back({m, context, rewriter});

    for(auto m : matchers.type_matchers)
        finders.push_back({m, context, rewriter});

    for(auto m : matchers.stmt_matchers)
        finders.push_back({m, context, rewriter});

    for(auto m : matchers.nns_matchers)
        finders.push_back({m, context, rewriter});

    for(auto m : matchers.nnsl_matchers)
        finders.push_back({m, context, rewriter});

    for(auto m : matchers.typeloc_matchers)
        finders.push_back({m, context, rewriter});

    for(auto m : matchers.cxxinit_matchers)
        finders.push_back({m, context, rewriter});
    
    for(auto finder : finders)
        finder.matchAST();

    auto buffer = rewriter.getRewriteBufferFor(context.getSourceManager().getMainFileID());

    if(buffer != nullptr)
        buffer->write(llvm::outs());
}


