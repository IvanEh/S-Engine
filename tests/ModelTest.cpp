#include <gtest/gtest.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics/Model.hpp"

using namespace s_engine::graphics;
using namespace std;

bool InitOpengGlForTesting() {
    GLFWwindow* window;
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
         
    window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
	return false;
      
    }
    glfwMakeContextCurrent(window);
    
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
	return false;
      
    }
    glViewport(0, 0, 800, 600);  
    
    return true;
}


TEST(ModelTests, LoadingEmptyModel) {
  ASSERT_TRUE(InitOpengGlForTesting());

  Model model;
  model.Load();
  ASSERT_TRUE(model.is_loaded());
}