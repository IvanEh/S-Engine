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


TEST ( ResourcesTest, EfficientMetadataNonLazy) {
    Resources::DEBUG_DESTROY();
    
    constexpr int id = 1;
    Model localModel;
    
    Resources::R().AddModel(&localModel, id);
    
    auto meta = Resources::R().GetNonLazyResMetadataPtr(Resources::MODEL, 1);
    ASSERT_TRUE(meta);
    if(meta) {
        EXPECT_EQ(&localModel, meta->res);
    }
}

TEST ( ResourcesTest, NonLazyLoad_OnLoadedModel) {
    Resources::DEBUG_DESTROY();
    
    Model* model = new Model;
    
    constexpr int id = 1;
    Resources::R().AddModel(model, id, LOAD_ON_CREATION, false);
    const Resource* storedModelNonLazy = Resources::R().GetNonLazyResource(Resources::MODEL, id);
    EXPECT_EQ(model,storedModelNonLazy );
    
    const Resource* storedModelLazy = Resources::R().GetResource(Resources::MODEL, id);
    ASSERT_EQ(model, storedModelLazy);
    
    const Resource* storedNonLazyLoadAfterLazy = Resources::R().GetNonLazyResource(Resources::MODEL, id);
    EXPECT_EQ(model, storedNonLazyLoadAfterLazy);
    
    delete model;
}