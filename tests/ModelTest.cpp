#include <gtest/gtest.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics/Model.hpp"

using namespace s_engine::graphics;
using namespace std;




TEST(ModelTests, LoadingEmptyModel) {

  Model model;
  model.Load();
  
  ASSERT_TRUE(model.is_loaded());
}