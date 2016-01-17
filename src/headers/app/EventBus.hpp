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

class EventBus {
private:
  unordered_map<string, vector<Listener>> listeners; 
  unordered_map<string, vector<Event>> eventQueue;
  
  static const EventBus* instance;
  
  EventBus();
public:
  
  void Subscribe(string eventKey, Listener listener);
  void Poll(string eventKey, Event event);
  void NotifyAll();
  
  static EventBus& GetEventBus();
};

}
}