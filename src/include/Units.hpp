#pragma once

#include <GL/glew.h>
#include <glm/vec3.hpp>

/**
 * GLfloat is the default floating point type
 * In general all 'significant' and 'sensible variable' should be opengl types
 */


namespace s_engine {
namespace graphics {

struct Vertex {
  union { 
    struct {
      GLfloat x;
      GLfloat y;
      GLfloat z;
    } coords;
    
    struct {
      GLfloat x;
      GLfloat y;
      GLfloat z;
    };
  };
  
  union { 
    struct {
      GLfloat x;
      GLfloat y;
      GLfloat z;
    } normal;
    
    struct {
      GLfloat nx;
      GLfloat ny;
      GLfloat nz;
    };
  };
  
  union { 
    struct {
      GLfloat x;
      GLfloat y;
    } texture;
    
    struct {
      GLfloat tx;
      GLfloat ty;
    };
  };
  
  static void SetUpVAO(GLuint& VAO);
};

};
};