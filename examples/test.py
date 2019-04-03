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
