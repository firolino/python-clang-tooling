import unittest
from libtooling import *

hasMatched = False

def callback(nodes):
    global hasMatched
    hasMatched = True

def matches(src, matcher):
    global hasMatched
    hasMatched = False
    tooling = Tooling()
    tooling.add(matcher, callback)
    tooling.run_from_source(src)
    return hasMatched

def notMatches(src, matcher):
    return matches(src, matcher) == False

class TestMatchers(unittest.TestCase):
    
    def test_accessSpecDecl(self):
        self.assertTrue("class C { public: int i; };", accessSpecDecl())    
        self.assertTrue("class C { public: int i; };", accessSpecDecl(isPublic()))

    def test_addrLabelExpr(self):
       self.assertTrue(matches("void f() { FOO: ; void *ptr = &&FOO; goto *ptr; }", addrLabelExpr()))

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