#version 130


/*
layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec2 aTexCoord;
*/

in vec3 aVertexPosition;
in vec2 aTexCoord;

out vec2 vCoordTexture;
out vec2 vPosition;

uniform mat3 uModelMatrix;



void main() {

  vPosition = aVertexPosition;
  gl_Position = vec4((uModelMatrix*vec3(aVertexPosition, 1)).xy, 0, 1);
  vCoordTexture = aTexCoord;

}
