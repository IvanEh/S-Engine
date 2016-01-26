#pragma once

#include "AppEngine.hpp"

namespace s_engine {
namespace app {

class Context {};  
  
class Event {
private:
  const Context* context = nullptr;
public:
  const Context* GetContext() const;
};


}
}