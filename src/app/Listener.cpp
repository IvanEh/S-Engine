#include "headers/app/Listener.hpp"

namespace s_engine {
namespace app {
  
Listener::Listener(Action& action) {
  this->action = action;
}

Listener::Listener(Action* action) {
  this->action = *action;
}

Listener::Listener() {
 this->action = Action();
}
  

void Listener::OnAction(Event& event)
{
  this->action(event);
  
}

}
}