#include <GL/glew.h>
#include <iostream>
#include <glimac/common.hpp>
#include <glimac/SDLWindowManager.hpp>
//#include <GLFW/glfw3.h>
#include <string>

class AppManager
{
public:

  AppManager();
  int start(char** argv);

  inline int getAppWidth() const {
  	return m_width;
  }

  inline int getAppHeight() const {
  	return m_height;
  }
  inline std::string getWindowName() const {
  	return m_window_name;
  }


private:

  int m_width = 800;
  int m_height = 600;
  std::string m_window_name = "GLrunner";
  
};
