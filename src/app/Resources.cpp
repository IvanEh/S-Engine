#include <app/Resources.hpp>

namespace s_engine {
namespace app {
 
    Resources* Resources::instance;
  
unsigned int Resources::LoadModel ( s_engine::graphics::Model* model, unsigned int id, bool lazyLoad, bool keepInMemory ) {
  if(this->models.count(id) != 0) {
    return 0;
  }
  
  if(id == 0) {
    return 0;
  }
  
  ModelRes res;
  res.model = model;
  res.path = "";
  res.lazyLoad = lazyLoad;
  res.lazyInst = false;
  res.keepInMemory = keepInMemory;
  
  this->models[id] = res;
} 

const Model* Resources::GetModel ( unsigned int id ) {
    auto it = models.find(id);
    if(it ==  models.end() ) {
	return nullptr;
    }
    
    return (*it).second.model;
}

  
Resources& Resources::R() {
  if(Resources::instance == nullptr) {
    Resources::instance = new Resources;
  } 
  
  return *Resources::instance;
    
}



  
}
}