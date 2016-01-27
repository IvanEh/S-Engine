#include "app/EventBus.hpp"

#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <map>

#include "app/Events.hpp"
#include "app/Listener.hpp"

using namespace std;

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
    this->eventQueue[eventKey] = queue<Event>();
  }
  
  this->eventQueue[eventKey].push(event);
}


void EventBus::NotifyAll() {
  for(auto it = this->eventQueue.begin(); it != this->eventQueue.end(); ++it) {
      string eventKey = it->first;
      queue<Event>& events = it->second;
      
      for(int i = 0; i < events.size(); i++) {
	Event& event = events.front();
	vector<Listener>& listeners = this->listeners[eventKey];
	
	for(int j = 0; j < listeners.size(); j++) {
	  listeners[j].OnAction(event);
	}	
	
	events.pop();
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