#include <app/Resources.hpp>
#include <GL/gl.h>

namespace s_engine {
namespace app {
 
    Resources* Resources::instance;
  
GLuint Resources::LoadModel ( string path, GLuint id, LoadPolicy loadPolicy, bool lazyInst, bool keepInMemory ) {
  if(this->models.count(id) != 0) {
    return 0;
  }
  
  if(id == 0) {
    return 0;
  }
  
  ResInfo res;
  res.res = nullptr;
  res.path = path;
  res.loadPolicy = loadPolicy;
  res.lazyInst = false;
  res.keepInMemory = keepInMemory;
  
  this->models[id] = res;
}
    
/**
 *@deprecated
 */    
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

const Resource* Resources::GetResource ( Resources::ResType resType, GLuint id ) {
    ResHolder* resHolder;
    switch(resType) {
        case MODEL:
            resHolder = &this->models;
            break;
        case SHADER:
            resHolder = &this->shaders;
            break;
        default:
            return nullptr;
    }
    
    auto it = resHolder->find(id);
    if(it ==  resHolder->end() ) {
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
    
    return res.res;
}

// TODO: extract mutual part
const Resource* Resources::GetNonLazyResource (ResType resType, GLuint id ) {
    ResHolder* resHolder;
    switch(resType) {
        case MODEL:
            resHolder = &this->models;
            break;
        case SHADER:
            resHolder = &this->shaders;
            break;
        default:
            return nullptr;
    }
    
    auto it = resHolder->find(id);
    if(it ==  resHolder->end() ) {
    return nullptr;
    }
    
    ResInfo res = (*it).second;
       
    if(res.loadPolicy == LAZY_LOAD ) {
      res.res->Load();
    }
    
    return res.res;
}


const graphics::Model* Resources::GetModel ( GLuint id ) {
    const Resource* res = GetResource(MODEL, id);
    const Model* model = dynamic_cast<const Model*> ( res );
    return model;
}

const graphics::Shader* Resources::GetShader ( GLuint id ) {
    const Resource* res = GetResource(SHADER, id);
    const Shader* shader = dynamic_cast<const Shader*> ( res );
    return shader;
}



  
Resources& Resources::R() {
  if(Resources::instance == nullptr) {
    Resources::instance = new Resources;
  } 
  
  return *Resources::instance;
    
}



  
}
}