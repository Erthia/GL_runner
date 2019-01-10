#version 130

in vec3 vPosition;
in vec3 vNormal;


out vec3 fFragColor;


uniform vec3 uColor;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;

uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;

vec3 blinnPhong()
{
	vec3 color;
	color = (uLightIntensity * (uKd*(dot(uLightDir_vs,vNormal))+
	uKs*(pow(dot(normalize((-vPosition)+uLightDir_vs)/2,vNormal),uShininess)))) ;

	return color;
}

void main() {

	fFragColor =   vec3(0.65,0.50,1.0)* blinnPhong();
}
