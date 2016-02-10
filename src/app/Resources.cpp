#include <app/Resources.hpp>

#include <memory>

#include <GL/gl.h>

namespace s_engine {
namespace app {
 
    Resources* Resources::instance;
  
GLuint Resources::AddModel ( GLuint id, string path, LoadPolicy loadPolicy, bool lazyInst, bool keepInMemory ) {
  if(this->models.count(id) != 0) {
    return 0;
  }
  
  if(id == 0) {
    return 0;
  }
  
  ResMetadata res;
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
GLuint Resources::AddModel ( s_engine::graphics::Model* model, GLuint id, s_engine::app::LoadPolicy 
loadPolicy, bool lazyInst, bool keepInMemory ) {
  if(this->models.count(id) != 0) {
    return 0;
  }
  
  if(id == 0) {
    return 0;
  }
  
  ResMetadata res;
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
    
    ResMetadata res = (*it).second;
    
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
    
    ResMetadata res = (*it).second;
       
    if(res.loadPolicy == LAZY_LOAD ) {
      res.res->Load();
    }
    
    return res.res;
}

// FIXME: 
ResMetadata Resources::GetResMetadata ( Resources::ResType resType, GLuint id ) {
//     ResMetadata meta = GetNonLazyResMetadata(resType, id); 
//     
//     if(meta->loadPolicy == LAZY_LOAD ) {
//       if(meta->res != nullptr) {
//         meta->res->Load();
//       }
//     }
//     
//     return *meta;
}

ResMetadata Resources::GetNonLazyResMetadata ( Resources::ResType resType, GLuint id ) {
    auto resHolder = ResolveResHolder(resType);
    if(resHolder == nullptr) {
        // invalid state
        return ResMetadata { };
    }
    
    auto it = resHolder->find(id);
    if(it ==  resHolder->end() ) {
        // invalid state
        return ResMetadata { };
    }
    
    ResMetadata res = (*it).second;
    
    return res;
}

unique_ptr< ResMetadata > Resources::GetNonLazyResMetadataPtr 
                          ( Resources::ResType resType, GLuint id ) {
    unique_ptr<ResMetadata> metaPtr = nullptr;
    
    ResHolder* resHolder = ResolveResHolder(resType);
    if(resHolder == nullptr) {
        return nullptr;
    }
    
    auto it = resHolder->find(id);
    if(it == resHolder->end()) {
        return nullptr;
    }else {
        ResMetadata*  meta = new ResMetadata( (*it).second );
        metaPtr.reset(meta);
    }
    
    return metaPtr;
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


bool Resources::Exist ( Resources::ResType resType, GLuint id ) {
    ResHolder* resHolder = ResolveResHolder(resType);
    if(resHolder == nullptr) {
        return false;
    }
    
    if(resHolder->count(id) <= 0) {
        return false;
    }else {
        return true;
    }
}



  
Resources& Resources::R() {
  if(Resources::instance == nullptr) {
    Resources::instance = new Resources;
  } 
  
  return *Resources::instance;
    
}

///////////////////////////////////////////////////////////////////////////////
//    Private functions
///////////////////////////////////////////////////////////////////////////////

Resources::ResHolder* Resources::ResolveResHolder ( Resources::ResType resType ) {
    ResHolder* resHolder;
    switch(resType) {
        case MODEL:
            resHolder = &this->models;
            break;
        case SHADER:
            resHolder = &this->shaders;
            break;
        default:
            resHolder = nullptr;
    }
    
    return resHolder;
}



  
}
}