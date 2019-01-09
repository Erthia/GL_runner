
#version 130

in vec3 aVertexPosition;


uniform mat4 uMVPMatrix;
uniform mat4 uNormalMatrix;

out vec3 vCoordTexture;


void main() {

	vec4 vertexPosition = uMVPMatrix *vec4(aVertexPosition, 1);
	gl_Position =  vertexPosition.xyww;
	vCoordTexture = aVertexPosition;
}
