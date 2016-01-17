#pragma once

#include <functional>

#include "headers/app/Events.hpp"

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
  virtual bool OnAction(Event& event) {};
};

}
}