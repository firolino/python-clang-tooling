#include <string>
#include <boost/python.hpp>
#include <clang/ASTMatchers/ASTMatchers.h>

#include "node-matcher.h"
#include "bound-nodes.h"
#include "tooling/tooling.h"

using namespace std;

template<typename From, typename T, typename... Args>
struct implicitly_convertible_helper_run
{
    using Runner = implicitly_convertible_helper_run<From, Args...>;

    implicitly_convertible_helper_run()
    {
        boost::python::implicitly_convertible<From, clang::ast_matchers::internal::Matcher<T>>();
        Runner run;
    }
};

template<typename From, typename T>
struct implicitly_convertible_helper_run<From, T>
{
    implicitly_convertible_helper_run()
    {
        boost::python::implicitly_convertible<From, clang::ast_matchers::internal::Matcher<T>>();
    }
};

template<typename From, typename... To>
struct implicitly_convertible_helper_impl;

template<typename From, typename... To>
struct implicitly_convertible_helper_impl<From, clang::ast_matchers::internal::TypeList<To...>>
{
    using Runner = implicitly_convertible_helper_run<From, To...>;

    implicitly_convertible_helper_impl()
    {
        Runner run;
    }
};

template<typename MatcherType>
struct implicitly_convertible_helper
{
    using Impl = implicitly_convertible_helper_impl<MatcherType, typename MatcherType::ReturnTypes>;

    implicitly_convertible_helper()
    {
        Impl run;
    }
};

