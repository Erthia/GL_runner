#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include <cmath>     

namespace glimac {


class FreelyCamera
{
public:

	FreelyCamera()
	{
		m_Position = ()
	};
	FreelyCamera(glm::vec3 _Position);




private:

	void computeDirectionVectors()
	{
		m_FrontVector[0] = cos(m_fTheta)*sin(m_fPhi);
		m_FrontVector[1] = sin(m_fTheta);
		m_FrontVector[2] = cos(m_fTheta)*cos(m_fPhi);

		m_LeftVector[0] = sin(m_fPhi +(M_PI/2));
		m_LeftVector[1] = 0;
		m_LeftVector[2] = cos(m_fPhi + (M_PI/2));

		m_UpVector = m_FrontVector * m_LeftVector;
	};

	glm::vec3 m_Position;
	glm::vec3 m_FrontVector;
	glm::vec3 m_LeftVector;
	glm::vec3 m_UpVector;

	float m_fPhi;
	float m_fTheta;


	


};

}


