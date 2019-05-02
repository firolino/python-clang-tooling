import unittest
from libtooling import *

hasMatched = False
bindingIsCorrect = False
bindingNameToCheck = ("", 0)
currentBindingCount = 0

def callback(nodes):
    global hasMatched
    hasMatched = True

def callbackWithBindingCheck(nodes):
    global hasMatched
    global bindingIsCorrect
    global bindingNameToCheck
    global currentBindingCount
    hasMatched = True    
    if nodes.getParmVarDecl(bindingNameToCheck[0]):
        currentBindingCount = currentBindingCount + 1
        if currentBindingCount == bindingNameToCheck[1]:
            bindingIsCorrect = True        

def matches(src, matcher):
    global hasMatched
    hasMatched = False
    tooling = Tooling()
    tooling.add(matcher, callback)
    tooling.run_from_source(src)
    return hasMatched

def notMatches(src, matcher):
    return matches(src, matcher) == False
    
def matchAndVerifyResultTrue(src, matcher, idVerifier):
    global hasMatched
    global bindingIsCorrect
    global bindingNameToCheck
    global currentBindingCount
    hasMatched = False
    bindingIsCorrect = False
    currentBindingCount = 0
    bindingNameToCheck = idVerifier
    tooling = Tooling()
    tooling.add(matcher, callbackWithBindingCheck)
    tooling.run_from_source(src)
    return hasMatched and bindingIsCorrect
    
def VerifyIdIsBoundToParmVarDecl(name, expectedCount):
    return (name, expectedCount)

class TestMatchers(unittest.TestCase):

    def test_dummy(self):
        ArgumentY = declRefExpr(to(varDecl(hasName("y")))).bind("arg")
        IntParam = parmVarDecl(hasType(isInteger())).bind("param")
        CallExpr = callExpr(forEachArgumentWithParam(ArgumentY, IntParam))
        
        self.assertTrue(notMatches("void f(int* i) { int* y; f(y); }", CallExpr))
        self.assertTrue(notMatches("void f(int i) { int x; f(x); }", CallExpr))
        
        ArgumentY = declRefExpr(to(varDecl(hasName("y")))).bind("arg")
        IntParam = parmVarDecl(hasType(isInteger())).bind("param")
        CallExpr = callExpr(forEachArgumentWithParam(ArgumentY, IntParam))
        
        self.assertTrue(matchAndVerifyResultTrue(
                                    "struct S {"
                                    "  const S& operator[](int i) { return *this; }"
                                    "};"
                                    "void f(S S1) {"
                                    "  int y = 1;"
                                    "  S1[y];"
                                    "}", CallExpr, VerifyIdIsBoundToParmVarDecl("param", 1)))

        CallExpr2 = callExpr(forEachArgumentWithParam(ArgumentY, IntParam))
        
        self.assertTrue(matchAndVerifyResultTrue(
                                    "struct S {"
                                    "  static void g(int i);"
                                    "};"
                                    "void f() {"
                                    "  int y = 1;"
                                    "  S::g(y);"
                                    "}", CallExpr2, VerifyIdIsBoundToParmVarDecl("param", 1)))                                    
        
    def test_accessSpecDecl(self):
        self.assertTrue("class C { public: int i; };", accessSpecDecl())    
        self.assertTrue("class C { public: int i; };", accessSpecDecl(isPublic()))

    def test_addrLabelExpr(self):
       self.assertTrue(matches("void f() { FOO: ; void *ptr = &&FOO; goto *ptr; }", addrLabelExpr()))

    def test_arraySubscriptMatchers(self):
        self.assertTrue(matches("int i[2]; void f() { i[1] = 1; }", arraySubscriptExpr()))
        self.assertTrue(matches("int i[2]; void f() { i[1] = 1; }", arraySubscriptExpr(hasIndex(integerLiteral(equals(1))))))
        self.assertTrue(matches("int i[2]; void f() { 1[i] = 1; }",arraySubscriptExpr(hasIndex(integerLiteral(equals(1))))))
        self.assertTrue(notMatches("int i[2]; void f() { i[1] = 1; }", arraySubscriptExpr(hasIndex(integerLiteral(equals(0))))))

    def test_arrayType(self):
        self.assertTrue(matches("int a[] = {2,3};", arrayType()))
        self.assertTrue(matches("int a[42];", arrayType()))
        self.assertTrue(matches("void f(int b) { int a[b]; }", arrayType()))
        self.assertTrue(notMatches("struct A {}; A a[7];", arrayType(hasElementType(builtinType()))))
        self.assertTrue(matches("int const a[] = { 2, 3 };", qualType(arrayType(hasElementType(builtinType())))))
        self.assertTrue(matches("int const a[] = { 2, 3 };", qualType(isConstQualified(), arrayType(hasElementType(builtinType())))))
        self.assertTrue(matches("typedef const int T; T x[] = { 1, 2 };", qualType(isConstQualified(), arrayType())))
        self.assertTrue(notMatches("int a[] = { 2, 3 };", qualType(isConstQualified(), arrayType(hasElementType(builtinType())))))
        self.assertTrue(notMatches("int a[] = { 2, 3 };", qualType(arrayType(hasElementType(isConstQualified(), builtinType())))))
        self.assertTrue(notMatches("int const a[] = { 2, 3 };", qualType(arrayType(hasElementType(builtinType())), unless(isConstQualified()))))
        self.assertTrue(matches("int a[2];", constantArrayType(hasElementType(builtinType()))))
        self.assertTrue(matches("const int a = 0;", qualType(isInteger())))
        self.assertTrue(matches("int a[2];", constantArrayType()))
        self.assertTrue(notMatches("void f() { int a[] = { 2, 3 }; int b[a[0]]; }", constantArrayType(hasElementType(builtinType()))))
        self.assertTrue(matches("int a[42];", constantArrayType(hasSize(42))))
        self.assertTrue(matches("int b[2*21];", constantArrayType(hasSize(42))))
        self.assertTrue(notMatches("int c[41], d[43];", constantArrayType(hasSize(42))))

    def test_unless(self):
        unless(isImplicit())
    
    def test_asmStatement(self):
        self.assertTrue(matches("void foo() { __asm(\"mov al, 2\"); }", asmStmt()))

    def test_atomic(self):
        self.assertTrue(matches("void foo() { int *ptr; __atomic_load_n(ptr, 1); }", atomicExpr()))
        self.assertTrue(matches("_Atomic(int) i;", atomicType()))
        self.assertTrue(matches("_Atomic(int) i;", atomicType(hasValueType(isInteger()))))
        self.assertTrue(notMatches("_Atomic(float) f;", atomicType(hasValueType(isInteger()))))

    def test_usingDecl(self):
        self.assertTrue(notMatches("", decl(usingDecl())))
        self.assertTrue(matches("namespace x { class X {}; } using x::X;", decl(usingDecl())))
    
    def test_hasName(self):
        NamedX = namedDecl(hasName("X"))
        self.assertTrue(matches("void foo() { int X; }", NamedX))

    def test_matchesName(self):
        NamedX = namedDecl(matchesName("::X"))
        self.assertTrue(matches("typedef int Xa;", NamedX))
        self.assertTrue(matches("int Xb;", NamedX))

if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestMatchers)
    unittest.TextTestRunner(verbosity=2).run(suite)
