cmake_minimum_required(VERSION 2.8)

project(s-engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})

set ( PROJECT_LIB ${PROJECT_NAME}_lib )
set ( PROJECT_SANDBOX_DIR sandbox)
set ( SOURCE_DIR src)
set ( TEST_DIR tests)
set ( INCLUDE_DIR "${SOURCE_DIR}/include")
set ( EXT_DIR "external")
file ( GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/*.cpp")
file ( GLOB_RECURSE TEST_FILES "${TEST_DIR}/*.cpp")

include_directories(${INCLUDE_DIR})

add_library( ${PROJECT_LIB} ${SOURCE_FILES})

#
#	GTEST
#
set ( GTEST_DIR ${EXT_DIR}/googletest)
add_subdirectory ( ${GTEST_DIR})
include_directories( ${GTEST_DIR}/googletest/include)



########################################################

add_executable ( test ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(test
  ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES}
  Xxf86vm pthread Xrandr Xinerama Xi Xcursor dl
  ${X11_LIBRARIES} gtest gmock_main ${PROJECT_LIB})  

add_executable(qbla ${PROJECT_SANDBOX_DIR}/main.cpp)
target_link_libraries(qbla
  ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES}
  Xxf86vm pthread Xrandr Xinerama Xi Xcursor dl
  ${X11_LIBRARIES} gtest gmock_main ${PROJECT_LIB})
  

