cmake_minimum_required(VERSION 3.16)
project(starter_files)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

add_executable(compress compress.cpp binaryTree.cpp huffmanTree.cpp)
add_executable(decompress decompress.cpp binaryTree.cpp huffmanTree.cpp)
add_executable(main main.cpp)
