#pragma once

#include "AppEngine.hpp"

namespace s_engine {
namespace app {

class Event {
private:
  const AppEngine* context;
public:
  const AppEngine* GetContext() const;
};


}
}