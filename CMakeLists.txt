cmake_minimum_required(VERSION 2.8)

project(s-engine)

###############################################################################
#	Project values
###############################################################################


set ( SOURCE_DIR src)
set ( TEST_DIR tests)
set ( COMMON_INCLUDE_DIR "${SOURCE_DIR}/include")
set ( EXT_DIR "external")
set ( PROJECT_SANDBOX_DIR sandbox)
set ( PROJECT_SANDBOX_TARGET sandbox)

file ( GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/*.cpp")
file ( GLOB_RECURSE TEST_FILES "${TEST_DIR}/*.cpp")
file ( GLOB_RECURSE SANDBOX_FILES "${PROJECT_SANDBOX_DIR}/*.cpp")

#	

set ( GTEST_DIR ${EXT_DIR}/googletest)

# forward decleration

set ( LIBS dummy )
set ( TESTS_TARGET dummy )
set ( TESTS_LIBS dummy)
###############################################################################
#	Compiler options
###############################################################################


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


###############################################################################
#	Dependecies
###############################################################################


find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})

set ( LIBS ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES}
  Xxf86vm pthread Xrandr Xinerama Xi Xcursor dl
  ${X11_LIBRARIES}
)

###############################################################################
#	Project set up
###############################################################################


include_directories(${COMMON_INCLUDE_DIR})
add_library( ${PROJECT_NAME} ${SOURCE_FILES})


###############################################################################
#	Google unit tests
###############################################################################


add_subdirectory ( ${GTEST_DIR})
include_directories( ${GTEST_DIR}/googletest/include)
set ( TESTS_TARGET tests )
set ( TESTS_LIBS gtest gmock_main)


###############################################################################
#	Targets
###############################################################################


add_executable ( ${TESTS_TARGET} ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(${TESTS_TARGET} ${LIBS}
    ${TESTS_LIBS} ${PROJECT_NAME} )  

add_executable(${PROJECT_SANDBOX_TARGET} ${SANDBOX_FILES})
target_link_libraries(${PROJECT_SANDBOX_TARGET} 
  ${LIBS} ${TESTS_LIBS} ${PROJECT_NAME})
  
