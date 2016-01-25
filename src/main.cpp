#include <iostream>
#include <unistd.h>
#include <unordered_map>

#include "headers/app/AppEngine.hpp"
#include "headers/utils.hpp"
#include "headers/app/Listener.hpp"
#include "headers/app/EventBus.hpp"

using namespace s_engine::app;
using namespace std;


int main(int argc, char **argv) {
  Listener listener;
  
   EventBus::GetEventBus().Subscribe("click", listener);
   EventBus::GetEventBus().NotifyAll();
   
  //AppEngine appEngine{100, 100, 1, 1};
  //appEngine.Run();
  
}
