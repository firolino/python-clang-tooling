#include "wrapper-expose.h"
#include <boost/python.hpp>
#include <clang/ASTMatchers/ASTMatchers.h>

#define STRINGIFY(str) #str

#define EXPOSE_WRAPPER(name) \
{\
    using ExposedType = name;\
    class_<clang::name, boost::noncopyable>(STRINGIFY(name)"Impl", no_init);\
    class_<name>(STRINGIFY(name))\
        .def("__call__",\
            +[](ExposedType &self)\
            {\
                return self.call();\
            }\
        )\
        .def("__call__",\
            +[](ExposedType &self, const clang::ast_matchers::internal::Matcher<clang::name> &arg)\
            {\
                return self.call(arg);\
            }\
        )

#define EXPOSE_WRAPPER_CALL_FUNC(other)\
    .def("__call__",\
        +[](ExposedType &self, const clang::ast_matchers::internal::Matcher<clang::other> &arg)\
        {\
            return self.call(arg);\
        }\
    )

#define EXPOSE_WRAPPER_CALL_FUNC_P2(other1, other2)\
    .def("__call__",\
        +[](ExposedType &self, const clang::ast_matchers::internal::Matcher<clang::other1> &arg1, const clang::ast_matchers::internal::Matcher<clang::other2> &arg2)\
        {\
            return self.call(arg1, arg2);\
        }\
    )

#define END_WRAPPER_EXPOSING()\
;}

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

#define EXPOSE_WRAPPER_VAR(Type, name)\
    Type name;\
    scope().attr(STRINGIFY(name)) = name

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


