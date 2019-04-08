cmake_minimum_required(VERSION 2.8)

find_package(LLVM REQUIRED)
find_package(Clang REQUIRED)
FIND_PACKAGE(Boost COMPONENTS system python3)
FIND_PACKAGE(PythonInterp 3)
FIND_PACKAGE(PythonLibs 3 REQUIRED)
message(" ........ ${PYTHON_VERSION} ...........")
find_package(Python 3 REQUIRED COMPONENTS Interpreter Development)

#set(CMAKE_CXX_FLAGS "-Wall -g3 -O0 -fno-rtti ${LLVM_COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS "-Wall -g3 -O0 ${LLVM_COMPILE_FLAGS} -fexceptions -std=c++17")
#set_source_files_properties(foo.cpp PROPERTIES COMPILE_FLAGS -Wno-effc++)

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${CLANG_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PYTHON_INCLUDE_DIRS})

set(CLANG_TOOL_SRC
        main.cc
        tooling/tooling.cc
        utils/utils.cc
        actions/frontendaction.cc
        consumer/consumer.cc
)

# remove trailing whitespaces
string(STRIP ${LLVM_LDFLAGS} LLVM_LDFLAGS)

add_library(libtooling SHARED ${CLANG_TOOL_SRC})
target_link_libraries(libtooling ${CLANG_LIBS} ${LLVM_LIBS_CORE} ${LLVM_LDFLAGS} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

# Copy the __init__.py file
configure_file(__init__.py ${CMAKE_CURRENT_BINARY_DIR}/__init__.py COPYONLY)

# Suppress prefix "lib" because Python does not allow this prefix
set_target_properties(libtooling PROPERTIES PREFIX "")
#message("-------------- ${Python_SITEARCH} ---------  \n" ${Python_SITELIB})
install(TARGETS libtooling DESTINATION "/home/fkasmis/.local/lib/python3.7/site-packages")

