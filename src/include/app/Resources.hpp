#pragma once

#include <string>
#include <map>

#include "graphics/Model.hpp"

using namespace std;

namespace s_engine {
namespace app {


using namespace s_engine::graphics;  

enum ModelLoadPolicy {
 LOAD_ON_CREATION,
 LAZY_LOAD,
 MANUALLY
};



struct ModelRes {
  Model* model;
  string path;
  ModelLoadPolicy loadPolicy;
  bool lazyInst;
  bool keepInMemory;
};  

  
class Resources {
public: /* fields */
  static constexpr GLuint NONE = 0;
private:
  map<GLuint, ModelRes> models;
  
  static Resources* instance;
public:
    GLuint LoadModel(string path, ModelLoadPolicy loadPolicy = LAZY_LOAD, bool lazyInst = false, bool keepInMemory = true)
;
    GLuint LoadModel(string path, GLuint id, ModelLoadPolicy loadPolicy = LAZY_LOAD, bool lazyInst = false, bool 
        keepInMemory = true); 
    GLuint LoadModel( s_engine::graphics::Model* model, GLuint id, ModelLoadPolicy loadPolicy = LAZY_LOAD, bool 
        lazyInst = false, bool keepInMemory = true );
    
    const Model* GetModel(GLuint id);
    
    
    static Resources& R();
};
 
  
}
}
