#pragma once

#include <unordered_map>
#include <vector>
#include <string>

#include "headers/app/Events.hpp"
#include "headers/app/Listener.hpp"

using std::unordered_map;
using std::unordered_multimap;
using std::string;
using std::vector;

namespace s_engine {
namespace app {

//TODO: filters and criteria 
//	priorities
class EventBus {
private:
  unordered_map<string, vector<Listener>> listeners{}; 
  unordered_map<string, vector<Event>> eventQueue{};
  
  static EventBus* instance;
  
  EventBus();
  EventBus(const EventBus& ) = delete;
  EventBus(const EventBus&& ) = delete;
public:
  
  void Subscribe(string eventKey, Listener listener);
  void Poll(string eventKey, Event event);
  void NotifyAll();
  
  static EventBus& GetEventBus();
};

}
}