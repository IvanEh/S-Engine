#include "headers/app/EventBus.hpp"

#include <unordered_map>
#include <vector>
#include <string>

#include "headers/app/Events.hpp"
#include "headers/app/Listener.hpp"

using std::unordered_map;
using std::string;
using std::vector;

namespace s_engine {
namespace app {

  
EventBus::EventBus() {
}


EventBus& EventBus::GetEventBus() {
  if(EventBus::instance == nullptr) {
    EventBus::instance = new EventBus;
  }
  
  return *instance;
}
  
  
}
}