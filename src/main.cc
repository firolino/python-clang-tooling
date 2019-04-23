#include <string>
#include <boost/python.hpp>
#include <clang/ASTMatchers/ASTMatchers.h>

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

        EXPOSE_MATCHER(AccessSpecDecl);
        EXPOSE_MATCHER(AddrLabelExpr);
        EXPOSE_MATCHER(ArraySubscriptExpr);
        EXPOSE_MATCHER(AsmStmt);
        EXPOSE_MATCHER(AtomicExpr);
        EXPOSE_MATCHER(BinaryConditionalOperator);
        EXPOSE_MATCHER(BinaryOperator);
        EXPOSE_MATCHER(BlockDecl);
        EXPOSE_MATCHER(BlockExpr);
        EXPOSE_MATCHER(BreakStmt);
        EXPOSE_MATCHER(CallExpr);
        EXPOSE_MATCHER(CaseStmt);
        EXPOSE_MATCHER(CastExpr);
        EXPOSE_MATCHER(CharacterLiteral);
        EXPOSE_MATCHER(ClassTemplateDecl);
        EXPOSE_MATCHER(CompoundLiteralExpr);
        EXPOSE_MATCHER(CompoundStmt);
        EXPOSE_MATCHER(ConditionalOperator);
        EXPOSE_MATCHER(ConstantExpr);
        EXPOSE_MATCHER(ContinueStmt);
        EXPOSE_MATCHER(CStyleCastExpr);
        EXPOSE_MATCHER(CUDAKernelCallExpr);
        EXPOSE_MATCHER(CXXBindTemporaryExpr);
        EXPOSE_MATCHER(CXXBoolLiteralExpr);
        EXPOSE_MATCHER(CXXCatchStmt);
        EXPOSE_MATCHER(CXXConstCastExpr);
        EXPOSE_MATCHER(CXXConstructExpr);
        EXPOSE_MATCHER(CXXConstructorDecl);
        EXPOSE_MATCHER(CXXConversionDecl);
        EXPOSE_MATCHER(CXXDefaultArgExpr);
        EXPOSE_MATCHER(CXXDeleteExpr);
        EXPOSE_MATCHER(CXXDependentScopeMemberExpr);
        EXPOSE_MATCHER(CXXDestructorDecl);
        EXPOSE_MATCHER(CXXDynamicCastExpr);
        EXPOSE_MATCHER(CXXForRangeStmt);
        EXPOSE_MATCHER(CXXFunctionalCastExpr);
        EXPOSE_MATCHER(CXXMemberCallExpr);
        EXPOSE_MATCHER(CXXMethodDecl);
        EXPOSE_MATCHER(CXXNewExpr);
        EXPOSE_MATCHER(CXXNullPtrLiteralExpr);
        EXPOSE_MATCHER(CXXOperatorCallExpr);
        EXPOSE_MATCHER(CXXRecordDecl);
        EXPOSE_MATCHER(CXXReinterpretCastExpr);
        EXPOSE_MATCHER(CXXStaticCastExpr);
        EXPOSE_MATCHER(CXXStdInitializerListExpr);
        EXPOSE_MATCHER(CXXTemporaryObjectExpr);
        EXPOSE_MATCHER(CXXThisExpr);
        EXPOSE_MATCHER(CXXThrowExpr);
        EXPOSE_MATCHER(CXXTryStmt);
        EXPOSE_MATCHER(CXXUnresolvedConstructExpr);
        EXPOSE_MATCHER(DeclaratorDecl);
        EXPOSE_MATCHER(ClassTemplatePartialSpecializationDecl);
        EXPOSE_MATCHER(ClassTemplateSpecializationDecl);
        EXPOSE_MATCHER(DeclRefExpr);
        EXPOSE_MATCHER(DeclStmt);
        EXPOSE_MATCHER(DefaultStmt);
        EXPOSE_MATCHER(DesignatedInitExpr);
        EXPOSE_MATCHER(DoStmt);
        EXPOSE_MATCHER(EnumConstantDecl);
        EXPOSE_MATCHER(EnumDecl);
        EXPOSE_MATCHER(ExplicitCastExpr);
        EXPOSE_MATCHER(Expr);
        EXPOSE_MATCHER(ExprWithCleanups);
        EXPOSE_MATCHER(FieldDecl);
        EXPOSE_MATCHER(FloatingLiteral);
        EXPOSE_MATCHER(ForStmt);
        EXPOSE_MATCHER(FriendDecl);
        EXPOSE_MATCHER(FunctionDecl);
        EXPOSE_MATCHER(FunctionTemplateDecl);
        EXPOSE_MATCHER(GNUNullExpr);
        EXPOSE_MATCHER(GotoStmt);
        EXPOSE_MATCHER(IfStmt);
        EXPOSE_MATCHER(ImaginaryLiteral);
        EXPOSE_MATCHER(ImplicitCastExpr);
        EXPOSE_MATCHER(ImplicitValueInitExpr);
        EXPOSE_MATCHER(IndirectFieldDecl);
        EXPOSE_MATCHER(InitListExpr);
        EXPOSE_MATCHER(IntegerLiteral);
        EXPOSE_MATCHER(LabelDecl);
        EXPOSE_MATCHER(LabelStmt);
        EXPOSE_MATCHER(LambdaExpr);
        EXPOSE_MATCHER(LinkageSpecDecl);
        EXPOSE_MATCHER(MaterializeTemporaryExpr);
        EXPOSE_MATCHER(MemberExpr);
        EXPOSE_MATCHER(NamedDecl);
        EXPOSE_MATCHER(NamespaceAliasDecl);
        EXPOSE_MATCHER(NamespaceDecl);
        EXPOSE_MATCHER(NonTypeTemplateParmDecl);
        EXPOSE_MATCHER(NullStmt);
        EXPOSE_MATCHER(ObjCAtCatchStmt);
        EXPOSE_MATCHER(ObjCAtFinallyStmt);
        EXPOSE_MATCHER(ObjCAtThrowStmt);
        EXPOSE_MATCHER(ObjCAtTryStmt);
        EXPOSE_MATCHER(ObjCAutoreleasePoolStmt);
        EXPOSE_MATCHER(ObjCCategoryDecl);
        EXPOSE_MATCHER(ObjCCategoryImplDecl);
        EXPOSE_MATCHER(ObjCImplementationDecl);
        EXPOSE_MATCHER(ObjCInterfaceDecl);
        EXPOSE_MATCHER(ObjCIvarDecl);
        EXPOSE_MATCHER(ObjCIvarRefExpr);
        EXPOSE_MATCHER(ObjCMessageExpr);
        EXPOSE_MATCHER(ObjCMethodDecl);
        EXPOSE_MATCHER(ObjCPropertyDecl);
        EXPOSE_MATCHER(ObjCProtocolDecl);
        EXPOSE_MATCHER(OpaqueValueExpr);
        EXPOSE_MATCHER(ParenExpr);
        EXPOSE_MATCHER(ParenListExpr);
        EXPOSE_MATCHER(ParmVarDecl);
        EXPOSE_MATCHER(PredefinedExpr);
        EXPOSE_MATCHER(RecordDecl);
        EXPOSE_MATCHER(ReturnStmt);
        EXPOSE_MATCHER(StaticAssertDecl);
        EXPOSE_MATCHER(StmtExpr);
        EXPOSE_MATCHER(StringLiteral);
        EXPOSE_MATCHER(SubstNonTypeTemplateParmExpr);
        EXPOSE_MATCHER(SwitchCase);
        EXPOSE_MATCHER(SwitchStmt);
        EXPOSE_MATCHER(TemplateTypeParmDecl);
        EXPOSE_MATCHER(TranslationUnitDecl);
        EXPOSE_MATCHER(TypeAliasDecl);
        EXPOSE_MATCHER(TypeAliasTemplateDecl);
        EXPOSE_MATCHER(TypedefDecl);
        EXPOSE_MATCHER(TypedefNameDecl);
        EXPOSE_MATCHER(UnaryExprOrTypeTraitExpr);
        EXPOSE_MATCHER(UnaryOperator);
        EXPOSE_MATCHER(UnresolvedLookupExpr);
        EXPOSE_MATCHER(UnresolvedMemberExpr);
        EXPOSE_MATCHER(UnresolvedUsingTypenameDecl);
        EXPOSE_MATCHER(UnresolvedUsingValueDecl);
        EXPOSE_MATCHER(UserDefinedLiteral);
        EXPOSE_MATCHER(UsingDecl);
        EXPOSE_MATCHER(UsingDirectiveDecl);
        EXPOSE_MATCHER(ValueDecl);
        EXPOSE_MATCHER(VarDecl);
        EXPOSE_MATCHER(WhileStmt);

        EXPOSE_MATCHER(ArrayType);
        EXPOSE_MATCHER(AtomicType);
        EXPOSE_MATCHER(AutoType);
        EXPOSE_MATCHER(BlockPointerType);
        EXPOSE_MATCHER(BuiltinType);
        EXPOSE_MATCHER(ComplexType);
        EXPOSE_MATCHER(ConstantArrayType);
        EXPOSE_MATCHER(DecayedType);
        EXPOSE_MATCHER(DecltypeType);
        EXPOSE_MATCHER(DependentSizedArrayType);
        EXPOSE_MATCHER(ElaboratedType);
        EXPOSE_MATCHER(EnumType);
        EXPOSE_MATCHER(FunctionProtoType);
        EXPOSE_MATCHER(FunctionType);
        EXPOSE_MATCHER(IncompleteArrayType);
        EXPOSE_MATCHER(InjectedClassNameType);
        EXPOSE_MATCHER(LValueReferenceType);
        EXPOSE_MATCHER(MemberPointerType);
        EXPOSE_MATCHER(ObjCObjectPointerType);
        EXPOSE_MATCHER(ParenType);
        EXPOSE_MATCHER(PointerType);
        EXPOSE_MATCHER(RecordType);
        EXPOSE_MATCHER(ReferenceType);
        EXPOSE_MATCHER(RValueReferenceType);
        EXPOSE_MATCHER(SubstTemplateTypeParmType);
        EXPOSE_MATCHER(TagType);
        EXPOSE_MATCHER(TemplateSpecializationType);
        EXPOSE_MATCHER(TemplateTypeParmType);
        EXPOSE_MATCHER(TypedefType);
        EXPOSE_MATCHER(UnaryTransformType);
        EXPOSE_MATCHER(VariableArrayType);

        EXPOSE_MATCHER(CXXCtorInitializer);
        EXPOSE_MATCHER(Decl);
        EXPOSE_MATCHER(NestedNameSpecifierLoc);
        EXPOSE_MATCHER(NestedNameSpecifier);
        EXPOSE_MATCHER(QualType);
        EXPOSE_MATCHER(Stmt);
        EXPOSE_MATCHER(TemplateArgument);
        EXPOSE_MATCHER(TemplateName);
        EXPOSE_MATCHER(TypeLoc);
        EXPOSE_MATCHER(Type);



                EXPOSE_BINDABLE_MATCHER(AccessSpecDecl);
        EXPOSE_BINDABLE_MATCHER(AddrLabelExpr);
        EXPOSE_BINDABLE_MATCHER(ArraySubscriptExpr);
        EXPOSE_BINDABLE_MATCHER(AsmStmt);
        EXPOSE_BINDABLE_MATCHER(AtomicExpr);
        EXPOSE_BINDABLE_MATCHER(BinaryConditionalOperator);
        EXPOSE_BINDABLE_MATCHER(BinaryOperator);
        EXPOSE_BINDABLE_MATCHER(BlockDecl);
        EXPOSE_BINDABLE_MATCHER(BlockExpr);
        EXPOSE_BINDABLE_MATCHER(BreakStmt);
        EXPOSE_BINDABLE_MATCHER(CallExpr);
        EXPOSE_BINDABLE_MATCHER(CaseStmt);
        EXPOSE_BINDABLE_MATCHER(CastExpr);
        EXPOSE_BINDABLE_MATCHER(CharacterLiteral);
        EXPOSE_BINDABLE_MATCHER(ClassTemplateDecl);
        EXPOSE_BINDABLE_MATCHER(CompoundLiteralExpr);
        EXPOSE_BINDABLE_MATCHER(CompoundStmt);
        EXPOSE_BINDABLE_MATCHER(ConditionalOperator);
        EXPOSE_BINDABLE_MATCHER(ConstantExpr);
        EXPOSE_BINDABLE_MATCHER(ContinueStmt);
        EXPOSE_BINDABLE_MATCHER(CStyleCastExpr);
        EXPOSE_BINDABLE_MATCHER(CUDAKernelCallExpr);
        EXPOSE_BINDABLE_MATCHER(CXXBindTemporaryExpr);
        EXPOSE_BINDABLE_MATCHER(CXXBoolLiteralExpr);
        EXPOSE_BINDABLE_MATCHER(CXXCatchStmt);
        EXPOSE_BINDABLE_MATCHER(CXXConstCastExpr);
        EXPOSE_BINDABLE_MATCHER(CXXConstructExpr);
        EXPOSE_BINDABLE_MATCHER(CXXConstructorDecl);
        EXPOSE_BINDABLE_MATCHER(CXXConversionDecl);
        EXPOSE_BINDABLE_MATCHER(CXXDefaultArgExpr);
        EXPOSE_BINDABLE_MATCHER(CXXDeleteExpr);
        EXPOSE_BINDABLE_MATCHER(CXXDependentScopeMemberExpr);
        EXPOSE_BINDABLE_MATCHER(CXXDestructorDecl);
        EXPOSE_BINDABLE_MATCHER(CXXDynamicCastExpr);
        EXPOSE_BINDABLE_MATCHER(CXXForRangeStmt);
        EXPOSE_BINDABLE_MATCHER(CXXFunctionalCastExpr);
        EXPOSE_BINDABLE_MATCHER(CXXMemberCallExpr);
        EXPOSE_BINDABLE_MATCHER(CXXMethodDecl);
        EXPOSE_BINDABLE_MATCHER(CXXNewExpr);
        EXPOSE_BINDABLE_MATCHER(CXXNullPtrLiteralExpr);
        EXPOSE_BINDABLE_MATCHER(CXXOperatorCallExpr);
        EXPOSE_BINDABLE_MATCHER(CXXRecordDecl);
        EXPOSE_BINDABLE_MATCHER(CXXReinterpretCastExpr);
        EXPOSE_BINDABLE_MATCHER(CXXStaticCastExpr);
        EXPOSE_BINDABLE_MATCHER(CXXStdInitializerListExpr);
        EXPOSE_BINDABLE_MATCHER(CXXTemporaryObjectExpr);
        EXPOSE_BINDABLE_MATCHER(CXXThisExpr);
        EXPOSE_BINDABLE_MATCHER(CXXThrowExpr);
        EXPOSE_BINDABLE_MATCHER(CXXTryStmt);
        EXPOSE_BINDABLE_MATCHER(CXXUnresolvedConstructExpr);
        EXPOSE_BINDABLE_MATCHER(DeclaratorDecl);
        EXPOSE_BINDABLE_MATCHER(ClassTemplatePartialSpecializationDecl);
        EXPOSE_BINDABLE_MATCHER(ClassTemplateSpecializationDecl);
        EXPOSE_BINDABLE_MATCHER(DeclRefExpr);
        EXPOSE_BINDABLE_MATCHER(DeclStmt);
        EXPOSE_BINDABLE_MATCHER(DefaultStmt);
        EXPOSE_BINDABLE_MATCHER(DesignatedInitExpr);
        EXPOSE_BINDABLE_MATCHER(DoStmt);
        EXPOSE_BINDABLE_MATCHER(EnumConstantDecl);
        EXPOSE_BINDABLE_MATCHER(EnumDecl);
        EXPOSE_BINDABLE_MATCHER(ExplicitCastExpr);
        EXPOSE_BINDABLE_MATCHER(Expr);
        EXPOSE_BINDABLE_MATCHER(ExprWithCleanups);
        EXPOSE_BINDABLE_MATCHER(FieldDecl);
        EXPOSE_BINDABLE_MATCHER(FloatingLiteral);
        EXPOSE_BINDABLE_MATCHER(ForStmt);
        EXPOSE_BINDABLE_MATCHER(FriendDecl);
        EXPOSE_BINDABLE_MATCHER(FunctionDecl);
        EXPOSE_BINDABLE_MATCHER(FunctionTemplateDecl);
        EXPOSE_BINDABLE_MATCHER(GNUNullExpr);
        EXPOSE_BINDABLE_MATCHER(GotoStmt);
        EXPOSE_BINDABLE_MATCHER(IfStmt);
        EXPOSE_BINDABLE_MATCHER(ImaginaryLiteral);
        EXPOSE_BINDABLE_MATCHER(ImplicitCastExpr);
        EXPOSE_BINDABLE_MATCHER(ImplicitValueInitExpr);
        EXPOSE_BINDABLE_MATCHER(IndirectFieldDecl);
        EXPOSE_BINDABLE_MATCHER(InitListExpr);
        EXPOSE_BINDABLE_MATCHER(IntegerLiteral);
        EXPOSE_BINDABLE_MATCHER(LabelDecl);
        EXPOSE_BINDABLE_MATCHER(LabelStmt);
        EXPOSE_BINDABLE_MATCHER(LambdaExpr);
        EXPOSE_BINDABLE_MATCHER(LinkageSpecDecl);
        EXPOSE_BINDABLE_MATCHER(MaterializeTemporaryExpr);
        EXPOSE_BINDABLE_MATCHER(MemberExpr);
        EXPOSE_BINDABLE_MATCHER(NamedDecl);
        EXPOSE_BINDABLE_MATCHER(NamespaceAliasDecl);
        EXPOSE_BINDABLE_MATCHER(NamespaceDecl);
        EXPOSE_BINDABLE_MATCHER(NonTypeTemplateParmDecl);
        EXPOSE_BINDABLE_MATCHER(NullStmt);
        EXPOSE_BINDABLE_MATCHER(ObjCAtCatchStmt);
        EXPOSE_BINDABLE_MATCHER(ObjCAtFinallyStmt);
        EXPOSE_BINDABLE_MATCHER(ObjCAtThrowStmt);
        EXPOSE_BINDABLE_MATCHER(ObjCAtTryStmt);
        EXPOSE_BINDABLE_MATCHER(ObjCAutoreleasePoolStmt);
        EXPOSE_BINDABLE_MATCHER(ObjCCategoryDecl);
        EXPOSE_BINDABLE_MATCHER(ObjCCategoryImplDecl);
        EXPOSE_BINDABLE_MATCHER(ObjCImplementationDecl);
        EXPOSE_BINDABLE_MATCHER(ObjCInterfaceDecl);
        EXPOSE_BINDABLE_MATCHER(ObjCIvarDecl);
        EXPOSE_BINDABLE_MATCHER(ObjCIvarRefExpr);
        EXPOSE_BINDABLE_MATCHER(ObjCMessageExpr);
        EXPOSE_BINDABLE_MATCHER(ObjCMethodDecl);
        EXPOSE_BINDABLE_MATCHER(ObjCPropertyDecl);
        EXPOSE_BINDABLE_MATCHER(ObjCProtocolDecl);
        EXPOSE_BINDABLE_MATCHER(OpaqueValueExpr);
        EXPOSE_BINDABLE_MATCHER(ParenExpr);
        EXPOSE_BINDABLE_MATCHER(ParenListExpr);
        EXPOSE_BINDABLE_MATCHER(ParmVarDecl);
        EXPOSE_BINDABLE_MATCHER(PredefinedExpr);
        EXPOSE_BINDABLE_MATCHER(RecordDecl);
        EXPOSE_BINDABLE_MATCHER(ReturnStmt);
        EXPOSE_BINDABLE_MATCHER(StaticAssertDecl);
        EXPOSE_BINDABLE_MATCHER(StmtExpr);
        EXPOSE_BINDABLE_MATCHER(StringLiteral);
        EXPOSE_BINDABLE_MATCHER(SubstNonTypeTemplateParmExpr);
        EXPOSE_BINDABLE_MATCHER(SwitchCase);
        EXPOSE_BINDABLE_MATCHER(SwitchStmt);
        EXPOSE_BINDABLE_MATCHER(TemplateTypeParmDecl);
        EXPOSE_BINDABLE_MATCHER(TranslationUnitDecl);
        EXPOSE_BINDABLE_MATCHER(TypeAliasDecl);
        EXPOSE_BINDABLE_MATCHER(TypeAliasTemplateDecl);
        EXPOSE_BINDABLE_MATCHER(TypedefDecl);
        EXPOSE_BINDABLE_MATCHER(TypedefNameDecl);
        EXPOSE_BINDABLE_MATCHER(UnaryExprOrTypeTraitExpr);
        EXPOSE_BINDABLE_MATCHER(UnaryOperator);
        EXPOSE_BINDABLE_MATCHER(UnresolvedLookupExpr);
        EXPOSE_BINDABLE_MATCHER(UnresolvedMemberExpr);
        EXPOSE_BINDABLE_MATCHER(UnresolvedUsingTypenameDecl);
        EXPOSE_BINDABLE_MATCHER(UnresolvedUsingValueDecl);
        EXPOSE_BINDABLE_MATCHER(UserDefinedLiteral);
        EXPOSE_BINDABLE_MATCHER(UsingDecl);
        EXPOSE_BINDABLE_MATCHER(UsingDirectiveDecl);
        EXPOSE_BINDABLE_MATCHER(ValueDecl);
        EXPOSE_BINDABLE_MATCHER(VarDecl);
        EXPOSE_BINDABLE_MATCHER(WhileStmt);

        EXPOSE_BINDABLE_MATCHER(ArrayType);
        EXPOSE_BINDABLE_MATCHER(AtomicType);
        EXPOSE_BINDABLE_MATCHER(AutoType);
        EXPOSE_BINDABLE_MATCHER(BlockPointerType);
        EXPOSE_BINDABLE_MATCHER(BuiltinType);
        EXPOSE_BINDABLE_MATCHER(ComplexType);
        EXPOSE_BINDABLE_MATCHER(ConstantArrayType);
        EXPOSE_BINDABLE_MATCHER(DecayedType);
        EXPOSE_BINDABLE_MATCHER(DecltypeType);
        EXPOSE_BINDABLE_MATCHER(DependentSizedArrayType);
        EXPOSE_BINDABLE_MATCHER(ElaboratedType);
        EXPOSE_BINDABLE_MATCHER(EnumType);
        EXPOSE_BINDABLE_MATCHER(FunctionProtoType);
        EXPOSE_BINDABLE_MATCHER(FunctionType);
        EXPOSE_BINDABLE_MATCHER(IncompleteArrayType);
        EXPOSE_BINDABLE_MATCHER(InjectedClassNameType);
        EXPOSE_BINDABLE_MATCHER(LValueReferenceType);
        EXPOSE_BINDABLE_MATCHER(MemberPointerType);
        EXPOSE_BINDABLE_MATCHER(ObjCObjectPointerType);
        EXPOSE_BINDABLE_MATCHER(ParenType);
        EXPOSE_BINDABLE_MATCHER(PointerType);
        EXPOSE_BINDABLE_MATCHER(RecordType);
        EXPOSE_BINDABLE_MATCHER(ReferenceType);
        EXPOSE_BINDABLE_MATCHER(RValueReferenceType);
        EXPOSE_BINDABLE_MATCHER(SubstTemplateTypeParmType);
        EXPOSE_BINDABLE_MATCHER(TagType);
        EXPOSE_BINDABLE_MATCHER(TemplateSpecializationType);
        EXPOSE_BINDABLE_MATCHER(TemplateTypeParmType);
        EXPOSE_BINDABLE_MATCHER(TypedefType);
        EXPOSE_BINDABLE_MATCHER(UnaryTransformType);
        EXPOSE_BINDABLE_MATCHER(VariableArrayType);

        EXPOSE_BINDABLE_MATCHER(CXXCtorInitializer);
        EXPOSE_BINDABLE_MATCHER(Decl);
        EXPOSE_BINDABLE_MATCHER(NestedNameSpecifierLoc);
        EXPOSE_BINDABLE_MATCHER(NestedNameSpecifier);
        EXPOSE_BINDABLE_MATCHER(QualType);
        EXPOSE_BINDABLE_MATCHER(Stmt);
        EXPOSE_BINDABLE_MATCHER(TemplateArgument);
        EXPOSE_BINDABLE_MATCHER(TemplateName);
        EXPOSE_BINDABLE_MATCHER(TypeLoc);
        EXPOSE_BINDABLE_MATCHER(Type);
        
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


        class_<BoundNodes>("BoundNodes", init<const BoundNodes&>())
            
            .def("getFunctionDecl", 
                +[](BoundNodes &self, const std::string &id)
                {
                    return self.getNodeAs<FunctionDecl>(id);
                }, 
                return_value_policy<reference_existing_object>()
            )
            
            .def("getVarDecl", 
                +[](BoundNodes &self, const std::string &id)
                {
                    return self.getNodeAs<VarDecl>(id);
                }, 
                return_value_policy<reference_existing_object>()
            )
        ;
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



