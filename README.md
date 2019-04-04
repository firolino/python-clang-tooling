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
accessSpecDecl |  | 
addrLabelExpr |  | 
arraySubscriptExpr |  | 
arrayType |  | 
asmStmt |  | 
atomicExpr |  | 
atomicType |  | 
autoreleasePoolStmt |  | 
autoType |  | 
binaryConditionalOperator |  | 
binaryOperator |  | 
blockDecl |  | 
blockExpr |  | 
blockPointerType |  | 
breakStmt |  | 
builtinType |  | 
callExpr |  | 
caseStmt |  | 
castExpr |  | 
characterLiteral |  | 
chooseExpr |  | 
classTemplateDecl |  | 
classTempleParalSpelizionDecl |  | 
classTempleSpelizionDecl |  | 
complexType |  | 
compoundLiteralExpr |  | 
compoundStmt |  | 
conditionalOperator |  | 
constantArrayType |  | 
constantExpr |  | 
continueStmt |  | 
cStyleCastExpr |  | 
cudaKernelCallExpr |  | 
cxxBindTemporaryExpr |  | 
cxxBoolLiteral |  | 
cxxCatchStmt |  | 
cxxConstCastExpr |  | 
cxxConstructExpr |  | 
cxxConstructorDecl |  | 
cxxConversionDecl |  | 
cxxCtorInitializer |  | 
cxxDefaultArgExpr |  | 
cxxDeleteExpr |  | 
cxxDependentScopeMemberExpr |  | 
cxxDestructorDecl |  | 
cxxDynamicCastExpr |  | 
cxxForRangeStmt |  | 
cxxFunctionalCastExpr |  | 
cxxMemberCallExpr |  | 
cxxMethodDecl | :heavy_check_mark: | 
cxxNewExpr |  | 
cxxNullPtrLiteralExpr |  | 
cxxOperatorCallExpr |  | 
cxxRecordDecl |  | 
cxxReinterpretCastExpr |  | 
cxxStaticCastExpr |  | 
cxxStdInitializerListExpr |  | 
cxxTemporaryObjectExpr |  | 
cxxThisExpr |  | 
cxxThrowExpr |  | 
cxxTryStmt |  | 
cxxUnresolvedConstructExpr |  | 
decayedType |  | 
decl | :heavy_check_mark: | 
declaratorDecl |  | 
declRefExpr | :heavy_check_mark: | 
declStmt |  | 
decltypeType |  | 
defaultStmt |  | 
dependentSizedArrayType |  | 
designatedInitExpr |  | 
doStmt |  | 
elaboratedType |  | 
enumConstantDecl |  | 
enumDecl |  | 
enumType |  | 
explicitCastExpr |  | 
expr |  | 
exprWithCleanups |  | 
fieldDecl |  | 
floatLiteral |  | 
forStmt |  | 
friendDecl |  | 
functionDecl | :heavy_check_mark: | 
functionProtoType |  | 
functionTemplateDecl |  | 
functionType |  | 
gnuNullExpr |  | 
gotoStmt |  | 
ifStmt |  | 
imaginaryLiteral |  | 
implicitCastExpr |  | 
implicitValueInitExpr |  | 
incompleteArrayType |  | 
indirectFieldDecl |  | 
initListExpr |  | 
injectedClassNameType |  | 
integerLiteral |  | 
labelDecl |  | 
labelStmt |  | 
lambdaExpr |  | 
linkageSpecDecl |  | 
lValueReferenceType |  | 
materializeTemporaryExpr |  | 
memberExpr |  | 
memberPointerType |  | 
namedDecl | :heavy_check_mark: | 
namespaceAliasDecl |  | 
namespaceDecl |  | 
nestedNameSpecifier |  | 
nestedNameSpecifierLoc |  | 
nonTypeTemplateParmDecl |  | 
nullStmt |  | 
objcCatchStmt |  | 
objcCategoryDecl |  | 
objcCategoryImplDecl |  | 
objcFinallyStmt |  | 
objcImplementationDecl |  | 
objcInterfaceDecl |  | 
objcIvarDecl |  | 
objcIvarRefExpr |  | 
objcMessageExpr |  | 
objcMethodDecl |  | 
objcObjectPointerType |  | 
objcPropertyDecl |  | 
objcProtocolDecl |  | 
objcThrowStmt |  | 
objcTryStmt |  | 
ompDefaultClause |  | 
ompExecutableDirective |  | 
opaqueValueExpr |  | 
parenExpr |  | 
parenListExpr |  | 
parenType |  | 
parmVarDecl |  | 
pointerType |  | 
predefinedExpr |  | 
qualType |  | 
recordDecl |  | 
recordType |  | 
referenceType |  | 
returnStmt |  | 
rValueReferenceType |  | 
staticAssertDecl |  | 
stmt |  | 
stmtExpr |  | 
stringLiteral |  | 
substNonTypeTemplateParmExpr |  | 
substTemplateTypeParmType |  | 
switchCase |  | 
switchStmt |  | 
tagType |  | 
templateArgument |  | 
templateName |  | 
templateSpecializationType |  | 
templateTypeParmDecl |  | 
templateTypeParmType |  | 
translationUnitDecl |  | 
type |  | 
typeAliasDecl |  | 
typeAliasTemplateDecl |  | 
typedefDecl |  | 
typedefNameDecl |  | 
typedefType |  | 
typeLoc |  | 
unaryExprOrTypeTraitExpr |  | 
unaryOperator |  | 
unaryTransformType |  | 
unresolvedLookupExpr |  | 
unresolvedMemberExpr |  | 
unresolvedUsingTypenameDecl |  | 
unresolvedUsingValueDecl |  | 
userDefinedLiteral |  | 
usingDecl | :heavy_check_mark: | 
usingDirectiveDecl |  | 
valueDecl |  | 
varDecl | :heavy_check_mark: | 
variableArrayType |  | 
whileStmt |  | 

