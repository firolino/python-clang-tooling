# python-clang-tooling

```python
from libtooling import *

def fn_finder_cb(nodes):
    if nodes.getFunctionDecl("0"):
        print("print function found")

def int_finder_cb(nodes):
    if nodes.getVarDecl("int"):
        print("integer found")

fn_finder1 = functionDecl(hasName("print")).bind("0")
int_finder = varDecl(hasType(isInteger())).bind("int")

tooling = Tooling("../tests/simple.cc")

tooling.add(fn_finder1, fn_finder_cb)
tooling.add(int_finder, int_finder_cb)

tooling.run()
```

# Node Matchers

Return Type | Name | Parameters | Implemented
------------ | ------------- | ------------- | -------------
Matcher<CXXCtorInitializer> | cxxCtorInitializer | Matcher<CXXCtorInitializer>| :heavy_check_mark:
Matcher<Decl> | accessSpecDecl | Matcher<AccessSpecDecl>| :heavy_check_mark:
Matcher<Decl> | blockDecl | Matcher<BlockDecl>| :heavy_check_mark:
Matcher<Decl> | classTemplateDecl | Matcher<ClassTemplateDecl>| :heavy_check_mark:
Matcher<Decl> | classTemplatePartialSpecializationDecl | Matcher<ClassTemplatePartialSpecializationDecl>| :heavy_check_mark:
Matcher<Decl> | classTemplateSpecializationDecl | Matcher<ClassTemplateSpecializationDecl>| :heavy_check_mark:
Matcher<Decl> | cxxConstructorDecl | Matcher<CXXConstructorDecl>| :heavy_check_mark:
Matcher<Decl> | cxxConversionDecl | Matcher<CXXConversionDecl>| :heavy_check_mark:
Matcher<Decl> | cxxDestructorDecl | Matcher<CXXDestructorDecl>| :heavy_check_mark:
Matcher<Decl> | cxxMethodDecl | Matcher<CXXMethodDecl>| :heavy_check_mark:
Matcher<Decl> | cxxRecordDecl | Matcher<CXXRecordDecl>| :heavy_check_mark:
Matcher<Decl> | decl | Matcher<Decl>| :heavy_check_mark:
Matcher<Decl> | declaratorDecl | Matcher<DeclaratorDecl>| :heavy_check_mark:
Matcher<Decl> | enumConstantDecl | Matcher<EnumConstantDecl>| :heavy_check_mark:
Matcher<Decl> | enumDecl | Matcher<EnumDecl>| :heavy_check_mark:
Matcher<Decl> | fieldDecl | Matcher<FieldDecl>| :heavy_check_mark:
Matcher<Decl> | friendDecl | Matcher<FriendDecl>| :heavy_check_mark:
Matcher<Decl> | functionDecl | Matcher<FunctionDecl>| :heavy_check_mark:
Matcher<Decl> | functionTemplateDecl | Matcher<FunctionTemplateDecl>| :heavy_check_mark:
Matcher<Decl> | indirectFieldDecl | Matcher<IndirectFieldDecl>| :heavy_check_mark:
Matcher<Decl> | labelDecl | Matcher<LabelDecl>| :heavy_check_mark:
Matcher<Decl> | linkageSpecDecl | Matcher<LinkageSpecDecl>| :heavy_check_mark:
Matcher<Decl> | namedDecl | Matcher<NamedDecl>| :heavy_check_mark:
Matcher<Decl> | namespaceAliasDecl | Matcher<NamespaceAliasDecl>| :heavy_check_mark:
Matcher<Decl> | namespaceDecl | Matcher<NamespaceDecl>| :heavy_check_mark:
Matcher<Decl> | nonTypeTemplateParmDecl | Matcher<NonTypeTemplateParmDecl>| :heavy_check_mark:
Matcher<Decl> | objcCategoryDecl | Matcher<ObjCCategoryDecl>| :heavy_check_mark:
Matcher<Decl> | objcCategoryImplDecl | Matcher<ObjCCategoryImplDecl>| :heavy_check_mark:
Matcher<Decl> | objcImplementationDecl | Matcher<ObjCImplementationDecl>| :heavy_check_mark:
Matcher<Decl> | objcInterfaceDecl | Matcher<ObjCInterfaceDecl>| :heavy_check_mark:
Matcher<Decl> | objcIvarDecl | Matcher<ObjCIvarDecl>| :heavy_check_mark:
Matcher<Decl> | objcMethodDecl | Matcher<ObjCMethodDecl>| :heavy_check_mark:
Matcher<Decl> | objcPropertyDecl | Matcher<ObjCPropertyDecl>| :heavy_check_mark:
Matcher<Decl> | objcProtocolDecl | Matcher<ObjCProtocolDecl>| :heavy_check_mark:
Matcher<Decl> | parmVarDecl | Matcher<ParmVarDecl>| :heavy_check_mark:
Matcher<Decl> | recordDecl | Matcher<RecordDecl>| :heavy_check_mark:
Matcher<Decl> | staticAssertDecl | Matcher<StaticAssertDecl>| :heavy_check_mark:
Matcher<Decl> | templateTypeParmDecl | Matcher<TemplateTypeParmDecl>| :heavy_check_mark:
Matcher<Decl> | translationUnitDecl | Matcher<TranslationUnitDecl>| :heavy_check_mark:
Matcher<Decl> | typeAliasDecl | Matcher<TypeAliasDecl>| :heavy_check_mark:
Matcher<Decl> | typeAliasTemplateDecl | Matcher<TypeAliasTemplateDecl>| :heavy_check_mark:
Matcher<Decl> | typedefDecl | Matcher<TypedefDecl>| :heavy_check_mark:
Matcher<Decl> | typedefNameDecl | Matcher<TypedefNameDecl>| :heavy_check_mark:
Matcher<Decl> | unresolvedUsingTypenameDecl | Matcher<UnresolvedUsingTypenameDecl>| :heavy_check_mark:
Matcher<Decl> | unresolvedUsingValueDecl | Matcher<UnresolvedUsingValueDecl>| :heavy_check_mark:
Matcher<Decl> | usingDecl | Matcher<UsingDecl>| :heavy_check_mark:
Matcher<Decl> | usingDirectiveDecl | Matcher<UsingDirectiveDecl>| :heavy_check_mark:
Matcher<Decl> | valueDecl | Matcher<ValueDecl>| :heavy_check_mark:
Matcher<Decl> | varDecl | Matcher<VarDecl>| :heavy_check_mark:
Matcher<NestedNameSpecifierLoc> | nestedNameSpecifierLoc | Matcher<NestedNameSpecifierLoc>| :heavy_check_mark:
Matcher<NestedNameSpecifier> | nestedNameSpecifier | Matcher<NestedNameSpecifier>| :heavy_check_mark:
Matcher<OMPClause> | ompDefaultClause | Matcher<OMPDefaultClause>| :heavy_check_mark:
Matcher<QualType> | qualType | Matcher<QualType>| :heavy_check_mark:
Matcher<Stmt> | addrLabelExpr | Matcher<AddrLabelExpr>| :heavy_check_mark:
Matcher<Stmt> | arraySubscriptExpr | Matcher<ArraySubscriptExpr>| :heavy_check_mark:
Matcher<Stmt> | asmStmt | Matcher<AsmStmt>| :heavy_check_mark:
Matcher<Stmt> | atomicExpr | Matcher<AtomicExpr>| :heavy_check_mark:
Matcher<Stmt> | autoreleasePoolStmt | Matcher<ObjCAutoreleasePoolStmt>| :heavy_check_mark:
Matcher<Stmt> | binaryConditionalOperator | Matcher<BinaryConditionalOperator>| :heavy_check_mark:
Matcher<Stmt> | binaryOperator | Matcher<BinaryOperator>| :heavy_check_mark:
Matcher<Stmt> | blockExpr | Matcher<BlockExpr>| :heavy_check_mark:
Matcher<Stmt> | breakStmt | Matcher<BreakStmt>| :heavy_check_mark:
Matcher<Stmt> | cStyleCastExpr | Matcher<CStyleCastExpr>| :heavy_check_mark:
Matcher<Stmt> | callExpr | Matcher<CallExpr>| :heavy_check_mark:
Matcher<Stmt> | caseStmt | Matcher<CaseStmt>| :heavy_check_mark:
Matcher<Stmt> | castExpr | Matcher<CastExpr>| :heavy_check_mark:
Matcher<Stmt> | characterLiteral | Matcher<CharacterLiteral>| :heavy_check_mark:
Matcher<Stmt> | chooseExpr | Matcher<ChooseExpr>| :heavy_check_mark:
Matcher<Stmt> | compoundLiteralExpr | Matcher<CompoundLiteralExpr>| :heavy_check_mark:
Matcher<Stmt> | compoundStmt | Matcher<CompoundStmt>| :heavy_check_mark:
Matcher<Stmt> | conditionalOperator | Matcher<ConditionalOperator>| :heavy_check_mark:
Matcher<Stmt> | constantExpr | Matcher<ConstantExpr>| :heavy_check_mark:
Matcher<Stmt> | continueStmt | Matcher<ContinueStmt>| :heavy_check_mark:
Matcher<Stmt> | cudaKernelCallExpr | Matcher<CUDAKernelCallExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxBindTemporaryExpr | Matcher<CXXBindTemporaryExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxBoolLiteral | Matcher<CXXBoolLiteralExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxCatchStmt | Matcher<CXXCatchStmt>| :heavy_check_mark:
Matcher<Stmt> | cxxConstCastExpr | Matcher<CXXConstCastExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxConstructExpr | Matcher<CXXConstructExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxDefaultArgExpr | Matcher<CXXDefaultArgExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxDeleteExpr | Matcher<CXXDeleteExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxDependentScopeMemberExpr | Matcher<CXXDependentScopeMemberExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxDynamicCastExpr | Matcher<CXXDynamicCastExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxForRangeStmt | Matcher<CXXForRangeStmt>| :heavy_check_mark:
Matcher<Stmt> | cxxFunctionalCastExpr | Matcher<CXXFunctionalCastExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxMemberCallExpr | Matcher<CXXMemberCallExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxNewExpr | Matcher<CXXNewExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxNullPtrLiteralExpr | Matcher<CXXNullPtrLiteralExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxOperatorCallExpr | Matcher<CXXOperatorCallExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxReinterpretCastExpr | Matcher<CXXReinterpretCastExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxStaticCastExpr | Matcher<CXXStaticCastExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxStdInitializerListExpr | Matcher<CXXStdInitializerListExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxTemporaryObjectExpr | Matcher<CXXTemporaryObjectExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxThisExpr | Matcher<CXXThisExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxThrowExpr | Matcher<CXXThrowExpr>| :heavy_check_mark:
Matcher<Stmt> | cxxTryStmt | Matcher<CXXTryStmt>| :heavy_check_mark:
Matcher<Stmt> | cxxUnresolvedConstructExpr | Matcher<CXXUnresolvedConstructExpr>| :heavy_check_mark:
Matcher<Stmt> | declRefExpr | Matcher<DeclRefExpr>| :heavy_check_mark:
Matcher<Stmt> | declStmt | Matcher<DeclStmt>| :heavy_check_mark:
Matcher<Stmt> | defaultStmt | Matcher<DefaultStmt>| :heavy_check_mark:
Matcher<Stmt> | designatedInitExpr | Matcher<DesignatedInitExpr>| :heavy_check_mark:
Matcher<Stmt> | doStmt | Matcher<DoStmt>| :heavy_check_mark:
Matcher<Stmt> | explicitCastExpr | Matcher<ExplicitCastExpr>| :heavy_check_mark:
Matcher<Stmt> | expr | Matcher<Expr>| :heavy_check_mark:
Matcher<Stmt> | exprWithCleanups | Matcher<ExprWithCleanups>| :heavy_check_mark:
Matcher<Stmt> | floatLiteral | Matcher<FloatingLiteral>| :heavy_check_mark:
Matcher<Stmt> | forStmt | Matcher<ForStmt>| :heavy_check_mark:
Matcher<Stmt> | gnuNullExpr | Matcher<GNUNullExpr>| :heavy_check_mark:
Matcher<Stmt> | gotoStmt | Matcher<GotoStmt>| :heavy_check_mark:
Matcher<Stmt> | ifStmt | Matcher<IfStmt>| :heavy_check_mark:
Matcher<Stmt> | imaginaryLiteral | Matcher<ImaginaryLiteral>| :heavy_check_mark:
Matcher<Stmt> | implicitCastExpr | Matcher<ImplicitCastExpr>| :heavy_check_mark:
Matcher<Stmt> | implicitValueInitExpr | Matcher<ImplicitValueInitExpr>| :heavy_check_mark:
Matcher<Stmt> | initListExpr | Matcher<InitListExpr>| :heavy_check_mark:
Matcher<Stmt> | integerLiteral | Matcher<IntegerLiteral>| :heavy_check_mark:
Matcher<Stmt> | labelStmt | Matcher<LabelStmt>| :heavy_check_mark:
Matcher<Stmt> | lambdaExpr | Matcher<LambdaExpr>| :heavy_check_mark:
Matcher<Stmt> | materializeTemporaryExpr | Matcher<MaterializeTemporaryExpr>| :heavy_check_mark:
Matcher<Stmt> | memberExpr | Matcher<MemberExpr>| :heavy_check_mark:
Matcher<Stmt> | nullStmt | Matcher<NullStmt>| :heavy_check_mark:
Matcher<Stmt> | objcCatchStmt | Matcher<ObjCAtCatchStmt>| :heavy_check_mark:
Matcher<Stmt> | objcFinallyStmt | Matcher<ObjCAtFinallyStmt>| :heavy_check_mark:
Matcher<Stmt> | objcIvarRefExpr | Matcher<ObjCIvarRefExpr>| :heavy_check_mark:
Matcher<Stmt> | objcMessageExpr | Matcher<ObjCMessageExpr>| :heavy_check_mark:
Matcher<Stmt> | objcThrowStmt | Matcher<ObjCAtThrowStmt>| :heavy_check_mark:
Matcher<Stmt> | objcTryStmt | Matcher<ObjCAtTryStmt>| :heavy_check_mark:
Matcher<Stmt> | ompExecutableDirective | Matcher<OMPExecutableDirective>| :heavy_check_mark:
Matcher<Stmt> | opaqueValueExpr | Matcher<OpaqueValueExpr>| :heavy_check_mark:
Matcher<Stmt> | parenExpr | Matcher<ParenExpr>| :heavy_check_mark:
Matcher<Stmt> | parenListExpr | Matcher<ParenListExpr>| :heavy_check_mark:
Matcher<Stmt> | predefinedExpr | Matcher<PredefinedExpr>| :heavy_check_mark:
Matcher<Stmt> | returnStmt | Matcher<ReturnStmt>| :heavy_check_mark:
Matcher<Stmt> | stmt | Matcher<Stmt>| :heavy_check_mark:
Matcher<Stmt> | stmtExpr | Matcher<StmtExpr>| :heavy_check_mark:
Matcher<Stmt> | stringLiteral | Matcher<StringLiteral>| :heavy_check_mark:
Matcher<Stmt> | substNonTypeTemplateParmExpr | Matcher<SubstNonTypeTemplateParmExpr>| :heavy_check_mark:
Matcher<Stmt> | switchCase | Matcher<SwitchCase>| :heavy_check_mark:
Matcher<Stmt> | switchStmt | Matcher<SwitchStmt>| :heavy_check_mark:
Matcher<Stmt> | unaryExprOrTypeTraitExpr | Matcher<UnaryExprOrTypeTraitExpr>| :heavy_check_mark:
Matcher<Stmt> | unaryOperator | Matcher<UnaryOperator>| :heavy_check_mark:
Matcher<Stmt> | unresolvedLookupExpr | Matcher<UnresolvedLookupExpr>| :heavy_check_mark:
Matcher<Stmt> | unresolvedMemberExpr | Matcher<UnresolvedMemberExpr>| :heavy_check_mark:
Matcher<Stmt> | userDefinedLiteral | Matcher<UserDefinedLiteral>| :heavy_check_mark:
Matcher<Stmt> | whileStmt | Matcher<WhileStmt>| :heavy_check_mark:
Matcher<TemplateArgument> | templateArgument | Matcher<TemplateArgument>| :heavy_check_mark:
Matcher<TemplateName> | templateName | Matcher<TemplateName>| :heavy_check_mark:
Matcher<TypeLoc> | typeLoc | Matcher<TypeLoc>| :heavy_check_mark:
Matcher<Type> | arrayType | Matcher<ArrayType>| :heavy_check_mark:
Matcher<Type> | atomicType | Matcher<AtomicType>| :heavy_check_mark:
Matcher<Type> | autoType | Matcher<AutoType>| :heavy_check_mark:
Matcher<Type> | blockPointerType | Matcher<BlockPointerType>| :heavy_check_mark:
Matcher<Type> | builtinType | Matcher<BuiltinType>| :heavy_check_mark:
Matcher<Type> | complexType | Matcher<ComplexType>| :heavy_check_mark:
Matcher<Type> | constantArrayType | Matcher<ConstantArrayType>| :heavy_check_mark:
Matcher<Type> | decayedType | Matcher<DecayedType>| :heavy_check_mark:
Matcher<Type> | decltypeType | Matcher<DecltypeType>| :heavy_check_mark:
Matcher<Type> | dependentSizedArrayType | Matcher<DependentSizedArrayType>| :heavy_check_mark:
Matcher<Type> | elaboratedType | Matcher<ElaboratedType>| :heavy_check_mark:
Matcher<Type> | enumType | Matcher<EnumType>| :heavy_check_mark:
Matcher<Type> | functionProtoType | Matcher<FunctionProtoType>| :heavy_check_mark:
Matcher<Type> | functionType | Matcher<FunctionType>| :heavy_check_mark:
Matcher<Type> | incompleteArrayType | Matcher<IncompleteArrayType>| :heavy_check_mark:
Matcher<Type> | injectedClassNameType | Matcher<InjectedClassNameType>| :heavy_check_mark:
Matcher<Type> | lValueReferenceType | Matcher<LValueReferenceType>| :heavy_check_mark:
Matcher<Type> | memberPointerType | Matcher<MemberPointerType>| :heavy_check_mark:
Matcher<Type> | objcObjectPointerType | Matcher<ObjCObjectPointerType>| :heavy_check_mark:
Matcher<Type> | parenType | Matcher<ParenType>| :heavy_check_mark:
Matcher<Type> | pointerType | Matcher<PointerType>| :heavy_check_mark:
Matcher<Type> | rValueReferenceType | Matcher<RValueReferenceType>| :heavy_check_mark:
Matcher<Type> | recordType | Matcher<RecordType>| :heavy_check_mark:
Matcher<Type> | referenceType | Matcher<ReferenceType>| :heavy_check_mark:
Matcher<Type> | substTemplateTypeParmType | Matcher<SubstTemplateTypeParmType>| :heavy_check_mark:
Matcher<Type> | tagType | Matcher<TagType>| :heavy_check_mark:
Matcher<Type> | templateSpecializationType | Matcher<TemplateSpecializationType>| :heavy_check_mark:
Matcher<Type> | templateTypeParmType | Matcher<TemplateTypeParmType>| :heavy_check_mark:
Matcher<Type> | type | Matcher<Type>| :heavy_check_mark:
Matcher<Type> | typedefType | Matcher<TypedefType>| :heavy_check_mark:
Matcher<Type> | unaryTransformType | Matcher<UnaryTransformType>| :heavy_check_mark:
Matcher<Type> | variableArrayType | Matcher<VariableArrayType>| :heavy_check_mark:
