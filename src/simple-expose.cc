#include "simple-expose.h"
#include <boost/python.hpp>
#include <clang/ASTMatchers/ASTMatchers.h>

void expose_simple()
{
    using namespace boost::python;

    using namespace clang;
    using namespace clang::ast_matchers;
    using namespace clang::ast_matchers::internal;

    def("asString", asString);
    def("booleanType", booleanType);
    def("containsDeclaration", containsDeclaration);
    def("declCountIs", declCountIs);
    def("designatorCountIs", designatorCountIs);
    def("equalsIntegralValue", equalsIntegralValue);
    def("forEachConstructorInitializer", forEachConstructorInitializer);
    def("forEachOverridden", forEachOverridden);
    def("forEachSwitchCase", forEachSwitchCase);
    def("forField", forField);
    def("forFunction", forFunction);
    def("hasAnyConstructorInitializer", hasAnyConstructorInitializer);
    def("hasAnyDeclaration", hasAnyDeclaration);
    def("hasAnyUsingShadowDecl", hasAnyUsingShadowDecl);
    def("hasArgumentOfType", hasArgumentOfType);
    def("hasArraySize", hasArraySize);
    def("hasAttr", hasAttr);
    def("hasAutomaticStorageDuration", hasAutomaticStorageDuration);
    def("hasBase", hasBase);
    def("hasBitWidth", hasBitWidth);
    def("hasCanonicalType", hasCanonicalType);
    def("hasCaseConstant", hasCaseConstant);
    def("hasCastKind", hasCastKind);
    def("hasConditionVariableStatement", hasConditionVariableStatement);
    def("hasDecayedType", hasDecayedType);
    def("hasDeclContext", hasDeclContext);
    def("hasDefaultArgument", hasDefaultArgument);
    def("hasDefinition", hasDefinition);
    def("hasDestinationType", hasDestinationType);
    def("hasElse", hasElse);
    def("hasExternalFormalLinkage", hasExternalFormalLinkage);
    def("hasFalseExpression", hasFalseExpression);
    def("hasGlobalStorage", hasGlobalStorage);
    def("hasImplicitDestinationType", hasImplicitDestinationType);
    def("hasInClassInitializer", hasInClassInitializer);
    def("hasIncrement", hasIncrement);
    def("hasIndex", hasIndex);
    def("hasInit", hasInit);
    def("hasInitializer", hasInitializer);
    def("hasKeywordSelector", hasKeywordSelector);
    def("hasLocalQualifiers", hasLocalQualifiers);
    def("hasLocalStorage", hasLocalStorage);
    def("hasLoopInit", hasLoopInit);
    def("hasLoopVariable", hasLoopVariable);
    def("hasMethod", hasMethod);
    def("hasNullSelector", hasNullSelector);
    def("hasQualifier", hasQualifier);
    def("hasRangeInit", hasRangeInit);
    def("hasReceiver", hasReceiver);
    def("hasReceiverType", hasReceiverType);
    def("hasReturnValue", hasReturnValue);
    def("hasSelector", hasSelector);
    def("hasSingleDecl", hasSingleDecl);
    def("hasSizeExpr", hasSizeExpr);
    def("hasSpecializedTemplate", hasSpecializedTemplate);
    def("hasStaticStorageDuration", hasStaticStorageDuration);
    def("hasSyntacticForm", hasSyntacticForm);
    def("hasTargetDecl", hasTargetDecl);
    def("hasThen", hasThen);
    def("hasThreadStorageDuration", hasThreadStorageDuration);
    def("hasTrailingReturn", hasTrailingReturn);
    def("hasTrueExpression", hasTrueExpression);
    def("hasTypeLoc", hasTypeLoc);
    def("hasUnaryOperand", hasUnaryOperand);
    def("hasUnarySelector", hasUnarySelector);
    def("hasUnderlyingDecl", hasUnderlyingDecl);
    def("hasUnqualifiedDesugaredType", hasUnqualifiedDesugaredType);
    def("ignoringImpCasts", ignoringImpCasts);
    def("ignoringImplicit", ignoringImplicit);
    def("ignoringParenCasts", ignoringParenCasts);
    def("ignoringParenImpCasts", ignoringParenImpCasts);
    def("isAnonymous", isAnonymous);
    def("isAnyCharacter", isAnyCharacter);
    def("isAnyPointer", isAnyPointer);
    def("isArray", isArray);
    def("isBaseInitializer", isBaseInitializer);
    def("isBitField", isBitField);
    def("isCatchAll", isCatchAll);
    def("isClass", isClass);
    def("isConst", isConst);
    def("isConstQualified", isConstQualified);
    def("isCopyAssignmentOperator", isCopyAssignmentOperator);
    def("isCopyConstructor", isCopyConstructor);
    def("isDefaultConstructor", isDefaultConstructor);
    def("isDefaulted", isDefaulted);
    def("isDelegatingConstructor", isDelegatingConstructor);
    def("isDeleted", isDeleted);
    def("isExceptionVariable", isExceptionVariable);
    def("isExpr", isExpr);
    def("isImplicit", isImplicit);
    def("isInstanceMessage", isInstanceMessage);
    def("isInstantiated", isInstantiated);
    def("isInstantiationDependent", isInstantiationDependent);
    def("isInteger", isInteger);
    def("isIntegral", isIntegral);
    def("isInTemplateInstantiation", isInTemplateInstantiation);
    def("isLambda", isLambda);
    def("isListInitialization", isListInitialization);
    def("isMain", isMain);
    def("isMemberInitializer", isMemberInitializer);
    def("isMoveAssignmentOperator", isMoveAssignmentOperator);
    def("isMoveConstructor", isMoveConstructor);
    def("isNoReturn", isNoReturn);
    def("isOverride", isOverride);
    def("isPrivate", isPrivate);
    def("isProtected", isProtected);
    def("isPublic", isPublic);
    def("isPure", isPure);
    def("isScoped", isScoped);
    def("isSignedInteger", isSignedInteger);
    def("isStaticLocal", isStaticLocal);
    def("isStruct", isStruct);
    def("isTypeDependent", isTypeDependent);
    def("isUnion", isUnion);
    def("isUnsignedInteger", isUnsignedInteger);
    def("isUserProvided", isUserProvided);
    def("isValueDependent", isValueDependent);
    def("isVariadic", isVariadic);
    def("isVirtualAsWritten", isVirtualAsWritten);
    def("isVirtual", isVirtual);
    def("isVolatileQualified", isVolatileQualified);
    def("isWritten", isWritten);
    def("matchesName", matchesName);
    def("matchesSelector", matchesSelector);
    def("member", member);
    def("namesType", namesType);
    def("nullPointerConstant", nullPointerConstant);
    def("numSelectorArgs", numSelectorArgs);
    def("ofClass", ofClass);
    def("ofKind", ofKind);
    def("onImplicitObjectArgument", onImplicitObjectArgument);
    def("on", on);
    def("realFloatingPointType", realFloatingPointType);
    def("refersToDeclaration", refersToDeclaration);
    def("refersToIntegralType", refersToIntegralType);
    def("refersToTemplate", refersToTemplate);
    def("refersToType", refersToType);
    def("requiresZeroInitialization", requiresZeroInitialization);
    def("returns", returns);
    def("specifiesNamespace", specifiesNamespace);
    def("specifiesTypeLoc", specifiesTypeLoc);
    def("specifiesType", specifiesType);
    def("statementCountIs", statementCountIs);
    def("throughUsingDecl", throughUsingDecl);
    def("to", to);
    def("usesADL", usesADL);
    def("voidType", voidType);
    def("withInitializer", withInitializer);

    def("alignOfExpr", alignOfExpr);
    def("hasEitherOperand", hasEitherOperand);
    def("hasName", hasName);
    def("sizeOfExpr", sizeOfExpr);

    Matcher<Decl> (*equalsNode_1)(const Decl* const&) = equalsNode;
    Matcher<Stmt> (*equalsNode_2)(const Stmt* const&) = equalsNode;
    Matcher<Type> (*equalsNode_3)(const Type* const&) = equalsNode;

    def("equalsNode", equalsNode_1);
    def("equalsNode", equalsNode_2);
    def("equalsNode", equalsNode_3);

    Matcher<NestedNameSpecifier> (*hasPrefix_1)(const Matcher<NestedNameSpecifier>&) = hasPrefix;
    Matcher<NestedNameSpecifierLoc> (*hasPrefix_2)(const Matcher<NestedNameSpecifierLoc>&) = hasPrefix;

    def("hasPrefix", hasPrefix_1);
    def("hasPrefix", hasPrefix_2);

    Matcher<CXXMemberCallExpr> (*thisPointerType_1)(const Matcher<QualType>&) = thisPointerType;
    Matcher<CXXMemberCallExpr> (*thisPointerType_2)(const Matcher<Decl>&) = thisPointerType;

    def("thisPointerType", thisPointerType_1);
    def("thisPointerType", thisPointerType_2);

    Matcher<QualType> (*references_1)(const Matcher<QualType>&) = references;
    Matcher<QualType> (*references_2)(const Matcher<Decl>&) = references;

    def("references", references_1);
    def("references", references_2);

    Matcher<QualType> (*pointsTo_1)(const Matcher<QualType>&) = pointsTo;
    Matcher<QualType> (*pointsTo_2)(const Matcher<Decl>&) = pointsTo;

    def("pointsTo", pointsTo_1);
    def("pointsTo", pointsTo_2);

    Matcher<CallExpr> (*callee_1)(const Matcher<Stmt>&) = callee;
    Matcher<CallExpr> (*callee_2)(const Matcher<Decl>&) = callee;

    def("callee", callee_1);
    def("callee", callee_2);

    Matcher<CXXRecordDecl> (*isSameOrDerivedFrom_1)(const Matcher<NamedDecl>&) = isSameOrDerivedFrom;
    Matcher<CXXRecordDecl> (*isSameOrDerivedFrom_2)(const std::string&) = isSameOrDerivedFrom;

    def("isSameOrDerivedFrom", isSameOrDerivedFrom_1);
    def("isSameOrDerivedFrom", isSameOrDerivedFrom_2);

    Matcher<QualType> (*ignoringParens_1)(const Matcher<QualType>&) = ignoringParens;
    Matcher<Expr> (*ignoringParens_2)(const Matcher<Expr>&) = ignoringParens;

    def("ignoringParens", ignoringParens_1);
    def("ignoringParens", ignoringParens_2);

    BindableMatcher<TypeLoc> (*loc_1)(const Matcher<QualType>&) = loc;
    BindableMatcher<NestedNameSpecifierLoc> (*loc_2)(const Matcher<NestedNameSpecifier>&) = loc;

    def("loc", loc_1);
    def("loc", loc_2);
}