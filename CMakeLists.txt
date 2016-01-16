cmake_minimum_required(VERSION 2.8)

project(s-engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set ( SOURCE_DIR src)
file ( GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILES} )

install(TARGETS s-engine RUNTIME DESTINATION bin)