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

Name | Implemented | Tested
------------ | ------------- | ------------- 
cxxCtorInitializer |  | 
accessSpecDecl |  | 
blockDecl |  | 
classTemplateDecl |  | 
classTempleParalSpelizionDecl |  | 
classTempleSpelizionDecl |  | 
cxxConstructorDecl |  | 
cxxConversionDecl |  | 
cxxDestructorDecl |  | 
cxxMethodDecl | :heavy_check_mark: | 
cxxRecordDecl |  | 
decl | :heavy_check_mark: | 
declaratorDecl |  | 
enumConstantDecl |  | 
enumDecl |  | 
fieldDecl |  | 
friendDecl |  | 
functionDecl | :heavy_check_mark: | 
functionTemplateDecl |  | 
indirectFieldDecl |  | 
labelDecl |  | 
linkageSpecDecl |  | 
namedDecl | :heavy_check_mark: | 
namespaceAliasDecl |  | 
namespaceDecl |  | 
nonTypeTemplateParmDecl |  | 
objcCategoryDecl |  | 
objcCategoryImplDecl |  | 
objcImplementationDecl |  | 
objcInterfaceDecl |  | 
objcIvarDecl |  | 
objcMethodDecl |  | 
objcPropertyDecl |  | 
objcProtocolDecl |  | 
parmVarDecl |  | 
recordDecl |  | 
staticAssertDecl |  | 
templateTypeParmDecl |  | 
translationUnitDecl |  | 
typeAliasDecl |  | 
typeAliasTemplateDecl |  | 
typedefDecl |  | 
typedefNameDecl |  | 
unresolvedUsingTypenameDecl |  | 
unresolvedUsingValueDecl |  | 
usingDecl | :heavy_check_mark: | 
usingDirectiveDecl |  | 
valueDecl |  | 
varDecl | :heavy_check_mark: | 
nestedNameSpecifierLoc |  | 
nestedNameSpecifier |  | 
ompDefaultClause |  | 
qualType |  | 
addrLabelExpr |  | 
arraySubscriptExpr |  | 
asmStmt |  | 
atomicExpr |  | 
autoreleasePoolStmt |  | 
binaryConditionalOperator |  | 
binaryOperator |  | 
blockExpr |  | 
breakStmt |  | 
cStyleCastExpr |  | 
callExpr |  | 
caseStmt |  | 
castExpr |  | 
characterLiteral |  | 
chooseExpr |  | 
compoundLiteralExpr |  | 
compoundStmt |  | 
conditionalOperator |  | 
constantExpr |  | 
continueStmt |  | 
cudaKernelCallExpr |  | 
cxxBindTemporaryExpr |  | 
cxxBoolLiteral |  | 
cxxCatchStmt |  | 
cxxConstCastExpr |  | 
cxxConstructExpr |  | 
cxxDefaultArgExpr |  | 
cxxDeleteExpr |  | 
cxxDependentScopeMemberExpr |  | 
cxxDynamicCastExpr |  | 
cxxForRangeStmt |  | 
cxxFunctionalCastExpr |  | 
cxxMemberCallExpr |  | 
cxxNewExpr |  | 
cxxNullPtrLiteralExpr |  | 
cxxOperatorCallExpr |  | 
cxxReinterpretCastExpr |  | 
cxxStaticCastExpr |  | 
cxxStdInitializerListExpr |  | 
cxxTemporaryObjectExpr |  | 
cxxThisExpr |  | 
cxxThrowExpr |  | 
cxxTryStmt |  | 
cxxUnresolvedConstructExpr |  | 
declRefExpr | :heavy_check_mark: | 
declStmt |  | 
defaultStmt |  | 
designatedInitExpr |  | 
doStmt |  | 
explicitCastExpr |  | 
expr |  | 
exprWithCleanups |  | 
floatLiteral |  | 
forStmt |  | 
gnuNullExpr |  | 
gotoStmt |  | 
ifStmt |  | 
imaginaryLiteral |  | 
implicitCastExpr |  | 
implicitValueInitExpr |  | 
initListExpr |  | 
integerLiteral |  | 
labelStmt |  | 
lambdaExpr |  | 
materializeTemporaryExpr |  | 
memberExpr |  | 
nullStmt |  | 
objcCatchStmt |  | 
objcFinallyStmt |  | 
objcIvarRefExpr |  | 
objcMessageExpr |  | 
objcThrowStmt |  | 
objcTryStmt |  | 
ompExecutableDirective |  | 
opaqueValueExpr |  | 
parenExpr |  | 
parenListExpr |  | 
predefinedExpr |  | 
returnStmt |  | 
stmt |  | 
stmtExpr |  | 
stringLiteral |  | 
substNonTypeTemplateParmExpr |  | 
switchCase |  | 
switchStmt |  | 
unaryExprOrTypeTraitExpr |  | 
unaryOperator |  | 
unresolvedLookupExpr |  | 
unresolvedMemberExpr |  | 
userDefinedLiteral |  | 
whileStmt |  | 
templateArgument |  | 
templateName |  | 
typeLoc |  | 
arrayType |  | 
atomicType |  | 
autoType |  | 
blockPointerType |  | 
builtinType |  | 
complexType |  | 
constantArrayType |  | 
decayedType |  | 
decltypeType |  | 
dependentSizedArrayType |  | 
elaboratedType |  | 
enumType |  | 
functionProtoType |  | 
functionType |  | 
incompleteArrayType |  | 
injectedClassNameType |  | 
lValueReferenceType |  | 
memberPointerType |  | 
objcObjectPointerType |  | 
parenType |  | 
pointerType |  | 
rValueReferenceType |  | 
recordType |  | 
referenceType |  | 
substTemplateTypeParmType |  | 
tagType |  | 
templateSpecializationType |  | 
templateTypeParmType |  | 
type |  | 
typedefType |  | 
unaryTransformType |  | 
variableArrayType
