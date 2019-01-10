#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include "camera.hpp"

using namespace glimac;

/// Class TrackballCamera derived from camera
class TrackballCamera :public Camera
{
public:

	/// Default constructor TrackballCameracamera
	TrackballCamera():
		m_fDistance(0),m_fAngleX(0),m_fAngleY(0)
	{}

	/// Constructor with parameters
	TrackballCamera(const float fDistance,const float fAngleX,const float fAngleY)
		:m_fDistance(fDistance),m_fAngleX(fAngleX),m_fAngleY(fAngleY)
	{}

	/// method which handle sdl keyboard event
	void onKeyboardEvent(const SDL_Event &event)
	{
		if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_r))
		{
			m_fAngleX = 0;
			m_fAngleY = 0;
		}
	}

/// method which handle sdl mouse wheel event
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

/// method which handle sdl mouse position event
	void onMouseEvent(const SDL_Event &e)
	{
		// Rotate UP
		m_fAngleY += e.motion.yrel;
		// Rotate LEFT
		m_fAngleX += e.motion.xrel;
	}

/// Method wich return a view Matrix set up with camera parameters
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