# Narrowing Matchers

Name | Implemented | Tested
------------ | ------------- | ------------- 
allOf |  | 
anyOf |  | 
anything |  | 
argumentCountIs | :heavy_check_mark: | 
asString | :heavy_check_mark: | 
booleanType |  | 
declCountIs |  | 
designatorCountIs |  | 
equals |  | 
equalsBoundNode |  | 
equalsIntegralValue |  | 
equalsNode |  | 
hasAnyName |  | 
hasAnySelector |  | 
hasAttr |  | 
hasAutomaticStorageDuration |  | 
hasBitWidth |  | 
hasCastKind |  | 
hasDefaultArgument |  | 
hasDefinition |  | 
hasDynamicExceptionSpec |  | 
hasExternalFormalLinkage |  | 
hasGlobalStorage |  | 
hasKeywordSelector |  | 
hasLocalQualifiers |  | 
hasLocalStorage |  | 
hasName | :heavy_check_mark: | 
hasNullSelector |  | 
hasOperatorName |  | 
hasOverloadedOperatorName |  | 
hasSelector |  | 
hasSize |  | 
hasStaticStorageDuration |  | 
hasThreadStorageDuration |  | 
hasTrailingReturn |  | 
hasUnarySelector |  | 
isAllowedToContainClauseKind |  | 
isAnonymous |  | 
isAnyCharacter |  | 
isAnyPointer |  | 
isArray |  | 
isArrow |  | 
isAssignmentOperator |  | 
isBaseInitializer |  | 
isBitField |  | 
isCatchAll |  | 
isClass |  | 
isConst |  | 
isConstexpr |  | 
isConstQualified |  | 
isCopyAssignmentOperator |  | 
isCopyConstructor |  | 
isDefaultConstructor |  | 
isDefaulted |  | 
isDefinition |  | 
isDelegatingConstructor |  | 
isDeleted |  | 
isDerivedFrom |  | 
isExceptionVariable |  | 
isExpansionInFileMatching | :heavy_check_mark: | 
isExpansionInMainFile |  | 
isExpansionInSystemHeader |  | 
isExplicit |  | 
isExplicitTemplateSpecialization |  | 
isExternC |  | 
isFinal |  | 
isImplicit |  | 
isInline |  | 
isInstanceMessage |  | 
isInstantiated |  | 
isInstantiationDependent |  | 
isInteger | :heavy_check_mark: | 
isIntegral |  | 
isInTemplateInstantiation |  | 
isLambda |  | 
isListInitialization |  | 
isMain |  | 
isMemberInitializer |  | 
isMoveAssignmentOperator |  | 
isMoveConstructor |  | 
isNoneKind |  | 
isNoReturn |  | 
isNoThrow |  | 
isOMPStructuredBlock |  | 
isOverride |  | 
isPrivate |  | 
isProtected |  | 
isPublic |  | 
isPure |  | 
isSameOrDerivedFrom |  | 
isScoped |  | 
isSharedKind |  | 
isSignedInteger |  | 
isStandaloneDirective |  | 
isStaticLocal |  | 
isStaticStorageClass |  | 
isStruct |  | 
isTemplateInstantiation |  | 
isTypeDependent |  | 
isUnion |  | 
isUnsignedInteger |  | 
isUserProvided |  | 
isValueDependent |  | 
isVariadic |  | 
isVirtual |  | 
isVirtualAsWritten |  | 
isVolatileQualified |  | 
isWritten |  | 
matchesName | :heavy_check_mark: | 
matchesSelector |  | 
nullPointerConstant |  | 
numSelectorArgs |  | 
ofKind |  | 
parameterCountIs | :heavy_check_mark: | 
realFloatingPointType |  | 
requiresZeroInitialization |  | 
statementCountIs |  | 
templateArgumentCountIs | :heavy_check_mark: | 
unless |  | 
usesADL |  | 
voidType |  | 

