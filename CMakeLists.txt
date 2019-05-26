cmake_minimum_required(VERSION 3.8)
 
project(ParserREDP)

set(CMAKE_CXX_STANDARD 11)
  
include_directories(
        ${PROJECT_BINARY_DIR}/include
        ${PROJECT_SOURCE_DIR}/
)

enable_testing()
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bins)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/libs)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__CMAKE_FILE__='\"$(notdir $(abspath $<))\"'")
add_subdirectory(src)

