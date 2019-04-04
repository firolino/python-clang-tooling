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

Matcher\<T\><br/>Return Type | Name | Matcher\<T\><br/>Parameters | Implemented
------------ | ------------- | ------------- | --------
CXXCtorInitializer | cxxCtorInitializer | CXXCtorInitializer | 
Decl | accessSpecDecl | AccessSpecDecl | 
Decl | blockDecl | BlockDecl | 
Decl | classTemplateDecl | ClassTemplateDecl | 
Decl | classTempleParalSpelizionDecl | classTempleParalSpelizionDecl | 
Decl | classTempleSpelizionDecl | classTempleSpelizionDecl | 
Decl | cxxConstructorDecl | CXXConstructorDecl | 
Decl | cxxConversionDecl | CXXConversionDecl | 
Decl | cxxDestructorDecl | CXXDestructorDecl | 
Decl | cxxMethodDecl | CXXMethodDecl | :heavy_check_mark:
Decl | cxxRecordDecl | CXXRecordDecl | 
Decl | decl | Decl | :heavy_check_mark:
Decl | declaratorDecl | DeclaratorDecl | 
Decl | enumConstantDecl | EnumConstantDecl | 
Decl | enumDecl | EnumDecl | 
Decl | fieldDecl | FieldDecl | 
Decl | friendDecl | FriendDecl | 
Decl | functionDecl | FunctionDecl | :heavy_check_mark:
Decl | functionTemplateDecl | FunctionTemplateDecl | 
Decl | indirectFieldDecl | IndirectFieldDecl | 
Decl | labelDecl | LabelDecl | 
Decl | linkageSpecDecl | LinkageSpecDecl | 
Decl | namedDecl | NamedDecl | :heavy_check_mark:
Decl | namespaceAliasDecl | NamespaceAliasDecl | 
Decl | namespaceDecl | NamespaceDecl | 
Decl | nonTypeTemplateParmDecl | NonTypeTemplateParmDecl | 
Decl | objcCategoryDecl | ObjCCategoryDecl | 
Decl | objcCategoryImplDecl | ObjCCategoryImplDecl | 
Decl | objcImplementationDecl | ObjCImplementationDecl | 
Decl | objcInterfaceDecl | ObjCInterfaceDecl | 
Decl | objcIvarDecl | ObjCIvarDecl | 
Decl | objcMethodDecl | ObjCMethodDecl | 
Decl | objcPropertyDecl | ObjCPropertyDecl | 
Decl | objcProtocolDecl | ObjCProtocolDecl | 
Decl | parmVarDecl | ParmVarDecl | 
Decl | recordDecl | RecordDecl | 
Decl | staticAssertDecl | StaticAssertDecl | 
Decl | templateTypeParmDecl | TemplateTypeParmDecl | 
Decl | translationUnitDecl | TranslationUnitDecl | 
Decl | typeAliasDecl | TypeAliasDecl | 
Decl | typeAliasTemplateDecl | TypeAliasTemplateDecl | 
Decl | typedefDecl | TypedefDecl | 
Decl | typedefNameDecl | TypedefNameDecl | 
Decl | unresolvedUsingTypenameDecl | UnresolvedUsingTypenameDecl | 
Decl | unresolvedUsingValueDecl | UnresolvedUsingValueDecl | 
Decl | usingDecl | UsingDecl | :heavy_check_mark:
Decl | usingDirectiveDecl | UsingDirectiveDecl | 
Decl | valueDecl | ValueDecl | 
Decl | varDecl | VarDecl | :heavy_check_mark:
NestedNameSpecifierLoc | nestedNameSpecifierLoc | NestedNameSpecifierLoc | 
NestedNameSpecifier | nestedNameSpecifier | NestedNameSpecifier | 
OMPClause | ompDefaultClause | OMPDefaultClause | 
QualType | qualType | QualType | 
Stmt | addrLabelExpr | AddrLabelExpr | 
Stmt | arraySubscriptExpr | ArraySubscriptExpr | 
Stmt | asmStmt | AsmStmt | 
Stmt | atomicExpr | AtomicExpr | 
Stmt | autoreleasePoolStmt | ObjCAutoreleasePoolStmt | 
Stmt | binaryConditionalOperator | BinaryConditionalOperator | 
Stmt | binaryOperator | BinaryOperator | 
Stmt | blockExpr | BlockExpr | 
Stmt | breakStmt | BreakStmt | 
Stmt | cStyleCastExpr | CStyleCastExpr | 
Stmt | callExpr | CallExpr | 
Stmt | caseStmt | CaseStmt | 
Stmt | castExpr | CastExpr | 
Stmt | characterLiteral | CharacterLiteral | 
Stmt | chooseExpr | ChooseExpr | 
Stmt | compoundLiteralExpr | CompoundLiteralExpr | 
Stmt | compoundStmt | CompoundStmt | 
Stmt | conditionalOperator | ConditionalOperator | 
Stmt | constantExpr | ConstantExpr | 
Stmt | continueStmt | ContinueStmt | 
Stmt | cudaKernelCallExpr | CUDAKernelCallExpr | 
Stmt | cxxBindTemporaryExpr | CXXBindTemporaryExpr | 
Stmt | cxxBoolLiteral | CXXBoolLiteralExpr | 
Stmt | cxxCatchStmt | CXXCatchStmt | 
Stmt | cxxConstCastExpr | CXXConstCastExpr | 
Stmt | cxxConstructExpr | CXXConstructExpr | 
Stmt | cxxDefaultArgExpr | CXXDefaultArgExpr | 
Stmt | cxxDeleteExpr | CXXDeleteExpr | 
Stmt | cxxDependentScopeMemberExpr | CXXDependentScopeMemberExpr | 
Stmt | cxxDynamicCastExpr | CXXDynamicCastExpr | 
Stmt | cxxForRangeStmt | CXXForRangeStmt | 
Stmt | cxxFunctionalCastExpr | CXXFunctionalCastExpr | 
Stmt | cxxMemberCallExpr | CXXMemberCallExpr | 
Stmt | cxxNewExpr | CXXNewExpr | 
Stmt | cxxNullPtrLiteralExpr | CXXNullPtrLiteralExpr | 
Stmt | cxxOperatorCallExpr | CXXOperatorCallExpr | 
Stmt | cxxReinterpretCastExpr | CXXReinterpretCastExpr | 
Stmt | cxxStaticCastExpr | CXXStaticCastExpr | 
Stmt | cxxStdInitializerListExpr | CXXStdInitializerListExpr | 
Stmt | cxxTemporaryObjectExpr | CXXTemporaryObjectExpr | 
Stmt | cxxThisExpr | CXXThisExpr | 
Stmt | cxxThrowExpr | CXXThrowExpr | 
Stmt | cxxTryStmt | CXXTryStmt | 
Stmt | cxxUnresolvedConstructExpr | CXXUnresolvedConstructExpr | 
Stmt | declRefExpr | DeclRefExpr | :heavy_check_mark:
Stmt | declStmt | DeclStmt | 
Stmt | defaultStmt | DefaultStmt | 
Stmt | designatedInitExpr | DesignatedInitExpr | 
Stmt | doStmt | DoStmt | 
Stmt | explicitCastExpr | ExplicitCastExpr | 
Stmt | expr | Expr | 
Stmt | exprWithCleanups | ExprWithCleanups | 
Stmt | floatLiteral | FloatingLiteral | 
Stmt | forStmt | ForStmt | 
Stmt | gnuNullExpr | GNUNullExpr | 
Stmt | gotoStmt | GotoStmt | 
Stmt | ifStmt | IfStmt | 
Stmt | imaginaryLiteral | ImaginaryLiteral | 
Stmt | implicitCastExpr | ImplicitCastExpr | 
Stmt | implicitValueInitExpr | ImplicitValueInitExpr | 
Stmt | initListExpr | InitListExpr | 
Stmt | integerLiteral | IntegerLiteral | 
Stmt | labelStmt | LabelStmt | 
Stmt | lambdaExpr | LambdaExpr | 
Stmt | materializeTemporaryExpr | MaterializeTemporaryExpr | 
Stmt | memberExpr | MemberExpr | 
Stmt | nullStmt | NullStmt | 
Stmt | objcCatchStmt | ObjCAtCatchStmt | 
Stmt | objcFinallyStmt | ObjCAtFinallyStmt | 
Stmt | objcIvarRefExpr | ObjCIvarRefExpr | 
Stmt | objcMessageExpr | ObjCMessageExpr | 
Stmt | objcThrowStmt | ObjCAtThrowStmt | 
Stmt | objcTryStmt | ObjCAtTryStmt | 
Stmt | ompExecutableDirective | OMPExecutableDirective | 
Stmt | opaqueValueExpr | OpaqueValueExpr | 
Stmt | parenExpr | ParenExpr | 
Stmt | parenListExpr | ParenListExpr | 
Stmt | predefinedExpr | PredefinedExpr | 
Stmt | returnStmt | ReturnStmt | 
Stmt | stmt | Stmt | 
Stmt | stmtExpr | StmtExpr | 
Stmt | stringLiteral | StringLiteral | 
Stmt | substNonTypeTemplateParmExpr | SubstNonTypeTemplateParmExpr | 
Stmt | switchCase | SwitchCase | 
Stmt | switchStmt | SwitchStmt | 
Stmt | unaryExprOrTypeTraitExpr | UnaryExprOrTypeTraitExpr | 
Stmt | unaryOperator | UnaryOperator | 
Stmt | unresolvedLookupExpr | UnresolvedLookupExpr | 
Stmt | unresolvedMemberExpr | UnresolvedMemberExpr | 
Stmt | userDefinedLiteral | UserDefinedLiteral | 
Stmt | whileStmt | WhileStmt | 
TemplateArgument | templateArgument | TemplateArgument | 
TemplateName | templateName | TemplateName | 
TypeLoc | typeLoc | TypeLoc | 
Type | arrayType | ArrayType | 
Type | atomicType | AtomicType | 
Type | autoType | AutoType | 
Type | blockPointerType | BlockPointerType | 
Type | builtinType | BuiltinType | 
Type | complexType | ComplexType | 
Type | constantArrayType | ConstantArrayType | 
Type | decayedType | DecayedType | 
Type | decltypeType | DecltypeType | 
Type | dependentSizedArrayType | DependentSizedArrayType | 
Type | elaboratedType | ElaboratedType | 
Type | enumType | EnumType | 
Type | functionProtoType | FunctionProtoType | 
Type | functionType | FunctionType | 
Type | incompleteArrayType | IncompleteArrayType | 
Type | injectedClassNameType | InjectedClassNameType | 
Type | lValueReferenceType | LValueReferenceType | 
Type | memberPointerType | MemberPointerType | 
Type | objcObjectPointerType | ObjCObjectPointerType | 
Type | parenType | ParenType | 
Type | pointerType | PointerType | 
Type | rValueReferenceType | RValueReferenceType | 
Type | recordType | RecordType | 
Type | referenceType | ReferenceType | 
Type | substTemplateTypeParmType | SubstTemplateTypeParmType | 
Type | tagType | TagType | 
Type | templateSpecializationType | TemplateSpecializationType | 
Type | templateTypeParmType | TemplateTypeParmType | 
Type | type | Type | 
Type | typedefType | TypedefType | 
Type | unaryTransformType | UnaryTransformType | 
Type | variableArrayType | VariableArrayType | 
