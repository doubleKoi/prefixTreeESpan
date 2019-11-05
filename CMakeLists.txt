cmake_minimum_required(VERSION 3.15)
project(prefixTreeESpan)

set(CMAKE_CXX_STANDARD 14)

add_executable(prefixTreeESpan main.cpp src/TreeNode.cpp include/TreeNode.h src/GrowElem.cpp include/GrowElem.h src/PreTree.cpp include/PreTree.h src/ProjDB.cpp include/ProjDB.h src/ProjInst.cpp include/ProjInst.h src/Tree.cpp include/Tree.h)