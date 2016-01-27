#pragma once

#include <string>
#include <map>

#include <graphics/Model.hpp>

using namespace std;

namespace s_engine {
namespace app {

struct ModelRes {
  Model* model;
  string path;
  bool lazyLoad;
  bool lazyInst;
  bool keepInMemory;
};  
  
class Resources {
private:
  map<unsigned int, ModelRes> models;
  
  static Resources* instance;
public:
    unsigned int LoadModel(string path, bool lazyLoad = false, bool lazyInst = false, bool keepInMemory = true);
    unsigned int LoadModel(string path, unsigned int id, bool lazyLoad = false, bool lazyInst = false, bool keepInMemory = true); 
    unsigned int LoadModel(Model* model, unsigned int id);
    unsigned int LoadModel(Model* model);
    
    const Model* GetModel(unsigned int id);
    
    
    static Resources& R();
};
  
  
}
}
