#pragma once

#include <GL/glew.h>

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