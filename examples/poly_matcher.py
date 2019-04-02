from libtooling import *

## AST_MATCHER_P

declRefExpr()
asString("int")
refersToType(asString("int"))

isExpansionInFileMatching("")
hasAnyTemplateArgument(refersToType(asString("int")))
templateArgumentCountIs(0)
argumentCountIs(0)
hasAnyArgument(declRefExpr())

hasName("X")
hasAnyParameter(hasName("X"))
parameterCountIs(0)
functionDecl()
functionDecl(hasName(""))
#hasCondition
#equalsBoundNode
#hasBody
#hasAnySubstatement
#hasOperatorName
#hasLHS
#hasRHS
#hasSourceExpression
#hasSize

