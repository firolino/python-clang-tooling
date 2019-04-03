from libtooling import *

def fn_finder_cb(nodes):
    print("#")
    if nodes.getFunctionDecl("0"):
        print("saywhoo function found")
    if nodes.getFunctionDecl("1"):
        print("print function found")

def int_finder_cb(nodes):
    print("=")
    if nodes.getVarDecl("int"):
        print("integer found")

def regi_cb(nodes):
    print("in regi cb")

fn_finder1 = functionDecl(hasName("saywhoo")).bind("0")
fn_finder2 = functionDecl(hasName("print")).bind("1")

int_finder = varDecl(hasType(isInteger())).bind("int")
regi = namedDecl(matchesName("::X"))

tooling = Tooling("../tests/simple.cc")

#tooling.add(fn_finder1, fn_finder_cb)
#tooling.add(fn_finder2, fn_finder_cb)
#tooling.add(int_finder, int_finder_cb)
tooling.add(regi, regi_cb)

tooling.run()



