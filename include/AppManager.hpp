#include <GL/glew.h>
#include <iostream>
#include <glimac/common.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <GLFW/glfw3.h>
#include <string>

class AppManager
{
public:

  AppManager();
  int start(char** argv);



public:

  int m_width = 800;
  int m_height = 600;

  int m_score = 0;

};
