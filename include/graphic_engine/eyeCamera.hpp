#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include "camera.hpp"

using namespace glimac;

/// Class EyeCamera
/// Camera which allow to see by the eyes of the player
class EyeCamera :public Camera
{
public:

	/// Default constructor
	EyeCamera():
		m_fDistance(2),m_fAngleX(0),m_fAngleY(0)
	{}

	/// constructor with parameters
	EyeCamera(const float fDistance,const float fAngleX,const float fAngleY)
		:m_fDistance(fDistance),m_fAngleX(fAngleX),m_fAngleY(fAngleY)
	{}

	/// method handling SDL keyboard event
	void onKeyboardEvent(const SDL_Event &event)
	{
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_r))
		{
			m_fAngleX = 0;
			m_fAngleY = 0;
		}
	}


	/// method handling SDL mouse wheel event
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
			 if (m_fDistance>2)
			 {
				 m_fDistance-=0.1;
			 }

		}
	}

	/// method handling mouse movement event
	void onMouseEvent(const SDL_Event &e)
	{
		// Rotate UP
			m_fAngleY += e.motion.yrel;
			if (m_fAngleY>0)
				m_fAngleY = 0;
			if (m_fAngleY<5)
				m_fAngleY = 5;
		// Rotate LEFT
			m_fAngleX += e.motion.xrel;
			if (m_fAngleX>80)
				m_fAngleX = 80;
			if (m_fAngleX<-80)
				m_fAngleX = -80;
	}

	/// method which return a viewMatrix create with camera set up
	glm::mat4 getViewMatrix() const
	{

	glm::mat4 viewMatrix(1.0f);

	viewMatrix = glm::translate(glm::mat4(1.0),glm::vec3(0,0,m_fDistance));
	viewMatrix *= glm::rotate(viewMatrix,glm::radians(m_fAngleY),glm::vec3(1.0,0.0,0.0));

	viewMatrix *= glm::rotate(viewMatrix,glm::radians(m_fAngleX),glm::vec3(0.0,1.0,0.0));

	return viewMatrix;
	}






private:
	float m_fDistance;
	float m_fAngleX;
	float m_fAngleY;


};
