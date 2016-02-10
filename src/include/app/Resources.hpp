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
    class Shader;
}
}



namespace s_engine {
namespace app {

using namespace s_engine::graphics;  

/**
 * This enumerated type used to define the point of loading the resource
 * into the GPU's memory
 */
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
public: /* types */
    using ResHolder = map<GLuint, ResInfo>;

    enum ResType {
        MODEL,
        SHADER,
    };
  
public: /* fields */
  static constexpr GLuint NONE = 0;
private:
  ResHolder models;
  ResHolder shaders;
  static Resources* instance;
public: /* functions */
    // GLuint LoadModel(string path, LoadPolicy loadPolicy = LAZY_LOAD, bool lazyInst = false, bool keepInMemory = true);
    
    /**
     * Adds a model asset loading rule
     */
    GLuint AddModel(string path, GLuint id, LoadPolicy loadPolicy = LAZY_LOAD, bool lazyInst = false, bool 
        keepInMemory = true); 
    
    /**
     * Adds a shader asset loading rule
     */
    GLuint AddShader( string path, GLuint id, LoadPolicy loadPolicy = LAZY_LOAD, bool lazyInst = false, bool 
        keepInMemory = true);
    
    /**
     * @deprecated
     */
    GLuint LoadModel( Model* model, GLuint id, LoadPolicy loadPolicy = LAZY_LOAD, bool 
        lazyInst = false, bool keepInMemory = true );
    
    /**
     * Loads all the resources that weren't lazily loaded before
     * This function usually takes a lot of time to execute
     */
    void LoadResources();
    
    /**
     * Try to acquire the resource. If the resource is not loaded then load it
     * and make an instance of it. Lazy model loaded if needed so it
     * could take a time to execute this method
     * @returns nullptr if the resource doesn't exist
     */
    const Resource* GetResource( Resources::ResType resType, GLuint id );
    
    /**
     * Returns already loaded resources
     */
    const Resource* GetNonLazyResource( Resources::ResType resType, GLuint id);
    
    const Model* GetModel(GLuint id);
    const Shader* GetShader(GLuint id);
        
    static Resources& R();
private:

};  


}
}


#include "graphics/Model.hpp"
#include "graphics/Shader.hpp"