namespace pywrappers
{

#define GENERATE_CLANG_WRAPPER(name, func)                                      \
struct name                                                                     \
{                                                                               \
    template<typename... ArgsT>                                                 \
    auto call(const ArgsT &... args)                                    \
    {                                                                           \
        return clang::ast_matchers::func(args...);                              \
    }                                                                           \
}

GENERATE_CLANG_WRAPPER(AccessSpecDecl, accessSpecDecl);
GENERATE_CLANG_WRAPPER(AddrLabelExpr, addrLabelExpr);
GENERATE_CLANG_WRAPPER(ArraySubscriptExpr, arraySubscriptExpr);
GENERATE_CLANG_WRAPPER(AsmStmt, asmStmt);
GENERATE_CLANG_WRAPPER(AtomicExpr, atomicExpr);
GENERATE_CLANG_WRAPPER(BinaryConditionalOperator, binaryConditionalOperator);
GENERATE_CLANG_WRAPPER(BinaryOperator, binaryOperator);
GENERATE_CLANG_WRAPPER(BlockDecl, blockDecl);
GENERATE_CLANG_WRAPPER(BlockExpr, blockExpr);
GENERATE_CLANG_WRAPPER(BreakStmt, breakStmt);
GENERATE_CLANG_WRAPPER(CallExpr, callExpr);
GENERATE_CLANG_WRAPPER(CaseStmt, caseStmt);
GENERATE_CLANG_WRAPPER(CastExpr, castExpr);
GENERATE_CLANG_WRAPPER(CharacterLiteral, characterLiteral);
GENERATE_CLANG_WRAPPER(ClassTemplateDecl, classTemplateDecl);
GENERATE_CLANG_WRAPPER(CompoundLiteralExpr, compoundLiteralExpr);
GENERATE_CLANG_WRAPPER(CompoundStmt, compoundStmt);
GENERATE_CLANG_WRAPPER(ConditionalOperator, conditionalOperator);
GENERATE_CLANG_WRAPPER(ConstantExpr, constantExpr);
GENERATE_CLANG_WRAPPER(ContinueStmt, continueStmt);
GENERATE_CLANG_WRAPPER(CStyleCastExpr, cStyleCastExpr);
GENERATE_CLANG_WRAPPER(CUDAKernelCallExpr, cudaKernelCallExpr);
GENERATE_CLANG_WRAPPER(CXXBindTemporaryExpr, cxxBindTemporaryExpr);
GENERATE_CLANG_WRAPPER(CXXBoolLiteralExpr, cxxBoolLiteral);
GENERATE_CLANG_WRAPPER(CXXCatchStmt, cxxCatchStmt);
GENERATE_CLANG_WRAPPER(CXXConstCastExpr, cxxConstCastExpr);
GENERATE_CLANG_WRAPPER(CXXConstructExpr, cxxConstructExpr);
GENERATE_CLANG_WRAPPER(CXXConstructorDecl, cxxConstructorDecl);
GENERATE_CLANG_WRAPPER(CXXConversionDecl, cxxConversionDecl);
GENERATE_CLANG_WRAPPER(CXXDefaultArgExpr, cxxDefaultArgExpr);
GENERATE_CLANG_WRAPPER(CXXDeleteExpr, cxxDeleteExpr);
GENERATE_CLANG_WRAPPER(CXXDependentScopeMemberExpr, cxxDependentScopeMemberExpr);
GENERATE_CLANG_WRAPPER(CXXDestructorDecl, cxxDestructorDecl);
GENERATE_CLANG_WRAPPER(CXXDynamicCastExpr, cxxDynamicCastExpr);
GENERATE_CLANG_WRAPPER(CXXForRangeStmt, cxxForRangeStmt);
GENERATE_CLANG_WRAPPER(CXXFunctionalCastExpr, cxxFunctionalCastExpr);
GENERATE_CLANG_WRAPPER(CXXMemberCallExpr, cxxMemberCallExpr);
GENERATE_CLANG_WRAPPER(CXXMethodDecl, cxxMethodDecl);
GENERATE_CLANG_WRAPPER(CXXNewExpr, cxxNewExpr);
GENERATE_CLANG_WRAPPER(CXXNullPtrLiteralExpr, cxxNullPtrLiteralExpr);
GENERATE_CLANG_WRAPPER(CXXOperatorCallExpr, cxxOperatorCallExpr);
GENERATE_CLANG_WRAPPER(CXXRecordDecl, cxxRecordDecl);
GENERATE_CLANG_WRAPPER(CXXReinterpretCastExpr, cxxReinterpretCastExpr);
GENERATE_CLANG_WRAPPER(CXXStaticCastExpr, cxxStaticCastExpr);
GENERATE_CLANG_WRAPPER(CXXStdInitializerListExpr, cxxStdInitializerListExpr);
GENERATE_CLANG_WRAPPER(CXXTemporaryObjectExpr, cxxTemporaryObjectExpr);
GENERATE_CLANG_WRAPPER(CXXThisExpr, cxxThisExpr);
GENERATE_CLANG_WRAPPER(CXXThrowExpr, cxxThrowExpr);
GENERATE_CLANG_WRAPPER(CXXTryStmt, cxxTryStmt);
GENERATE_CLANG_WRAPPER(CXXUnresolvedConstructExpr, cxxUnresolvedConstructExpr);
GENERATE_CLANG_WRAPPER(DeclaratorDecl, declaratorDecl);
GENERATE_CLANG_WRAPPER(ClassTemplatePartialSpecializationDecl, classTemplatePartialSpecializationDecl);
GENERATE_CLANG_WRAPPER(ClassTemplateSpecializationDecl, classTemplateSpecializationDecl);
GENERATE_CLANG_WRAPPER(DeclRefExpr, declRefExpr);
GENERATE_CLANG_WRAPPER(DeclStmt, declStmt);
GENERATE_CLANG_WRAPPER(DefaultStmt, defaultStmt);
GENERATE_CLANG_WRAPPER(DesignatedInitExpr, designatedInitExpr);
GENERATE_CLANG_WRAPPER(DoStmt, doStmt);
GENERATE_CLANG_WRAPPER(EnumConstantDecl, enumConstantDecl);
GENERATE_CLANG_WRAPPER(EnumDecl, enumDecl);
GENERATE_CLANG_WRAPPER(ExplicitCastExpr, explicitCastExpr);
GENERATE_CLANG_WRAPPER(Expr, expr);
GENERATE_CLANG_WRAPPER(ExprWithCleanups, exprWithCleanups);
GENERATE_CLANG_WRAPPER(FieldDecl, fieldDecl);
GENERATE_CLANG_WRAPPER(FloatingLiteral, floatLiteral);
GENERATE_CLANG_WRAPPER(ForStmt, forStmt);
GENERATE_CLANG_WRAPPER(FriendDecl, friendDecl);
GENERATE_CLANG_WRAPPER(FunctionDecl, functionDecl);
GENERATE_CLANG_WRAPPER(FunctionTemplateDecl, functionTemplateDecl);
GENERATE_CLANG_WRAPPER(GNUNullExpr, gnuNullExpr);
GENERATE_CLANG_WRAPPER(GotoStmt, gotoStmt);
GENERATE_CLANG_WRAPPER(IfStmt, ifStmt);
GENERATE_CLANG_WRAPPER(ImaginaryLiteral, imaginaryLiteral);
GENERATE_CLANG_WRAPPER(ImplicitCastExpr, implicitCastExpr);
GENERATE_CLANG_WRAPPER(ImplicitValueInitExpr, implicitValueInitExpr);
GENERATE_CLANG_WRAPPER(IndirectFieldDecl, indirectFieldDecl);
GENERATE_CLANG_WRAPPER(InitListExpr, initListExpr);
GENERATE_CLANG_WRAPPER(IntegerLiteral, integerLiteral);
GENERATE_CLANG_WRAPPER(LabelDecl, labelDecl);
GENERATE_CLANG_WRAPPER(LabelStmt, labelStmt);
GENERATE_CLANG_WRAPPER(LambdaExpr, lambdaExpr);
GENERATE_CLANG_WRAPPER(LinkageSpecDecl, linkageSpecDecl);
GENERATE_CLANG_WRAPPER(MaterializeTemporaryExpr, materializeTemporaryExpr);
GENERATE_CLANG_WRAPPER(MemberExpr, memberExpr);
GENERATE_CLANG_WRAPPER(NamedDecl, namedDecl);
GENERATE_CLANG_WRAPPER(NamespaceAliasDecl, namespaceAliasDecl);
GENERATE_CLANG_WRAPPER(NamespaceDecl, namespaceDecl);
GENERATE_CLANG_WRAPPER(NonTypeTemplateParmDecl, nonTypeTemplateParmDecl);
GENERATE_CLANG_WRAPPER(NullStmt, nullStmt);
GENERATE_CLANG_WRAPPER(ObjCAtCatchStmt, objcCatchStmt);
GENERATE_CLANG_WRAPPER(ObjCAtFinallyStmt, objcFinallyStmt);
GENERATE_CLANG_WRAPPER(ObjCAtThrowStmt, objcThrowStmt);
GENERATE_CLANG_WRAPPER(ObjCAtTryStmt, objcTryStmt);
GENERATE_CLANG_WRAPPER(ObjCAutoreleasePoolStmt, autoreleasePoolStmt);
GENERATE_CLANG_WRAPPER(ObjCCategoryDecl, objcCategoryDecl);
GENERATE_CLANG_WRAPPER(ObjCCategoryImplDecl, objcCategoryImplDecl);
GENERATE_CLANG_WRAPPER(ObjCImplementationDecl, objcImplementationDecl);
GENERATE_CLANG_WRAPPER(ObjCInterfaceDecl, objcInterfaceDecl);
GENERATE_CLANG_WRAPPER(ObjCIvarDecl, objcIvarDecl);
GENERATE_CLANG_WRAPPER(ObjCIvarRefExpr, objcIvarRefExpr);
GENERATE_CLANG_WRAPPER(ObjCMessageExpr, objcMessageExpr);
GENERATE_CLANG_WRAPPER(ObjCMethodDecl, objcMethodDecl);
GENERATE_CLANG_WRAPPER(ObjCPropertyDecl, objcPropertyDecl);
GENERATE_CLANG_WRAPPER(ObjCProtocolDecl, objcProtocolDecl);
GENERATE_CLANG_WRAPPER(OpaqueValueExpr, opaqueValueExpr);
GENERATE_CLANG_WRAPPER(ParenExpr, parenExpr);
GENERATE_CLANG_WRAPPER(ParenListExpr, parenListExpr);
GENERATE_CLANG_WRAPPER(ParmVarDecl, parmVarDecl);
GENERATE_CLANG_WRAPPER(PredefinedExpr, predefinedExpr);
GENERATE_CLANG_WRAPPER(RecordDecl, recordDecl);
GENERATE_CLANG_WRAPPER(ReturnStmt, returnStmt);
GENERATE_CLANG_WRAPPER(StaticAssertDecl, staticAssertDecl);
GENERATE_CLANG_WRAPPER(StmtExpr, stmtExpr);
GENERATE_CLANG_WRAPPER(StringLiteral, stringLiteral);
GENERATE_CLANG_WRAPPER(SubstNonTypeTemplateParmExpr, substNonTypeTemplateParmExpr);
GENERATE_CLANG_WRAPPER(SwitchCase, switchCase);
GENERATE_CLANG_WRAPPER(SwitchStmt, switchStmt);
GENERATE_CLANG_WRAPPER(TemplateTypeParmDecl, templateTypeParmDecl);
GENERATE_CLANG_WRAPPER(TranslationUnitDecl, translationUnitDecl);
GENERATE_CLANG_WRAPPER(TypeAliasDecl, typeAliasDecl);
GENERATE_CLANG_WRAPPER(TypeAliasTemplateDecl, typeAliasTemplateDecl);
GENERATE_CLANG_WRAPPER(TypedefDecl, typedefDecl);
GENERATE_CLANG_WRAPPER(TypedefNameDecl, typedefNameDecl);
GENERATE_CLANG_WRAPPER(UnaryExprOrTypeTraitExpr, unaryExprOrTypeTraitExpr);
GENERATE_CLANG_WRAPPER(UnaryOperator, unaryOperator);
GENERATE_CLANG_WRAPPER(UnresolvedLookupExpr, unresolvedLookupExpr);
GENERATE_CLANG_WRAPPER(UnresolvedMemberExpr, unresolvedMemberExpr);
GENERATE_CLANG_WRAPPER(UnresolvedUsingTypenameDecl, unresolvedUsingTypenameDecl);
GENERATE_CLANG_WRAPPER(UnresolvedUsingValueDecl, unresolvedUsingValueDecl);
GENERATE_CLANG_WRAPPER(UserDefinedLiteral, userDefinedLiteral);
GENERATE_CLANG_WRAPPER(UsingDecl, usingDecl);
GENERATE_CLANG_WRAPPER(UsingDirectiveDecl, usingDirectiveDecl);
GENERATE_CLANG_WRAPPER(ValueDecl, valueDecl);
GENERATE_CLANG_WRAPPER(VarDecl, varDecl);
GENERATE_CLANG_WRAPPER(WhileStmt, whileStmt);

GENERATE_CLANG_WRAPPER(ArrayType, arrayType);
GENERATE_CLANG_WRAPPER(AtomicType, atomicType);
GENERATE_CLANG_WRAPPER(AutoType, autoType);
GENERATE_CLANG_WRAPPER(BlockPointerType, blockPointerType);
GENERATE_CLANG_WRAPPER(BuiltinType, builtinType);
GENERATE_CLANG_WRAPPER(ComplexType, complexType);
GENERATE_CLANG_WRAPPER(ConstantArrayType, constantArrayType);
GENERATE_CLANG_WRAPPER(DecayedType, decayedType);
GENERATE_CLANG_WRAPPER(DecltypeType, decltypeType);
GENERATE_CLANG_WRAPPER(DependentSizedArrayType, dependentSizedArrayType);
GENERATE_CLANG_WRAPPER(ElaboratedType, elaboratedType);
GENERATE_CLANG_WRAPPER(EnumType, enumType);
GENERATE_CLANG_WRAPPER(FunctionProtoType, functionProtoType);
GENERATE_CLANG_WRAPPER(FunctionType, functionType);
GENERATE_CLANG_WRAPPER(IncompleteArrayType, incompleteArrayType);
GENERATE_CLANG_WRAPPER(InjectedClassNameType, injectedClassNameType);
GENERATE_CLANG_WRAPPER(LValueReferenceType, lValueReferenceType);
GENERATE_CLANG_WRAPPER(MemberPointerType, memberPointerType);
GENERATE_CLANG_WRAPPER(ObjCObjectPointerType, objcObjectPointerType);
GENERATE_CLANG_WRAPPER(ParenType, parenType);
GENERATE_CLANG_WRAPPER(PointerType, pointerType);
GENERATE_CLANG_WRAPPER(RecordType, recordType);
GENERATE_CLANG_WRAPPER(ReferenceType, referenceType);
GENERATE_CLANG_WRAPPER(RValueReferenceType, rValueReferenceType);
GENERATE_CLANG_WRAPPER(SubstTemplateTypeParmType, substTemplateTypeParmType);
GENERATE_CLANG_WRAPPER(TagType, tagType);
GENERATE_CLANG_WRAPPER(TemplateSpecializationType, templateSpecializationType);
GENERATE_CLANG_WRAPPER(TemplateTypeParmType, templateTypeParmType);
GENERATE_CLANG_WRAPPER(TypedefType, typedefType);
GENERATE_CLANG_WRAPPER(UnaryTransformType, unaryTransformType);
GENERATE_CLANG_WRAPPER(VariableArrayType, variableArrayType);

GENERATE_CLANG_WRAPPER(CXXCtorInitializer, cxxCtorInitializer);
GENERATE_CLANG_WRAPPER(Decl, decl);
GENERATE_CLANG_WRAPPER(NestedNameSpecifierLoc, nestedNameSpecifierLoc);
GENERATE_CLANG_WRAPPER(NestedNameSpecifier, nestedNameSpecifier);
GENERATE_CLANG_WRAPPER(QualType, qualType);
GENERATE_CLANG_WRAPPER(Stmt, stmt);
GENERATE_CLANG_WRAPPER(TemplateArgument, templateArgument);
GENERATE_CLANG_WRAPPER(TemplateName, templateName);
GENERATE_CLANG_WRAPPER(TypeLoc, typeLoc);
GENERATE_CLANG_WRAPPER(Type, type);


}

