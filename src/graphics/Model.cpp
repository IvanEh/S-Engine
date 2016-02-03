#include "graphics/Model.hpp"

#include <GL/glew.h>
#include <GL/gl.h>

#include "Units.hpp"

namespace s_engine {
namespace graphics {

Model::Model() {

}



void Model::Load() {
  if(this->loaded) {
    // Unload first
      return;
  }
  
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(Vertex), &(vertices[0].x), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  
  Vertex::SetUpVAO(VAO);
  
  this->loaded = true;

  if(!this->keepInMemory) {
      this->vertices.resize(0);
  }
}


bool Model::is_loaded() const {
  return loaded;
}



vector< Vertex >* Model::GetVerticesPtr() {
  return &vertices;
}

}
}
