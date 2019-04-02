import unittest
from libtooling import *

idx = 0
hasMatched = False

def callback(match, idx):
    global hasMatched
    hasMatched = True

def matches(src, matcher):
    global idx
    global hasMatched
    hasMatched = False
    tooling = Tooling()
    tooling.add(matcher, callback)
    tooling.run_from_source(src)
    idx = idx + 1    
    return hasMatched

def notMatches(src, matcher):
    return matches(src, matcher) == False

class TestMatchers(unittest.TestCase):
    
    def test_MatchesVariousDecls(self):
        NamedX = namedDecl(hasName("X"))
        self.assertTrue(matches("void foo() { int X; }", functionDecl()))
        #self.assertTrue(matches("void foo() { int X; }", functionDecl().bind(".")))
        #self.assertTrue(matches("typedef int X;", NamedX))
        #self.assertTrue(matches("int X;", NamedX))
        #self.assertTrue(matches("class foo { virtual void X(); };", NamedX))
        #self.assertTrue(matches("void foo() try { } catch(int X) { }", NamedX))
        #self.assertTrue(matches("void foo() { int X; }", NamedX))
        #self.assertTrue(matches("namespace X { }", NamedX))
        #self.assertTrue(matches("enum X { A, B, C };", NamedX))
        #self.assertTrue(notMatches("#define X 1", NamedX))
   

if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestMatchers)
    unittest.TextTestRunner(verbosity=2).run(suite)