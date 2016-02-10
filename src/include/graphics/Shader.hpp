#pragma once

#include <string>

#include <GL/glew.h>

#include "app/Resources.hpp"

using namespace std;

using namespace s_engine::app;

namespace s_engine {
namespace graphics {

//using namespace app;

class Shader: public Resource {
protected:
    string vertexSource;
    string fragmentSource;
    GLuint vertexShaderId;
    GLuint fragmentShaderId;
    GLuint shaderProgramId;
public:
    Shader(const string& _fragmentSource, const string& _vertexSource);
    
    void Use();
};


}
}
