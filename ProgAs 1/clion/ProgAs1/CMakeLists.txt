cmake_minimum_required(VERSION 3.3)
project(ProgAs1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES index.cc CIndex.cpp CIndex.h Word.cpp Word.h skiplist.cpp skiplist.h wordNode.cpp wordNode.h)
add_executable(ProgAs1 ${SOURCE_FILES})