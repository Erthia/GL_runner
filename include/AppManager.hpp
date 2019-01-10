#include <GL/glew.h>
#include <iostream>
#include <glimac/common.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <string>

/// AppManager Class manage all the Game
/// Create all the game elements
class AppManager
{
public:

  /// Default Constructor of class AppManager
  AppManager();

  /// Getter for the window name
  inline const std::string getWindowName() const {
  	return m_window_name;
  }

  /// Getter for the window's width
    inline const int getAppWidth() const {
  	return m_width;
  }

  /// Getter for the window's height
      inline const int getAppHeight() const {
  	return m_height;
  }

  /// method which launch the application
  int start(char** argv);

public:

  std::string m_window_name;
  
  int m_width = 800;
  int m_height = 600;
  int m_score = 0;

};
