#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

namespace s_engine {
namespace app_engine {
  
/**
 * This class controlls the window and deals with events. 
 * It also serves as a container for other types of engine and
 * manages their lifecycle
 */
class AppEngine {
private:
  GLFWwindow* window; /// window instance. Should be hidden from the user
  int posX;
  int posY;
  int width;
  int height;
public:
  
  AppEngine(int width, int height, int posX = 0, int posY = 0);
    
/**
 *	Lifecycle callbacks
 */  
  bool OnCreate();
  void OnTick();
  void OnStop();

/**
 * 
 */

/**
 * 	Infinity loop
 */
  void Run();

/**
 * Setters and getters
 * (setters listed first)
 */

  void SetTickDuration();
  void GetTickDuration();
  
  void SetX(int x);
  int GetX();
  
  void SetY(int y);
  int GetY();
  
  void SetWidth(int width);
  int GetWidth();
  
  void SetHeight(int width);
  int GetHeight();
  
  void SetDimension(int width, int height);
  void SetPos(int x, int y);
    
  
private:
/**
 * 	Lifecycle functions
 */
  bool create();
  void tick();
  void stop();
  
  
};

}
}