#define STRINGIFY(str) #str

#define EXPOSE_MATCHER(name)                                                        \
    class_<Matcher<name>>(STRINGIFY(name), init<MatcherInterface<name>*>())         \
        .def(init<const Matcher<name>&>())

#define EXPOSE_BINDABLE_MATCHER(name)                                               \
    class_<BindableMatcher<name>, bases<Matcher<name>>>(                            \
        "BindableMatcher_" STRINGIFY(name), init<const Matcher<name>&>())           \
            .def("bind",                                                            \
                +[](BindableMatcher<name> &self, const std::string &id)             \
                {                                                                   \
                    return self.bind(id);                                           \
                }                                                                   \
            )                                                                       \
        ;                                                                           \

#define EXPOSE_POLY_MATCHER(name, paramT, arg)                                      \
    def(STRINGIFY(name),                                                        \
        +[](const paramT &param1)                                                   \
        {                                                                           \
            return name(param1);                                                    \
        }                                                                           \
    );                                                                              \
                                                                                    \
    class_<decltype(name(arg))>("matcher_" STRINGIFY(name), init<const paramT&>()); \
    implicitly_convertible_helper<decltype(name(arg))>()

#define EXPOSE_TYPE_TRAVERSE_MATCHER(name, arg)                                                   \
    def(STRINGIFY(name),                                                            \
        +[]()                                                                       \
        {                                                                           \
            return name();                                                          \
        }                                                                           \
    );                                                                              \
    def(STRINGIFY(name),                                                            \
        +[](Matcher<QualType> bm)                                                             \
        {                                                                           \
            return name(bm);                                                          \
        }                                                                           \
    );\
    def(STRINGIFY(name),                                                            \
        +[](Matcher<QualType> arg1, Matcher<QualType> arg2)                                                             \
        {                                                                           \
            return name(arg1, arg2);                                                          \
        }                                                                           \
    );\
    class_<decltype(name(arg))>("typematcher_" STRINGIFY(name), init<ArrayRef<const Matcher<QualType>*>>());\
    implicitly_convertible_helper<decltype(name(arg))>()

