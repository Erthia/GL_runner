
#version 130

/*
layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aNormCord;
layout(location = 2) in vec2 aTexCoord;
*/

in vec3 aVertexPosition;
in vec3 aNormCord;
in vec2 aTexCoord;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;


out vec3 vPosition;
out vec3 vNormal;
out vec2 vCoordTexture;


void main() {

	vec4 vertexPosition = vec4(aVertexPosition, 1);
	vec4 vertexNormale = vec4(aNormCord, 0);

	vPosition= vec3(uMVMatrix * vertexPosition);
	vNormal = vec3(uMVMatrix * vertexNormale);
	vCoordTexture = aTexCoord;

	gl_Position = uMVPMatrix * vertexPosition;

}
