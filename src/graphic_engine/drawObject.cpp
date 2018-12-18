#include <GL/glew.h>
#include "drawObject.hpp"

void draw3DObject(GLuint vao, int vertexCount)
{
  glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES,0,vertexCount);
  glBindVertexArray(0);

}
