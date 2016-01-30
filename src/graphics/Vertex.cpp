#include "graphics/Vertex.hpp"

namespace s_engine {
namespace graphics {

void Vertex::SetUpVAO ( GLuint& VAO ) {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    // coords attrib
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0); 
    
    // normal attrib
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3*sizeof(GLfloat)));
    glEnableVertexAttribArray(1);  
    
    // texture attrib
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(6*sizeof(GLfloat)));
    glEnableVertexAttribArray(2);  
    
    glBindVertexArray(0);
}

}
}
