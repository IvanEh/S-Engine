#include "app/EventBus.hpp"

#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <map>

#include "app/Events.hpp"
#include "app/Listener.hpp"

using std::unordered_map;
using std::unordered_multimap;
using std::string;
using std::vector;
using std::map;

namespace s_engine {
namespace app {

EventBus* EventBus::instance = nullptr;
  

EventBus::EventBus() {
}


void EventBus::Subscribe(string eventKey, Listener listener) {
  if(this->listeners.count(eventKey) <= 0 ){
      this->listeners[eventKey] = vector<Listener>();
  }
  
  this->listeners[eventKey].push_back(listener);
}


void EventBus::Poll(string eventKey, Event event) {
  if(this->eventQueue.count(eventKey) <= 0) {
    this->eventQueue[eventKey] = vector<Event>();
  }
  
  this->eventQueue[eventKey].push_back(event);
}


void EventBus::NotifyAll() {
  for(auto it = this->eventQueue.begin(); it != this->eventQueue.end(); ++it) {
      string eventKey = it->first;
      vector<Event>& events = it->second;
      
      for(int i = 0; i < events.size(); i++) {
	Event& event = events[i];
	vector<Listener>& listeners = this->listeners[eventKey];
	
	for(int j = 0; j < listeners.size(); j++) {
	  listeners[j].OnAction(event);
	}	
	
      }
      
  }
}


EventBus& EventBus::GetEventBus() {
  if(EventBus::instance == nullptr) {
    EventBus::instance = new EventBus;
  }
  
  return *instance;
}
  
  
}
}