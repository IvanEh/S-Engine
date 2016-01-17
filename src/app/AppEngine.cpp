#include "headers/app/AppEngine.hpp"

#include <random>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include "headers/utils.hpp"

namespace s_engine {
namespace app {
 
AppEngine::AppEngine(int width, int height, int posX, int posY) {
  glfwInit();
  
  this->window = glfwCreateWindow(width, height, "Test", nullptr, nullptr);
  
  if(this->window == nullptr) {
      running = false;
  } else {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
    SetDimension(width, height);
    SetPos(posX, posY);
    
    running = true;
  }
   
  glfwMakeContextCurrent(this->window);
}
  
/**
 *	Functions and Methods
 */  
  
void AppEngine::Run() {
  bool success = this->OnCreate();
  
  this->currentTick = timems();
  while((this->is_running() && success) && !glfwWindowShouldClose(this->window) ) {
     glfwPollEvents();
     
     this->lastTick = this->currentTick;
     this->currentTick = timems();
     
     this->OnTick();
     
     glfwSwapBuffers(window);
  }
  
  this->OnStop(success);
}

void AppEngine::Pause() {
  this->running = false;
}

void AppEngine::Terminate() {
  this->Pause();
  
}



  
/**
 * Setters and Getters
 */

long AppEngine::GetTickDuration() {
  return (this->currentTick - this->currentTick);
}


void AppEngine::SetX(int x) {
  SetPos(x, this->y);
}

int AppEngine::GetX() {
  return this->x;
}

void AppEngine::SetY(int y) {
  SetPos(this->x, y);
}

int AppEngine::GetY() {
  return this->y;
}

void AppEngine::SetWidth(int width) {
  SetDimension(width, this->height);
}

int AppEngine::GetWidth() {
  return this->width;
}

void AppEngine::SetHeight(int height) {
  SetDimension(this->width, height);
}

int AppEngine::GetHeight() {
  return this->height;
}


void AppEngine::SetDimension(int width, int height) {
  if(width < 0 || height < 0) {
      return;
  }
   
   this->width = width;
   this->height = height;
   
   glfwSetWindowSize(this->window, this->width, this->height);
}


void AppEngine::SetPos(int x, int y) {
  /// TODO: fit in screen
  if(x < 0) {
    x = 0;
  }
  
  if(y < 0) {
    y = 0;
  }
  
  this->x = x;
  this->y = y;
  
  glfwSetWindowPos(this->window, this->x, this->y);
}

bool AppEngine::is_running() {
  return running;
}

bool AppEngine::OnCreate() {

}

void AppEngine::OnTick() {
  if(std::rand() % 1000 < 10) {
    this->SetPos(this->x + 1, this->y + 1);
  }
  
}

void AppEngine::OnStop(bool success) {

}


  
  
}
}