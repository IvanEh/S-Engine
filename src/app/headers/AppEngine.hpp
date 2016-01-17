#pragma once

#include <ctime>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

namespace s_engine {
namespace app {
  
/**
 * This class controlls the window and deals with events. 
 * It also serves as a container for other types of engine and
 * manages their lifecycle
 */
class AppEngine {
private:
  GLFWwindow* window; /// window instance. Should be hidden from the user
  int x;
  int y;
  int width;
  int height;
  bool running;
  int lastTick;
  int currentTick;
public:
  
  AppEngine(int width, int height, int posX = 0, int posY = 0);
   

/**
 * 	Methods/Functions
 */

/**
 * 	Infinity loop
 */
  void Run();

/**
 *	Stop application main loop. Resources still loaded
 */  
  void Pause();
  
/**
 * 	Stop application and release resources
 */

  void Terminate();

/**
 * Setters and getters
 * (setters listed first)
 */

  long GetTickDuration();
  
  void SetX(int x);
  int GetX();
  
  void SetY(int y);
  int GetY();
  
  void SetWidth(int width);
  int GetWidth();
  
  void SetHeight(int height);
  int GetHeight();
  
  void SetDimension(int width, int height);
  void SetPos(int x, int y);
    
  bool is_running();
private:
/**
 *	Lifecycle callbacks
 */  

  bool OnCreate();
  void OnTick();
  void OnStop(bool success);
  
};

}
}