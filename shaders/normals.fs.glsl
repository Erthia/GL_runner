#version 130

in vec2 vCoordTexture;
in vec3 vPosition;
in vec3 vNormal;


out vec3 fFragColor;


//uniform vec3 uColor;
//uniform sampler2D uTexture;

void main() {


	fFragColor  = normalize(vNormal)-vec3(0.8,0.7,0.1);


	//fFragColor = vec3(1.0,0.0,0.0);

}