#define EXPOSE_MATCHER_P1(name, paramT, arg)                                        \
    def(STRINGIFY(name), name);                                                     \
    class_<decltype(name(arg))>("matcher_" STRINGIFY(name), init<const paramT&>())  \
    

BOOST_PYTHON_MODULE(libtooling)
{
    using namespace boost::python;

    void (Tooling::*add_decl)(clang::ast_matchers::DeclarationMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_type)(clang::ast_matchers::TypeMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_stmt)(clang::ast_matchers::StatementMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_nns)(clang::ast_matchers::NestedNameSpecifierMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_nnsl)(clang::ast_matchers::NestedNameSpecifierLocMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_typeloc)(clang::ast_matchers::TypeLocMatcher, boost::python::object) = &Tooling::add;
    void (Tooling::*add_cxxinit)(clang::ast_matchers::CXXCtorInitializerMatcher, boost::python::object) = &Tooling::add;

    class_<Tooling>("Tooling", init<>())
        .def(init<const std::string&>())
        .def("add", add_decl)
        .def("add", add_type)
        .def("add", add_stmt)
        .def("add", add_nns)
        .def("add", add_nnsl)
        .def("add", add_typeloc)
        .def("add", add_cxxinit)
        .def("run", &Tooling::run)
        .def("run_from_source", &Tooling::run_from_source)
    ;

    {
        using namespace clang;
        using namespace clang::ast_matchers;
        using namespace clang::ast_matchers::internal;

        expose_node_matcher();

        EXPOSE_POLY_MATCHER(hasType, Matcher<QualType>, isInteger());
        EXPOSE_POLY_MATCHER(isExpansionInFileMatching, std::string, "");
        EXPOSE_POLY_MATCHER(hasAnyTemplateArgument, Matcher<TemplateArgument>, refersToType(asString("int")));
        EXPOSE_POLY_MATCHER(parameterCountIs, unsigned int, 0);
        EXPOSE_POLY_MATCHER(templateArgumentCountIs, unsigned int, 0);
        EXPOSE_POLY_MATCHER(argumentCountIs, unsigned int, 0);
        EXPOSE_POLY_MATCHER(hasAnyArgument, Matcher<Expr>, declRefExpr());
        EXPOSE_POLY_MATCHER(hasAnyParameter, Matcher<ParmVarDecl>, hasName(""));
        EXPOSE_POLY_MATCHER(equals, bool, false);
        EXPOSE_POLY_MATCHER(equals, unsigned int, 1u);
        EXPOSE_POLY_MATCHER(equals, double, 0.0);
        EXPOSE_POLY_MATCHER(hasSize, unsigned int, 0);

        implicitly_convertible<BindableMatcher<Stmt>, Matcher<Expr>>();
        implicitly_convertible<BindableMatcher<Type>, Matcher<QualType>>();
        implicitly_convertible<Matcher<NamedDecl>, Matcher<ParmVarDecl>>();
        implicitly_convertible<Matcher<Type>, Matcher<QualType>>();
        implicitly_convertible<Matcher<Stmt>, Matcher<Expr>>();


        def("asString", asString);
        def("refersToType", refersToType);
        def("isInteger", isInteger);
        def("hasName", hasName);
        def("matchesName", matchesName);
        def("isPublic", isPublic);
        def("hasIndex", hasIndex);
        def("isConstQualified", isConstQualified);
        def("isImplicit", isImplicit);

        def("unless", 
            +[](Matcher<QualType> &arg1)
            {
                return Matcher<QualType>(unless(arg1));
            }
        );  
        def("unless", 
            +[](Matcher<Decl> &arg1)
            {
                return Matcher<Decl>(unless(arg1));
            }
        );

        EXPOSE_TYPE_TRAVERSE_MATCHER(hasElementType, builtinType());        
        EXPOSE_TYPE_TRAVERSE_MATCHER(hasValueType, isInteger()); 

        expose_bound_nodes();
    }


    using namespace pywrappers;

    class_<clang::AccessSpecDecl>("AccessSpecDeclImpl", init<const clang::AccessSpecDecl&>());
    class_<AccessSpecDecl>("AccessSpecDecl")
        .def("__call__", 
            +[](AccessSpecDecl &self)
            {
                return self.call();
            }
        )
        .def("__call__", 
            +[](AccessSpecDecl &self, clang::ast_matchers::internal::Matcher<clang::Decl> decl)
            {
                return self.call(decl);
            }
        )
    ;

    class_<clang::AddrLabelExpr>("AddrLabelExprImpl", init<const clang::AddrLabelExpr&>());
    class_<AddrLabelExpr>("AddrLabelExpr")
        .def("__call__", 
            +[](AddrLabelExpr &self)
            {
                return self.call();
            }
        )
    ;

    class_<clang::ArraySubscriptExpr>("ArraySubscriptExprImpl", init<const clang::ArraySubscriptExpr&>());
    class_<ArraySubscriptExpr>("ArraySubscriptExpr")
        .def("__call__", 
            +[](ArraySubscriptExpr &self)
            {
                return self.call();
            }
        )
        .def("__call__", 
            +[](ArraySubscriptExpr &self, clang::ast_matchers::internal::Matcher<clang::ArraySubscriptExpr> decl)
            {
                return self.call(decl);
            }
        )
    ;

    class_<clang::ArrayType, boost::noncopyable>("ArrayTypeImpl", no_init);
    class_<ArrayType>("ArrayType")
        .def("__call__", 
            +[](ArrayType &self)
            {
                return self.call();
            }
        )
        .def("__call__", 
            +[](ArrayType &self, clang::ast_matchers::internal::Matcher<clang::ArrayType> decl)
            {
                return self.call(decl);
            }
        )
    ;

    class_<clang::AtomicType, boost::noncopyable>("AtomicTypeImpl", no_init);
    class_<AtomicType>("AtomicType")
        .def("__call__", 
            +[](AtomicType &self)
            {
                return self.call();
            }
        )
        .def("__call__", 
            +[](AtomicType &self, clang::ast_matchers::internal::Matcher<clang::AtomicType> decl)
            {
                return self.call(decl);
            }
        )
    ;

    class_<clang::ConstantArrayType, boost::noncopyable>("ConstantArrayTypeImpl", no_init);
    class_<ConstantArrayType>("ConstantArrayType")
        .def("__call__", 
            +[](ConstantArrayType &self)
            {
                return self.call();
            }
        )
        .def("__call__", 
            +[](ConstantArrayType &self, clang::ast_matchers::internal::Matcher<clang::ConstantArrayType> decl)
            {
                return self.call(decl);
            }
        )
        .def("__call__", 
            +[](ConstantArrayType &self, clang::ast_matchers::internal::Matcher<clang::ArrayType> decl)
            {
                return self.call(decl);
            }
        )
    ;

    class_<clang::QualType>("QualTypeImpl", no_init);
    class_<QualType>("QualType")
        .def("__call__", 
            +[](QualType &self)
            {
                return self.call();
            }
        )
        .def("__call__", 
            +[](QualType &self, clang::ast_matchers::internal::Matcher<clang::QualType> decl)
            {
                return self.call(decl);
            }
        )
        .def("__call__", 
            +[](QualType &self, clang::ast_matchers::internal::Matcher<clang::QualType> decl, clang::ast_matchers::internal::Matcher<clang::QualType> decl2)
            {
                return self.call(decl, decl2);
            }
        )
    ;

    class_<clang::BuiltinType, boost::noncopyable>("BuiltinTypeImpl", no_init);
    class_<BuiltinType>("BuiltinType")
        .def("__call__", 
            +[](BuiltinType &self)
            {
                return self.call();
            }
        )
        .def("__call__", 
            +[](BuiltinType &self, clang::ast_matchers::internal::Matcher<clang::BuiltinType> decl)
            {
                return self.call(decl);
            }
        )
    ;

    class_<clang::IntegerLiteral, boost::noncopyable>("IntegerLiteralImpl", no_init);
    class_<IntegerLiteral>("IntegerLiteral")
        .def("__call__", 
            +[](IntegerLiteral &self)
            {
                return self.call();
            }
        )
        .def("__call__", 
            +[](IntegerLiteral &self, clang::ast_matchers::internal::Matcher<clang::IntegerLiteral> decl)
            {
                return self.call(decl);
            }
        )
    ;

    class_<clang::AsmStmt, boost::noncopyable>("AsmStmtImpl", no_init);
    class_<AsmStmt>("AsmStmt")
        .def("__call__", 
            +[](AsmStmt &self)
            {
                return self.call();
            }
        )
    ;

    class_<clang::AtomicExpr, boost::noncopyable>("AtomicExprImpl", no_init);
    class_<AtomicExpr>("AtomicExpr")
        .def("__call__", 
            +[](AtomicExpr &self)
            {
                return self.call();
            }
        )
    ;

    class_<clang::CXXMethodDecl>("CxxMethodDeclImpl", init<const clang::CXXMethodDecl&>());
    class_<CXXMethodDecl>("CxxMethodDecl")
        .def("__call__", 
            +[](CXXMethodDecl &self)
            {
                return self.call();
            }
        )
    ;

    class_<clang::DeclRefExpr>("DeclRefExprImpl", init<const clang::DeclRefExpr&>());
    class_<DeclRefExpr>("DeclRefExpr")
        .def("__call__", 
            +[](DeclRefExpr &self)
            {
                return self.call();
            }
        )
    ;

    class_<Decl>("Decl")
        .def("__call__", 
            +[](Decl &self)
            {
                return self.call();
            }
        )
        .def("__call__", 
            +[](Decl &self, clang::ast_matchers::internal::Matcher<clang::Decl> decl)
            {
                return self.call(decl);
            }
        )
    ;

    class_<UsingDecl>("UsingDecl")
        .def("__call__", 
            +[](UsingDecl &self)
            {
                return self.call();
            }
        )        
    ;

    class_<clang::FunctionDecl>("FunctionDeclImpl", init<const clang::FunctionDecl&>());
    class_<FunctionDecl>("FunctionDecl")
        .def("__call__", 
            +[](FunctionDecl &self)
            {
                return self.call();
            }
        )
        .def("__call__", 
            +[](FunctionDecl &self, clang::ast_matchers::internal::Matcher<clang::NamedDecl> namedDecl)
            {
                return self.call(namedDecl);
            }
        )
    ;

    class_<clang::VarDecl>("VarDeclImpl", init<const clang::VarDecl&>());
    class_<VarDecl>("VarDecl")
        .def("__call__", 
            +[](VarDecl &self)
            {
                return self.call();
            }
        )
        .def("__call__", 
            +[](VarDecl &self, clang::ast_matchers::internal::Matcher<clang::ValueDecl> namedDecl)
            {
                return self.call(namedDecl);
            }
        )
    ;

    class_<clang::NamedDecl>("NamedDeclImpl", init<const clang::NamedDecl&>());
    class_<NamedDecl>("NamedDecl")
        .def("__call__", 
            +[](NamedDecl &self)
            {
                return self.call();
            }
        )
        .def("__call__", 
            +[](NamedDecl &self, clang::ast_matchers::internal::Matcher<clang::NamedDecl> namedDecl)
            {
                return self.call(namedDecl);
            }
        )
    ;

    AccessSpecDecl accessSpecDecl;
    scope().attr("accessSpecDecl") = accessSpecDecl;

    AddrLabelExpr addrLabelExpr;
    scope().attr("addrLabelExpr") = addrLabelExpr;

    ArraySubscriptExpr arraySubscriptExpr;
    scope().attr("arraySubscriptExpr") = arraySubscriptExpr;

    IntegerLiteral integerLiteral;
    scope().attr("integerLiteral") = integerLiteral;

    AsmStmt asmStmt;
    scope().attr("asmStmt") = asmStmt;

    ArrayType arrayType;
    scope().attr("arrayType") = arrayType;

    AtomicExpr atomicExpr;
    scope().attr("atomicExpr") = atomicExpr;

    AtomicType atomicType;
    scope().attr("atomicType") = atomicType;

    ConstantArrayType constantArrayType;
    scope().attr("constantArrayType") = constantArrayType;

    BuiltinType builtinType;
    scope().attr("builtinType") = builtinType;

    QualType qualType;
    scope().attr("qualType") = qualType;

    DeclRefExpr declRefExpr;
    scope().attr("declRefExpr") = declRefExpr;

    CXXMethodDecl cxxMethodDecl;
    scope().attr("cxxMethodDecl") = cxxMethodDecl;

    FunctionDecl functionDecl;
    scope().attr("functionDecl") = functionDecl;

    VarDecl varDecl;
    scope().attr("varDecl") = varDecl;

    NamedDecl namedDecl;
    scope().attr("namedDecl") = namedDecl;

    Decl decl;
    scope().attr("decl") = decl;
    
    UsingDecl usingDecl;
    scope().attr("usingDecl") = usingDecl;
}



