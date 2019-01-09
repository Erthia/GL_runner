#version 130

in vec3 vCoordTexture;
out vec3 fFragColor;



uniform samplerCube skybox;

void main() {

	vec3 dataColor = texture(skybox, vCoordTexture).xyz;
	fFragColor = dataColor;

}
