from libtooling import *

def call_finder_cb(match, rewriter):
    print("function call {} at: {}".format(match.name, match.location.line))
    rewriter.append(match.location, "_blub")
    
def int_finder_cb(match, rewriter):
    print("integer {} at: {}".format(match.name, match.location.line)) 

def heee(v):
    print("huhuu {}".format(v))

def fn_finder_cb(match, id):
    print(id + ": fn at ")

#call_finder = callExpr()
#call_finder.bind(heee)

#parameterCountIs(0)
#parameterCountIs(1)

#int_finder = varDecl(hasType(isInteger()))
#int_finder.bind(int_finder)

tooling = Tooling("../tests/simple.cc")

fn_finder = functionDecl(hasName("print")).bind("fdg")
tooling.add(fn_finder, fn_finder_cb)

#hub1("hub1")
#hub2("hub2")
#hub3("hub3")

#tooling.add(intFinder)
#tooling.add(call_finder)

tooling.run()
#tooling.write_file("new.cc")
