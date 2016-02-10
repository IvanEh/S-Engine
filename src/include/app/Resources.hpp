#pragma once

#include <string>
#include <map>

#include "Units.hpp"

using namespace std;

namespace s_engine {
namespace app {

 /**
 * A marker class
 */
class Resource {
public:
    virtual void Load() =0;
    virtual void Unload() =0;

};


}

namespace graphics {
    class Model;   
}
}



namespace s_engine {
namespace app {

using namespace s_engine::graphics;  

enum LoadPolicy {
 LOAD_ON_CREATION,
 LAZY_LOAD,
 MANUALLY
};
 
struct ResInfo {
  Resource* res;
  string path;
  LoadPolicy loadPolicy;
  /**
   * Defines when to create an instance of particular resource
   * if true  - load only when the resource is queried first time by the user
   *    false - load when LoadResources is called
   */
  bool lazyInst;
  /**
   * Keep in memory after loading into the gpu
   */
  bool keepInMemory;
}; 

class Resources {
public: /* fields */
  static constexpr GLuint NONE = 0;
private:
  map<GLuint, ResInfo> models;
  map<GLuint, ResInfo> shaders;
  
  static Resources* instance;
public:
    // GLuint LoadModel(string path, LoadPolicy loadPolicy = LAZY_LOAD, bool lazyInst = false, bool keepInMemory = true);
    GLuint LoadShader(string path, LoadPolicy loadPolicy = LAZY_LOAD, bool lazyInst = false, bool keepInMemory = true);
    
    GLuint LoadModel(string path, GLuint id, LoadPolicy loadPolicy = LAZY_LOAD, bool lazyInst = false, bool 
        keepInMemory = true); 
    GLuint LoadModel( s_engine::graphics::Model* model, GLuint id, LoadPolicy loadPolicy = LAZY_LOAD, bool 
        lazyInst = false, bool keepInMemory = true );
    GLuint LoadShader( string path, bool lazyInst = false, bool keepInMemory = true);
    
    void LoadResources();
    const Model* GetModel(GLuint id);
    const Model* GetNonLazyModel(GLuint id);
    
    
    static Resources& R();
};
 
  
}
}


#include "graphics/Model.hpp"
#include "graphics/Shader.hpp"