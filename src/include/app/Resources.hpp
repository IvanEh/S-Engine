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
private:
  map<unsigned int, ModelRes> models;
  
  static Resources* instance;
public:
    unsigned int LoadModel(string path, ModelLoadPolicy loadPolicy = LAZY_LOAD, bool lazyInst = false, bool keepInMemory = true);
    unsigned int LoadModel(string path, unsigned int id, ModelLoadPolicy loadPolicy = LAZY_LOAD, bool lazyInst = false, bool keepInMemory = true); 
    unsigned int LoadModel( s_engine::graphics::Model* model, unsigned int id, ModelLoadPolicy loadPolicy = LAZY_LOAD, bool lazyInst = false, bool keepInMemory = true );
    
    const Model* GetModel(unsigned int id);
    
    
    static Resources& R();
};
 


  
}
}
