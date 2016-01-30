#pragma once

#include <vector>

#include "graphics/Vertex.hpp"

using namespace std;

namespace s_engine {
namespace graphics {

// TODO: shared buffers
class Model {
private:
  vector<Vertex> vertices;
  bool loaded {false};
  bool keepInMemory {false};
  GLuint VBO;
  GLuint VAO;
public:
  Model();
  Model(Model& model) =delete;
  Model(Model&& model) =delete;
  
  void Load();
  void Unload();
  bool is_loaded() const;
  vector<Vertex>* GetVerticesPtr(); 
};

}
}