#include <gtest/gtest.h>

#include <string>

#include "app/Resources.hpp"
#include "graphics/Model.hpp"

using namespace std;
using namespace s_engine::graphics;
using namespace s_engine::app;

TEST( ResourcesTest, StoreModelPointer) {
  Model* model = new Model;
  
  s_engine::app::Resources::R().AddModel(model, 1);
  const Model* storedModel = s_engine::app::Resources::R().GetModel(1);
  
  ASSERT_EQ(model, storedModel);
  
  delete model;
}

TEST ( ResourcesTest, NonLazyLoad) {
    Model* model = new Model;
    
    constexpr int id = 1;
    Resources::R().AddModel(model, id, LOAD_ON_CREATION, false);
    const Resource* storedModelNonLazy = Resources::R().GetNonLazyResource(Resources::MODEL, id);
    EXPECT_EQ(nullptr,storedModelNonLazy );
    
    const Resource* storedModelLazy = Resources::R().GetResource(Resources::MODEL, id);
    ASSERT_EQ(model, storedModelLazy);
    
    const Resource* storedNonLazyLoadAfterLazy = Resources::R().GetNonLazyResource(Resources::MODEL, id);
    EXPECT_EQ(model, storedNonLazyLoadAfterLazy);
    
    delete model;
}