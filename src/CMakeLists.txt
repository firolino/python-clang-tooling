cmake_minimum_required(VERSION 2.8)

find_package(LLVM REQUIRED)
find_package(Clang REQUIRED)
FIND_PACKAGE(Boost COMPONENTS system python3)
FIND_PACKAGE(PythonInterp 3)
FIND_PACKAGE(PythonLibs 3 REQUIRED)
find_package(Python 3 REQUIRED COMPONENTS Interpreter Development)
set(CMAKE_CXX_FLAGS "-Wall -g3 -O0 ${LLVM_COMPILE_FLAGS} -fexceptions -std=c++17")

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${CLANG_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PYTHON_INCLUDE_DIRS})

set(CLANG_TOOL_SRC
        main.cc
        node-matcher.cc
        bound-nodes.cc
        poly-matcher.cc
        wrapper-expose.cc
        tooling/tooling.cc
        utils/utils.cc
        actions/frontendaction.cc
        consumer/consumer.cc
)

# remove trailing whitespaces
string(STRIP ${LLVM_LDFLAGS} LLVM_LDFLAGS)

add_library(libtooling SHARED ${CLANG_TOOL_SRC})
target_link_libraries(libtooling ${CLANG_LIBS} ${LLVM_LIBS_CORE} ${LLVM_LDFLAGS} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

# Suppress prefix "lib" because Python does not allow this prefix
set_target_properties(libtooling PROPERTIES PREFIX "")
install(TARGETS libtooling DESTINATION "~/.local/lib/python3.7/site-packages")

