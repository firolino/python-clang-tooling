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

    PyMatcher(boost::python::object callback, clang::ASTContext &context)
        : callback(callback), context(context)
    {}

    void addMatcher(clang::ast_matchers::internal::Matcher<clang::Decl> m)
    {
        finder.addMatcher(m, this);
    }

    void matchAST()
    {
        finder.matchAST(context);
    }

    void run(const clang::ast_matchers::MatchFinder::MatchResult &result)
    {
        using namespace clang;

        for(auto &entry : result.Nodes.getMap())
        {   
            auto &id = entry.first;
            if(const auto *node = result.Nodes.getNodeAs<FunctionDecl>(id))
            {
                callback(node, id);
            }
            if(const auto *node = result.Nodes.getNodeAs<VarDecl>(id))
            {
                callback(node, id);
            }
        }
    }
};

void MMatcher::start(const std::vector<MCB> &matchers)
{
    using namespace clang::ast_matchers;

    std::vector<PyMatcher> finders;
    //std::vector<clang::ast_matchers::internal::Matcher<clang::Decl>> mms = matchers;
    //llvm::outs() << matchers.size() << "\n";
    for(auto m : matchers)
    {
        //auto mx = functionDecl().bind(".");
        //auto mmx = mms[0];//.bind(".");
        //finder.addMatcher(mx, this);
        //llvm::outs() << m.getID().second.asStringRef() <<"\n";
        //finder.addMatcher(functionDecl().bind("hhhhhhhhhhh"), this);
        PyMatcher finder(m.cb, context);
        finder.addMatcher(m.m);
        finders.push_back(finder);
    }
    //finder.addMatcher(functionDecl().bind("."), this);

    for(auto finder : finders)
        finder.matchAST();
}
#include <set>
std::set<std::string> st;
void MMatcher::run(const clang::ast_matchers::MatchFinder::MatchResult &result)
{
    using namespace clang;
/*
    const auto &ms = result.Nodes.getMap();
    for(auto &a : ms)
    {
        if(st.count(a.first.c_str()) == 0)
            {st.insert(a.first.c_str());
        llvm::outs() << a.first << "\n";}
    }

    //for(auto &x : st) llvm::outs() << x << "\n";

    if(const auto *node = result.Nodes.getNodeAs<FunctionDecl>("x"))
    {
        
    }

    if(node == nullptr)
        return;

    if(result.SourceManager->isInSystemHeader(node->getSourceRange().getBegin()))
        return;

    auto &sourceManager = context.getSourceManager();
    auto location = sourceManager.getPresumedLoc(node->getSourceRange().getBegin());
    
    llvm::outs() <<  node->getNameAsString() << " matched \n";*/
}

XConsumer::XConsumer(clang::ASTContext &context, const std::vector<MCB> &matchers)
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


