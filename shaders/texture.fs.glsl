#version 130

in vec2 vCoordTexture;
in vec3 vPosition;
in vec3 vNormal;

uniform sampler2D uTexture;

out vec3 fFragColor;


void main() {


	//fFragColor  = normalize(vNormal);

	vec4 color = texture(uTexture, vCoordTexture);
	fFragColor = color.rgb;

}
