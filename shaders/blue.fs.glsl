#version 130

in vec2 vCoordTexture;
in vec3 vPosition;
in vec3 vNormal;


out vec3 fFragColor;


//uniform vec3 uColor;
//uniform sampler2D uTexture;

void main() {


	//fFragColor  = normalize(vNormal);


	fFragColor = vec3(0.06,0.18,0.29);

}
