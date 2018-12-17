#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>

namespace glimac {


class TrackballCamera
{
public:

	TrackballCamera();
	TrackballCamera(const float fDistance,const float fAngleX,const float fAngleY)
		:m_fDistance(fDistance),m_fAngleX(fAngleX),m_fAngleY(fAngleY)
	{}

	void moveFront(float delta)
	{
		if(delta>0)
			m_fDistance -= 0.1 ;
		else
			m_fDistance += 0.1;
	}

	void rotateLeft(float degrees)
	{
		m_fAngleY +=degrees;
	}

	void rotateUp(float degrees)
	{
		m_fAngleX+=degrees;
	}
	glm::mat4 getViewMatrix() const
	{
	glm::mat4 viewMatrix;
	
	viewMatrix = glm::rotate(viewMatrix,glm::radians(m_fAngleY),glm::vec3(0,0,1.0));
	viewMatrix *= glm::rotate(viewMatrix,glm::radians(m_fAngleX),glm::vec3(0.0,1.0,0));
	viewMatrix *= glm::translate(glm::mat4(1.0),glm::vec3(0,0,m_fDistance/5));

	return viewMatrix;
	}



private:
	float m_fDistance=5;
	float m_fAngleX=0;
	float m_fAngleY=0;


};

}


