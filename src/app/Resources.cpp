#include <app/Resources.hpp>
#include <GL/gl.h>

namespace s_engine {
namespace app {
 
    Resources* Resources::instance;
  
GLuint Resources::LoadModel ( s_engine::graphics::Model* model, GLuint id, s_engine::app::LoadPolicy 
loadPolicy, bool lazyInst, bool keepInMemory ) {
  if(this->models.count(id) != 0) {
    return 0;
  }
  
  if(id == 0) {
    return 0;
  }
  
  ResInfo res;
  res.res = model;
  res.path = "";
  res.loadPolicy = loadPolicy;
  res.lazyInst = false;
  res.keepInMemory = keepInMemory;
  
  this->models[id] = res;
} 

const Model* Resources::GetModel ( GLuint id ) {
    auto it = models.find(id);
    if(it ==  models.end() ) {
	return nullptr;
    }
    
    ResInfo res = (*it).second;
    
    if(res.lazyInst) {
      if(res.res == nullptr) {
	// TODO lazy inst 
      }
       
      if(res.loadPolicy == LOAD_ON_CREATION ) {
	  res.res->Load();
      }
    }else {
        
    }
    
    if(res.loadPolicy == LAZY_LOAD ) {
      res.res->Load();
    }
    
}




  
Resources& Resources::R() {
  if(Resources::instance == nullptr) {
    Resources::instance = new Resources;
  } 
  
  return *Resources::instance;
    
}



  
}
}