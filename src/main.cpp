#include <iostream>
#include <unistd.h>

#include "headers/app/AppEngine.hpp"
#include "headers/utils.hpp"

using namespace s_engine::app;

int main(int argc, char **argv) {
  
 
  AppEngine appEngine{100, 100, 1, 1};
  appEngine.Run();
  
}
