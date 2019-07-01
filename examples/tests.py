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

    def test_last(self):
        cxxRecordDecl(hasDescendant(cxxRecordDecl(hasName("X"))))
        cxxRecordDecl(forEach(cxxRecordDecl(hasName("X"))))
        compoundStmt(hasParent(ifStmt()))
        expr(integerLiteral(hasAncestor(ifStmt())))
        varDecl(hasType(hasUnqualifiedDesugaredType(recordType(hasDeclaration(decl())))))
        cxxRecordDecl(hasMethod(hasOverloadedOperatorName("*")))

    def test_dummy(self):
        d = pointee(isInteger())
        xx = pointerType(pointee(isConstQualified(), isInteger()))
        
        cxxRecordDecl(has(cxxRecordDecl(hasName("X"))))
        cxxRecordDecl(eachOf(has(fieldDecl(hasName("a")).bind("v")), has(fieldDecl(hasName("b")).bind("v"))))
        
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

class ASTMatchersNodeTest(unittest.TestCase):
    
    def EXPECT_TRUE(self, m):
        self.assertTrue(m)

    def EXPECT_FALSE(self, m):
        self.assertFalse(m)

    def test_MatchesDeclarations(self):
        self.EXPECT_TRUE(notMatches("", decl(usingDecl())))
        self.EXPECT_TRUE(matches("namespace x { class X {}; } using x::X;", decl(usingDecl())))

    def test_MatchesVariousDecls(self):
        NamedX = namedDecl(hasName("X"))
        self.EXPECT_TRUE(matches("typedef int X;", NamedX))
        self.EXPECT_TRUE(matches("int X;", NamedX))
        self.EXPECT_TRUE(matches("class foo { virtual void X(); };", NamedX))
        self.EXPECT_TRUE(matches("void foo() try { } catch(int X) { }", NamedX))
        self.EXPECT_TRUE(matches("void foo() { int X; }", NamedX))
        self.EXPECT_TRUE(matches("namespace X { }", NamedX))
        self.EXPECT_TRUE(matches("enum X { A, B, C };", NamedX))
        self.EXPECT_TRUE(notMatches("#define X 1", NamedX))

    def test_REMatchesVariousDecls(self):
        NamedX = namedDecl(matchesName("::X"))
        self.EXPECT_TRUE(matches("typedef int Xa;", NamedX))
        self.EXPECT_TRUE(matches("int Xb;", NamedX))
        self.EXPECT_TRUE(matches("class foo { virtual void Xc(); };", NamedX))
        self.EXPECT_TRUE(matches("void foo() try { } catch(int Xdef) { }", NamedX))
        self.EXPECT_TRUE(matches("void foo() { int Xgh; }", NamedX))
        self.EXPECT_TRUE(matches("namespace Xij { }", NamedX))
        self.EXPECT_TRUE(matches("enum X { A, B, C };", NamedX))

        self.EXPECT_TRUE(notMatches("#define Xkl 1", NamedX))

        StartsWithNo = namedDecl(matchesName("::no"))
        self.EXPECT_TRUE(matches("int no_foo;", StartsWithNo))
        self.EXPECT_TRUE(matches("class foo { virtual void nobody(); };", StartsWithNo))

        Abc = namedDecl(matchesName("a.*b.*c"))
        self.EXPECT_TRUE(matches("int abc;", Abc))
        self.EXPECT_TRUE(matches("int aFOObBARc;", Abc))
        self.EXPECT_TRUE(notMatches("int cab;", Abc))
        self.EXPECT_TRUE(matches("int cabc;", Abc))

        StartsWithK = namedDecl(matchesName(":k[^:]*$"))
        self.EXPECT_TRUE(matches("int k;", StartsWithK))
        self.EXPECT_TRUE(matches("int kAbc;", StartsWithK))
        self.EXPECT_TRUE(matches("namespace x { int kTest; }", StartsWithK))
        self.EXPECT_TRUE(matches("class C { int k; };", StartsWithK))
        self.EXPECT_TRUE(notMatches("class C { int ckc; };", StartsWithK))
    
    def test_MatchClass(self):
        ClassX = recordDecl(recordDecl(hasName("X")))
        self.EXPECT_TRUE(matches("class X;", ClassX))
        self.EXPECT_TRUE(matches("class X {};", ClassX))
        self.EXPECT_TRUE(matches("template<class T> class X {};", ClassX))
        self.EXPECT_TRUE(notMatches("", ClassX))

    def MkStr(self, Body):
        str = "namespace NS {\
                struct X {};\
                void f(X);\
                void operator+(X, X);\
                }\
                struct MyX {};\
                void f(...);\
                void operator+(MyX, MyX);" + "void test_fn() { " + Body + " }"
        return str

    def test_ADLCall(self):
        ADLMatch = callExpr(usesADL())
        ADLMatchOper = cxxOperatorCallExpr(usesADL())

        self.EXPECT_TRUE(matches(self.MkStr("NS::X x; f(x);"), ADLMatch))
        self.EXPECT_TRUE(notMatches(self.MkStr("NS::X x; NS::f(x);"), ADLMatch))
        self.EXPECT_TRUE(notMatches(self.MkStr("MyX x; f(x);"), ADLMatch))
        self.EXPECT_TRUE(notMatches(self.MkStr("NS::X x; using NS::f; f(x);"), ADLMatch))

        #Operator call expressions
        self.EXPECT_TRUE(matches(self.MkStr("NS::X x; x + x;"), ADLMatch))
        self.EXPECT_TRUE(matches(self.MkStr("NS::X x; x + x;"), ADLMatchOper))
        self.EXPECT_TRUE(notMatches(self.MkStr("MyX x; x + x;"), ADLMatch))
        self.EXPECT_TRUE(notMatches(self.MkStr("MyX x; x + x;"), ADLMatchOper))
        self.EXPECT_TRUE(matches(self.MkStr("NS::X x; operator+(x, x);"), ADLMatch))
        self.EXPECT_TRUE(notMatches(self.MkStr("NS::X x; NS::operator+(x, x);"), ADLMatch))

    def test_translationUnitDecl(self):
        Code = "int MyVar1;\n" \
                "namespace NameSpace {\n"\
                "int MyVar2;\n"\
                "}  // namespace NameSpace\n"
        
        self.EXPECT_TRUE(matches(Code, varDecl(hasName("MyVar1"), hasDeclContext(translationUnitDecl()))))
        self.EXPECT_FALSE(matches(Code, varDecl(hasName("MyVar2"), hasDeclContext(translationUnitDecl()))))
        self.EXPECT_TRUE(matches(Code, varDecl(hasName("MyVar2"), hasDeclContext(decl(hasDeclContext(translationUnitDecl()))))))

if __name__ == '__main__':
    #suite = unittest.TestLoader().loadTestsFromTestCase(TestMatchers)
    #unittest.TextTestRunner(verbosity=2).run(suite)

    suite = unittest.TestLoader().loadTestsFromTestCase(ASTMatchersNodeTest)
    unittest.TextTestRunner(verbosity=2).run(suite)
