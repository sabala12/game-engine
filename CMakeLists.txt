cmake_minimum_required(VERSION 3.3)
project(game_engine)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories("/usr/include/")
include_directories("/usr/local/include/")

link_directories("/usr/lib")
link_directories("/usr/lib/x86_64-linux-gnu")
link_directories("/usr/local/lib")

#SET(CLANG_FSANITIZE_FLAG "-fsanitize=undefined")
#SET(CLANG_DISABLE_UNUSED_FLAG "-Wno-unused-value")

#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CLANG_FSANITIZE_FLAG}" )
#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CLANG_DISABLE_UNUSED_FLAG}" )

#SET (CMAKE_CXX_COMPILER "/usr/bin/clang++-3.6")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

file(GLOB TARGET_SRC
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/constraints/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/communication/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/communication/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/communication/zmq/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/communication/zmq/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/components/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/components/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/features/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/features/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/graphics/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/graphics/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/io/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/io/*.cpp"
)

add_library(${PROJECT_NAME} SHARED ${TARGET_SRC})
target_link_libraries(${PROJECT_NAME} libSDL2.so libglut.so libGL.so libGLU.so libGLEW.so libzmq.so)
set_target_properties(${PROJECT_NAME} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})

#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
#set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/../../${CMAKE_BUILD_TYPE})
#set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/../../${CMAKE_BUILD_TYPE})