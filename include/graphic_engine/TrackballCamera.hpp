#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include "camera.hpp"

using namespace glimac;

class TrackballCamera :public Camera
{
public:

	TrackballCamera():
		,m_fDistance(0),m_fAngleX(0),m_fAngleY(0)
	{}

	TrackballCamera(const float fDistance,const float fAngleX,const float fAngleY)
		:m_fDistance(fDistance),m_fAngleX(fAngleX),m_fAngleY(fAngleY)
	{}


// EVENT

	void onKeyboardEvent(const SDL_Event &event)
	{
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_r))
		{
			m_fAngleX = 0;
			m_fAngleY = 0;
		}
	}

	void onMouseWheelEvent(const SDL_Event &e)
	{
		if (e.button.button == SDL_BUTTON_WHEELUP)
		{
				// Move BACK
				m_fDistance+=0.1;
		}

		if (e.button.button == SDL_BUTTON_WHEELDOWN)
		{
			 // Move FRONT
				m_fDistance-=0.1;
		}
	}

	void onMouseEvent(const SDL_Event &e)
	{
		// Rotate UP
		m_fAngleY += e.motion.yrel;
		// Rotate LEFT
		m_fAngleX += e.motion.xrel;
	}


	glm::mat4 getViewMatrix() const
	{

	glm::mat4 viewMatrix(1.0f);

	viewMatrix = glm::rotate(viewMatrix,glm::radians(m_fAngleX),glm::vec3(0.0,1.0,0.0));
	viewMatrix *= glm::rotate(viewMatrix,glm::radians(m_fAngleY),glm::vec3(1.0,0.0,0.0));

	viewMatrix *= glm::translate(glm::mat4(1.0),glm::vec3(0,0,m_fDistance/5));

	return viewMatrix;
	}



private:
	float m_fDistance=0;
	float m_fAngleX=0;
	float m_fAngleY=0;


};