# AST Traversal Matchers

Name | Implemented | Tested
------------ | ------------- | ------------- 
alignOfExpr |  | 
callee |  | 
containsDeclaration |  | 
eachOf |  | 
findAll |  | 
forEach |  | 
forEachArgumentWithParam |  | 
forEachConstructorInitializer |  | 
forEachDescendant |  | 
forEachOverridden |  | 
forEachSwitchCase |  | 
forField |  | 
forFunction |  | 
has |  | 
hasAncestor |  | 
hasAnyArgument | :heavy_check_mark: | 
hasAnyClause |  | 
hasAnyConstructorInitializer |  | 
hasAnyDeclaration |  | 
hasAnyParameter | :heavy_check_mark: | 
hasAnySubstatement |  | 
hasAnyTemplateArgument | :heavy_check_mark: | 
hasAnyUsingShadowDecl |  | 
hasArgument |  | 
hasArgumentOfType |  | 
hasArraySize |  | 
hasBase |  | 
hasBody |  | 
hasCanonicalType |  | 
hasCaseConstant |  | 
hasCondition |  | 
hasConditionVariableStatement |  | 
hasDecayedType |  | 
hasDeclaration |  | 
hasDeclContext |  | 
hasDeducedType |  | 
hasDescendant |  | 
hasDestinationType |  | 
hasEitherOperand |  | 
hasElementType |  | 
hasElse |  | 
hasFalseExpression |  | 
hasImplicitDestinationType |  | 
hasInClassInitializer |  | 
hasIncrement |  | 
hasIndex |  | 
hasInit |  | 
hasInitializer |  | 
hasLHS |  | 
hasLoopInit |  | 
hasLoopVariable |  | 
hasMethod |  | 
hasObjectExpression |  | 
hasParameter |  | 
hasParent |  | 
hasPrefix |  | 
hasQualifier |  | 
hasRangeInit |  | 
hasReceiver |  | 
hasReceiverType |  | 
hasReplacementType |  | 
hasReturnValue |  | 
hasRHS |  | 
hasSingleDecl |  | 
hasSizeExpr |  | 
hasSourceExpression |  | 
hasSpecializedTemplate |  | 
hasStructuredBlock |  | 
hasSyntacticForm |  | 
hasTargetDecl |  | 
hasTemplateArgument |  | 
hasThen |  | 
hasTrueExpression |  | 
hasType | :heavy_check_mark: | 
hasTypeLoc |  | 
hasUnaryOperand |  | 
hasUnderlyingDecl |  | 
hasUnderlyingType |  | 
hasUnqualifiedDesugaredType |  | 
hasValueType |  | 
ignoringImpCasts |  | 
ignoringImplicit |  | 
ignoringParenCasts |  | 
ignoringParenImpCasts |  | 
ignoringParens |  | 
innerType |  | 
isDerivedFrom |  | 
isExpr |  | 
isSameOrDerivedFrom |  | 
loc |  | 
member |  | 
namesType |  | 
ofClass |  | 
on |  | 
onImplicitObjectArgument |  | 
pointee |  | 
pointsTo |  | 
references |  | 
refersToDeclaration |  | 
refersToIntegralType |  | 
refersToTemplate |  | 
refersToType | :heavy_check_mark: | 
returns |  | 
sizeOfExpr |  | 
specifiesNamespace |  | 
specifiesType |  | 
specifiesTypeLoc |  | 
thisPointerType |  | 
throughUsingDecl |  | 
to |  | 
withInitializer |  | 
