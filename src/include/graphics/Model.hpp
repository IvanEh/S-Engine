#pragma once

#include <vector>

#include "Units.hpp"

using namespace std;

namespace s_engine {
namespace graphics {

// TODO: shared buffers
/**
 * A Model object represents a 3d object in normalized coordinate system.
 * It could be loaded up to the GPU.
 * Manipulations availiable only on not loaded(to the GPU) models.
 */
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