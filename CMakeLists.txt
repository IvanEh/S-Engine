cmake_minimum_required(VERSION 2.8)

project(s-engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})

set ( SOURCE_DIR src)
set ( INCLUDE_DIR "${SOURCE_DIR}/include")
set ( EXT_DIR "external")
file ( GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/*.cpp")

include_directories(${INCLUDE_DIR})
add_executable(${PROJECT_NAME} ${SOURCE_FILES} )

install(TARGETS s-engine RUNTIME DESTINATION bin)

target_link_libraries(${PROJECT_NAME} 
  ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES}
  Xxf86vm pthread Xrandr Xinerama Xi Xcursor dl
  ${X11_LIBRARIES})