void expose_wrapper()
{
    using namespace pywrappers;
    using namespace boost::python;

    EXPOSE_WRAPPER(AccessSpecDecl)
        EXPOSE_WRAPPER_CALL_FUNC(Decl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(AddrLabelExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ArraySubscriptExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(AsmStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(AtomicExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(BinaryConditionalOperator)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(BinaryOperator)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(BlockDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(BlockExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(BreakStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CallExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CaseStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CastExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CharacterLiteral)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ClassTemplateDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CompoundLiteralExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CompoundStmt)
        EXPOSE_WRAPPER_CALL_FUNC(Stmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ConditionalOperator)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ConstantExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ContinueStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CStyleCastExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CUDAKernelCallExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXBindTemporaryExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXBoolLiteralExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXCatchStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXConstCastExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXConstructExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXConstructorDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXConversionDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXDefaultArgExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXDeleteExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXDependentScopeMemberExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXDestructorDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXDynamicCastExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXForRangeStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXFunctionalCastExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXMemberCallExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXMethodDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXNewExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXNullPtrLiteralExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXOperatorCallExpr)
            EXPOSE_WRAPPER_CALL_FUNC(CallExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXRecordDecl)
        EXPOSE_WRAPPER_CALL_FUNC(Decl)
        EXPOSE_WRAPPER_CALL_FUNC(NamedDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXReinterpretCastExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXStaticCastExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXStdInitializerListExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXTemporaryObjectExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXThisExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXThrowExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXTryStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(CXXUnresolvedConstructExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(DeclaratorDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ClassTemplatePartialSpecializationDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ClassTemplateSpecializationDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(DeclRefExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(DeclStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(DefaultStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(DesignatedInitExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(DoStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(EnumConstantDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(EnumDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ExplicitCastExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(Expr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ExprWithCleanups)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(FieldDecl)
        EXPOSE_WRAPPER_CALL_FUNC(NamedDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(FloatingLiteral)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ForStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(FriendDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(FunctionDecl)
        EXPOSE_WRAPPER_CALL_FUNC(NamedDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(FunctionTemplateDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(GNUNullExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(GotoStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(IfStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ImaginaryLiteral)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ImplicitCastExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ImplicitValueInitExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(IndirectFieldDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(InitListExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(IntegerLiteral)
        EXPOSE_WRAPPER_CALL_FUNC(Stmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(LabelDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(LabelStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(LambdaExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(LinkageSpecDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(MaterializeTemporaryExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(MemberExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(NamedDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(NamespaceAliasDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(NamespaceDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(NonTypeTemplateParmDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(NullStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCAtCatchStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCAtFinallyStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCAtThrowStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCAtTryStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCAutoreleasePoolStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCCategoryDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCCategoryImplDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCImplementationDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCInterfaceDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCIvarDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCIvarRefExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCMessageExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCMethodDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCPropertyDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCProtocolDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(OpaqueValueExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ParenExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ParenListExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ParmVarDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(PredefinedExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(RecordDecl)
        EXPOSE_WRAPPER_CALL_FUNC(Decl)
        EXPOSE_WRAPPER_CALL_FUNC(NamedDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ReturnStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(StaticAssertDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(StmtExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(StringLiteral)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(SubstNonTypeTemplateParmExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(SwitchCase)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(SwitchStmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TemplateTypeParmDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TranslationUnitDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TypeAliasDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TypeAliasTemplateDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TypedefDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TypedefNameDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(UnaryExprOrTypeTraitExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(UnaryOperator)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(UnresolvedLookupExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(UnresolvedMemberExpr)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(UnresolvedUsingTypenameDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(UnresolvedUsingValueDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(UserDefinedLiteral)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(UsingDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(UsingDirectiveDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ValueDecl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(VarDecl)
        EXPOSE_WRAPPER_CALL_FUNC(NamedDecl)
        EXPOSE_WRAPPER_CALL_FUNC(ValueDecl)
        EXPOSE_WRAPPER_CALL_FUNC_P2(NamedDecl, Decl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(WhileStmt)
    END_WRAPPER_EXPOSING()


    EXPOSE_WRAPPER(ArrayType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(AtomicType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(AutoType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(BlockPointerType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(BuiltinType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ComplexType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ConstantArrayType)
        EXPOSE_WRAPPER_CALL_FUNC(ArrayType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(DecayedType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(DecltypeType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(DependentSizedArrayType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ElaboratedType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(EnumType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(FunctionProtoType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(FunctionType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(IncompleteArrayType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(InjectedClassNameType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(LValueReferenceType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(MemberPointerType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ObjCObjectPointerType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ParenType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(PointerType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(RecordType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(ReferenceType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(RValueReferenceType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(SubstTemplateTypeParmType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TagType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TemplateSpecializationType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TemplateTypeParmType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TypedefType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(UnaryTransformType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(VariableArrayType)
    END_WRAPPER_EXPOSING()


    EXPOSE_WRAPPER(CXXCtorInitializer)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(Decl)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(NestedNameSpecifierLoc)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(NestedNameSpecifier)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(QualType)
        EXPOSE_WRAPPER_CALL_FUNC_P2(QualType, QualType)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(Stmt)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TemplateArgument)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TemplateName)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(TypeLoc)
    END_WRAPPER_EXPOSING()

    EXPOSE_WRAPPER(Type)
    END_WRAPPER_EXPOSING()


    EXPOSE_WRAPPER_VAR(AccessSpecDecl, accessSpecDecl);
    EXPOSE_WRAPPER_VAR(AddrLabelExpr, addrLabelExpr);
    EXPOSE_WRAPPER_VAR(ArraySubscriptExpr, arraySubscriptExpr);
    EXPOSE_WRAPPER_VAR(AsmStmt, asmStmt);
    EXPOSE_WRAPPER_VAR(AtomicExpr, atomicExpr);
    EXPOSE_WRAPPER_VAR(BinaryConditionalOperator, binaryConditionalOperator);
    EXPOSE_WRAPPER_VAR(BinaryOperator, binaryOperator);
    EXPOSE_WRAPPER_VAR(BlockDecl, blockDecl);
    EXPOSE_WRAPPER_VAR(BlockExpr, blockExpr);
    EXPOSE_WRAPPER_VAR(BreakStmt, breakStmt);
    EXPOSE_WRAPPER_VAR(CallExpr, callExpr);
    EXPOSE_WRAPPER_VAR(CaseStmt, caseStmt);
    EXPOSE_WRAPPER_VAR(CastExpr, castExpr);
    EXPOSE_WRAPPER_VAR(CharacterLiteral, characterLiteral);
    EXPOSE_WRAPPER_VAR(ClassTemplateDecl, classTemplateDecl);
    EXPOSE_WRAPPER_VAR(CompoundLiteralExpr, compoundLiteralExpr);
    EXPOSE_WRAPPER_VAR(CompoundStmt, compoundStmt);
    EXPOSE_WRAPPER_VAR(ConditionalOperator, conditionalOperator);
    EXPOSE_WRAPPER_VAR(ConstantExpr, constantExpr);
    EXPOSE_WRAPPER_VAR(ContinueStmt, continueStmt);
    EXPOSE_WRAPPER_VAR(CStyleCastExpr, cStyleCastExpr);
    EXPOSE_WRAPPER_VAR(CUDAKernelCallExpr, cudaKernelCallExpr);
    EXPOSE_WRAPPER_VAR(CXXBindTemporaryExpr, cxxBindTemporaryExpr);
    EXPOSE_WRAPPER_VAR(CXXBoolLiteralExpr, cxxBoolLiteral);
    EXPOSE_WRAPPER_VAR(CXXCatchStmt, cxxCatchStmt);
    EXPOSE_WRAPPER_VAR(CXXConstCastExpr, cxxConstCastExpr);
    EXPOSE_WRAPPER_VAR(CXXConstructExpr, cxxConstructExpr);
    EXPOSE_WRAPPER_VAR(CXXConstructorDecl, cxxConstructorDecl);
    EXPOSE_WRAPPER_VAR(CXXConversionDecl, cxxConversionDecl);
    EXPOSE_WRAPPER_VAR(CXXDefaultArgExpr, cxxDefaultArgExpr);
    EXPOSE_WRAPPER_VAR(CXXDeleteExpr, cxxDeleteExpr);
    EXPOSE_WRAPPER_VAR(CXXDependentScopeMemberExpr, cxxDependentScopeMemberExpr);
    EXPOSE_WRAPPER_VAR(CXXDestructorDecl, cxxDestructorDecl);
    EXPOSE_WRAPPER_VAR(CXXDynamicCastExpr, cxxDynamicCastExpr);
    EXPOSE_WRAPPER_VAR(CXXForRangeStmt, cxxForRangeStmt);
    EXPOSE_WRAPPER_VAR(CXXFunctionalCastExpr, cxxFunctionalCastExpr);
    EXPOSE_WRAPPER_VAR(CXXMemberCallExpr, cxxMemberCallExpr);
    EXPOSE_WRAPPER_VAR(CXXMethodDecl, cxxMethodDecl);
    EXPOSE_WRAPPER_VAR(CXXNewExpr, cxxNewExpr);
    EXPOSE_WRAPPER_VAR(CXXNullPtrLiteralExpr, cxxNullPtrLiteralExpr);
    EXPOSE_WRAPPER_VAR(CXXOperatorCallExpr, cxxOperatorCallExpr);
    EXPOSE_WRAPPER_VAR(CXXRecordDecl, cxxRecordDecl);
    EXPOSE_WRAPPER_VAR(CXXReinterpretCastExpr, cxxReinterpretCastExpr);
    EXPOSE_WRAPPER_VAR(CXXStaticCastExpr, cxxStaticCastExpr);
    EXPOSE_WRAPPER_VAR(CXXStdInitializerListExpr, cxxStdInitializerListExpr);
    EXPOSE_WRAPPER_VAR(CXXTemporaryObjectExpr, cxxTemporaryObjectExpr);
    EXPOSE_WRAPPER_VAR(CXXThisExpr, cxxThisExpr);
    EXPOSE_WRAPPER_VAR(CXXThrowExpr, cxxThrowExpr);
    EXPOSE_WRAPPER_VAR(CXXTryStmt, cxxTryStmt);
    EXPOSE_WRAPPER_VAR(CXXUnresolvedConstructExpr, cxxUnresolvedConstructExpr);
    EXPOSE_WRAPPER_VAR(DeclaratorDecl, declaratorDecl);
    EXPOSE_WRAPPER_VAR(ClassTemplatePartialSpecializationDecl, classTemplatePartialSpecializationDecl);
    EXPOSE_WRAPPER_VAR(ClassTemplateSpecializationDecl, classTemplateSpecializationDecl);
    EXPOSE_WRAPPER_VAR(DeclRefExpr, declRefExpr);
    EXPOSE_WRAPPER_VAR(DeclStmt, declStmt);
    EXPOSE_WRAPPER_VAR(DefaultStmt, defaultStmt);
    EXPOSE_WRAPPER_VAR(DesignatedInitExpr, designatedInitExpr);
    EXPOSE_WRAPPER_VAR(DoStmt, doStmt);
    EXPOSE_WRAPPER_VAR(EnumConstantDecl, enumConstantDecl);
    EXPOSE_WRAPPER_VAR(EnumDecl, enumDecl);
    EXPOSE_WRAPPER_VAR(ExplicitCastExpr, explicitCastExpr);
    EXPOSE_WRAPPER_VAR(Expr, expr);
    EXPOSE_WRAPPER_VAR(ExprWithCleanups, exprWithCleanups);
    EXPOSE_WRAPPER_VAR(FieldDecl, fieldDecl);
    EXPOSE_WRAPPER_VAR(FloatingLiteral, floatLiteral);
    EXPOSE_WRAPPER_VAR(ForStmt, forStmt);
    EXPOSE_WRAPPER_VAR(FriendDecl, friendDecl);
    EXPOSE_WRAPPER_VAR(FunctionDecl, functionDecl);
    EXPOSE_WRAPPER_VAR(FunctionTemplateDecl, functionTemplateDecl);
    EXPOSE_WRAPPER_VAR(GNUNullExpr, gnuNullExpr);
    EXPOSE_WRAPPER_VAR(GotoStmt, gotoStmt);
    EXPOSE_WRAPPER_VAR(IfStmt, ifStmt);
    EXPOSE_WRAPPER_VAR(ImaginaryLiteral, imaginaryLiteral);
    EXPOSE_WRAPPER_VAR(ImplicitCastExpr, implicitCastExpr);
    EXPOSE_WRAPPER_VAR(ImplicitValueInitExpr, implicitValueInitExpr);
    EXPOSE_WRAPPER_VAR(IndirectFieldDecl, indirectFieldDecl);
    EXPOSE_WRAPPER_VAR(InitListExpr, initListExpr);
    EXPOSE_WRAPPER_VAR(IntegerLiteral, integerLiteral);
    EXPOSE_WRAPPER_VAR(LabelDecl, labelDecl);
    EXPOSE_WRAPPER_VAR(LabelStmt, labelStmt);
    EXPOSE_WRAPPER_VAR(LambdaExpr, lambdaExpr);
    EXPOSE_WRAPPER_VAR(LinkageSpecDecl, linkageSpecDecl);
    EXPOSE_WRAPPER_VAR(MaterializeTemporaryExpr, materializeTemporaryExpr);
    EXPOSE_WRAPPER_VAR(MemberExpr, memberExpr);
    EXPOSE_WRAPPER_VAR(NamedDecl, namedDecl);
    EXPOSE_WRAPPER_VAR(NamespaceAliasDecl, namespaceAliasDecl);
    EXPOSE_WRAPPER_VAR(NamespaceDecl, namespaceDecl);
    EXPOSE_WRAPPER_VAR(NonTypeTemplateParmDecl, nonTypeTemplateParmDecl);
    EXPOSE_WRAPPER_VAR(NullStmt, nullStmt);
    EXPOSE_WRAPPER_VAR(ObjCAtCatchStmt, objcCatchStmt);
    EXPOSE_WRAPPER_VAR(ObjCAtFinallyStmt, objcFinallyStmt);
    EXPOSE_WRAPPER_VAR(ObjCAtThrowStmt, objcThrowStmt);
    EXPOSE_WRAPPER_VAR(ObjCAtTryStmt, objcTryStmt);
    EXPOSE_WRAPPER_VAR(ObjCAutoreleasePoolStmt, autoreleasePoolStmt);
    EXPOSE_WRAPPER_VAR(ObjCCategoryDecl, objcCategoryDecl);
    EXPOSE_WRAPPER_VAR(ObjCCategoryImplDecl, objcCategoryImplDecl);
    EXPOSE_WRAPPER_VAR(ObjCImplementationDecl, objcImplementationDecl);
    EXPOSE_WRAPPER_VAR(ObjCInterfaceDecl, objcInterfaceDecl);
    EXPOSE_WRAPPER_VAR(ObjCIvarDecl, objcIvarDecl);
    EXPOSE_WRAPPER_VAR(ObjCIvarRefExpr, objcIvarRefExpr);
    EXPOSE_WRAPPER_VAR(ObjCMessageExpr, objcMessageExpr);
    EXPOSE_WRAPPER_VAR(ObjCMethodDecl, objcMethodDecl);
    EXPOSE_WRAPPER_VAR(ObjCPropertyDecl, objcPropertyDecl);
    EXPOSE_WRAPPER_VAR(ObjCProtocolDecl, objcProtocolDecl);
    EXPOSE_WRAPPER_VAR(OpaqueValueExpr, opaqueValueExpr);
    EXPOSE_WRAPPER_VAR(ParenExpr, parenExpr);
    EXPOSE_WRAPPER_VAR(ParenListExpr, parenListExpr);
    EXPOSE_WRAPPER_VAR(ParmVarDecl, parmVarDecl);
    EXPOSE_WRAPPER_VAR(PredefinedExpr, predefinedExpr);
    EXPOSE_WRAPPER_VAR(RecordDecl, recordDecl);
    EXPOSE_WRAPPER_VAR(ReturnStmt, returnStmt);
    EXPOSE_WRAPPER_VAR(StaticAssertDecl, staticAssertDecl);
    EXPOSE_WRAPPER_VAR(StmtExpr, stmtExpr);
    EXPOSE_WRAPPER_VAR(StringLiteral, stringLiteral);
    EXPOSE_WRAPPER_VAR(SubstNonTypeTemplateParmExpr, substNonTypeTemplateParmExpr);
    EXPOSE_WRAPPER_VAR(SwitchCase, switchCase);
    EXPOSE_WRAPPER_VAR(SwitchStmt, switchStmt);
    EXPOSE_WRAPPER_VAR(TemplateTypeParmDecl, templateTypeParmDecl);
    EXPOSE_WRAPPER_VAR(TranslationUnitDecl, translationUnitDecl);
    EXPOSE_WRAPPER_VAR(TypeAliasDecl, typeAliasDecl);
    EXPOSE_WRAPPER_VAR(TypeAliasTemplateDecl, typeAliasTemplateDecl);
    EXPOSE_WRAPPER_VAR(TypedefDecl, typedefDecl);
    EXPOSE_WRAPPER_VAR(TypedefNameDecl, typedefNameDecl);
    EXPOSE_WRAPPER_VAR(UnaryExprOrTypeTraitExpr, unaryExprOrTypeTraitExpr);
    EXPOSE_WRAPPER_VAR(UnaryOperator, unaryOperator);
    EXPOSE_WRAPPER_VAR(UnresolvedLookupExpr, unresolvedLookupExpr);
    EXPOSE_WRAPPER_VAR(UnresolvedMemberExpr, unresolvedMemberExpr);
    EXPOSE_WRAPPER_VAR(UnresolvedUsingTypenameDecl, unresolvedUsingTypenameDecl);
    EXPOSE_WRAPPER_VAR(UnresolvedUsingValueDecl, unresolvedUsingValueDecl);
    EXPOSE_WRAPPER_VAR(UserDefinedLiteral, userDefinedLiteral);
    EXPOSE_WRAPPER_VAR(UsingDecl, usingDecl);
    EXPOSE_WRAPPER_VAR(UsingDirectiveDecl, usingDirectiveDecl);
    EXPOSE_WRAPPER_VAR(ValueDecl, valueDecl);
    EXPOSE_WRAPPER_VAR(VarDecl, varDecl);
    EXPOSE_WRAPPER_VAR(WhileStmt, whileStmt);

    EXPOSE_WRAPPER_VAR(ArrayType, arrayType);
    EXPOSE_WRAPPER_VAR(AtomicType, atomicType);
    EXPOSE_WRAPPER_VAR(AutoType, autoType);
    EXPOSE_WRAPPER_VAR(BlockPointerType, blockPointerType);
    EXPOSE_WRAPPER_VAR(BuiltinType, builtinType);
    EXPOSE_WRAPPER_VAR(ComplexType, complexType);
    EXPOSE_WRAPPER_VAR(ConstantArrayType, constantArrayType);
    EXPOSE_WRAPPER_VAR(DecayedType, decayedType);
    EXPOSE_WRAPPER_VAR(DecltypeType, decltypeType);
    EXPOSE_WRAPPER_VAR(DependentSizedArrayType, dependentSizedArrayType);
    EXPOSE_WRAPPER_VAR(ElaboratedType, elaboratedType);
    EXPOSE_WRAPPER_VAR(EnumType, enumType);
    EXPOSE_WRAPPER_VAR(FunctionProtoType, functionProtoType);
    EXPOSE_WRAPPER_VAR(FunctionType, functionType);
    EXPOSE_WRAPPER_VAR(IncompleteArrayType, incompleteArrayType);
    EXPOSE_WRAPPER_VAR(InjectedClassNameType, injectedClassNameType);
    EXPOSE_WRAPPER_VAR(LValueReferenceType, lValueReferenceType);
    EXPOSE_WRAPPER_VAR(MemberPointerType, memberPointerType);
    EXPOSE_WRAPPER_VAR(ObjCObjectPointerType, objcObjectPointerType);
    EXPOSE_WRAPPER_VAR(ParenType, parenType);
    EXPOSE_WRAPPER_VAR(PointerType, pointerType);
    EXPOSE_WRAPPER_VAR(RecordType, recordType);
    EXPOSE_WRAPPER_VAR(ReferenceType, referenceType);
    EXPOSE_WRAPPER_VAR(RValueReferenceType, rValueReferenceType);
    EXPOSE_WRAPPER_VAR(SubstTemplateTypeParmType, substTemplateTypeParmType);
    EXPOSE_WRAPPER_VAR(TagType, tagType);
    EXPOSE_WRAPPER_VAR(TemplateSpecializationType, templateSpecializationType);
    EXPOSE_WRAPPER_VAR(TemplateTypeParmType, templateTypeParmType);
    EXPOSE_WRAPPER_VAR(TypedefType, typedefType);
    EXPOSE_WRAPPER_VAR(UnaryTransformType, unaryTransformType);
    EXPOSE_WRAPPER_VAR(VariableArrayType, variableArrayType);

    EXPOSE_WRAPPER_VAR(CXXCtorInitializer, cxxCtorInitializer);
    EXPOSE_WRAPPER_VAR(Decl, decl);
    EXPOSE_WRAPPER_VAR(NestedNameSpecifierLoc, nestedNameSpecifierLoc);
    EXPOSE_WRAPPER_VAR(NestedNameSpecifier, nestedNameSpecifier);
    EXPOSE_WRAPPER_VAR(QualType, qualType);
    EXPOSE_WRAPPER_VAR(Stmt, stmt);
    EXPOSE_WRAPPER_VAR(TemplateArgument, templateArgument);
    EXPOSE_WRAPPER_VAR(TemplateName, templateName);
    EXPOSE_WRAPPER_VAR(TypeLoc, typeLoc);
    EXPOSE_WRAPPER_VAR(Type, type);
}