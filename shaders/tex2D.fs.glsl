#version 130

in vec2 vCoordTexture;

uniform vec3 uColor;
uniform sampler2D uTexture;

void main() {

	vec4 dataColor = texture(uTexture, vCoordTexture);
	fFragColor = dataColor;

}
