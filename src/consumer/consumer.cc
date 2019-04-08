#include "consumer.h"
#include <clang/ASTMatchers/ASTMatchers.h>

MMatcher::MMatcher(clang::ASTContext &context, clang::Rewriter &rewriter)
    : context(context), rewriter(rewriter)
{}

struct PyMatcher : public clang::ast_matchers::MatchFinder::MatchCallback
{
    clang::ast_matchers::MatchFinder finder;
    boost::python::object callback;

    clang::ASTContext &context;

    PyMatcher(DeclMatcherCallback mcb, clang::ASTContext &context)
        : callback(mcb.fn), context(context)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    PyMatcher(TypeMatcherCallback mcb, clang::ASTContext &context)
        : callback(mcb.fn), context(context)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    PyMatcher(StmtMatcherCallback mcb, clang::ASTContext &context)
        : callback(mcb.fn), context(context)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    PyMatcher(NnsMatcherCallback mcb, clang::ASTContext &context)
        : callback(mcb.fn), context(context)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    PyMatcher(NnslMatcherCallback mcb, clang::ASTContext &context)
        : callback(mcb.fn), context(context)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    PyMatcher(TypelocMatcherCallback mcb, clang::ASTContext &context)
        : callback(mcb.fn), context(context)
    {
        finder.addMatcher(mcb.matcher, this);
    }

    PyMatcher(CxxInitMatcherCallback mcb, clang::ASTContext &context)
        : callback(mcb.fn), context(context)
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

void MMatcher::start(const MatcherCallbackCollection &matchers)
{
    using namespace clang::ast_matchers;

    std::vector<PyMatcher> finders;
    for(auto m : matchers.decl_matchers)
        finders.push_back({m, context});
    for(auto m : matchers.type_matchers)
        finders.push_back({m, context});
    for(auto m : matchers.stmt_matchers)
        finders.push_back({m, context});
    for(auto m : matchers.nns_matchers)
        finders.push_back({m, context});
    for(auto m : matchers.nnsl_matchers)
        finders.push_back({m, context});
    for(auto m : matchers.typeloc_matchers)
        finders.push_back({m, context});
    for(auto m : matchers.cxxinit_matchers)
        finders.push_back({m, context});
    
    for(auto finder : finders)
        finder.matchAST();
}
#include <set>
std::set<std::string> st;
void MMatcher::run(const clang::ast_matchers::MatchFinder::MatchResult &result)
{
    using namespace clang;
}

XConsumer::XConsumer(clang::ASTContext &context, const MatcherCallbackCollection &matchers)
    : matchers(matchers)
{}

void XConsumer::HandleTranslationUnit(clang::ASTContext &context)
{
    rewriter.setSourceMgr(context.getSourceManager(), context.getLangOpts());

    MMatcher matcher(context, rewriter);
    matcher.start(matchers);

    auto buffer = rewriter.getRewriteBufferFor(context.getSourceManager().getMainFileID());

    if(buffer != nullptr)
        buffer->write(llvm::outs());
}


