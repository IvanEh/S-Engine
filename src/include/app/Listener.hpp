#pragma once

#include <functional>
#include <utility>

#include "app/Events.hpp"


namespace s_engine {
namespace app {
  
using Action = std::function<void(Event&)>;

class Listener {
private:
  Action action;
  
public:
   Listener();
 Listener(Action* action);
 Listener(Action& action);
 virtual void OnAction(Event& event);
  
};


}
}
