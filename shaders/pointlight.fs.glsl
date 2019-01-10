#version 130

in vec3 vPosition;
in vec3 vNormal;


out vec3 fFragColor;


uniform vec3 uColor;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;

uniform vec3 uLightPos_vs;
uniform vec3 uLightIntensity;

vec3 blinnPhong()
{
	vec3 color;

	color = (
	(uLightIntensity / (distance(uLightPos_vs,vPosition) * distance(LightPos_vs,vPosition)))
	*(uKd*(dot((normalize(uLightPos_vs - vPosition)),vNormal))+
	uKs*(pow(dot(normalize((-vPosition)+(normalize(uLightPos_vs - vPosition)))/2,vNormal),uShininess))));

	return color;
}

void main() {

	fFragColor = blinnPhong();
};
