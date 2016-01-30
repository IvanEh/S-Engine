#include <gtest/gtest.h>

#include "app/Resources.hpp"
#include "graphics/Model.hpp"

using namespace std;
using namespace s_engine::graphics;

TEST( ResourcesTest, StoreModelPointer) {
  Model* model = new Model;
  
  s_engine::app::Resources::R().LoadModel(model, 1);
  const Model* storedModel = s_engine::app::Resources::R().GetModel(1);
  
  ASSERT_EQ(storedModel, model);
  
  delete model;
}