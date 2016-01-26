#include <gtest/gtest.h>

#include <app/EventBus.hpp>
#include <app/Listener.hpp>
#include <app/Events.hpp>

#include <iostream>

using namespace s_engine::app;
using namespace std;

TEST(ListenerTest, LambdaCallback) {
  bool action = false;
  Listener listener ( [&action](Event& e) {action = true; } );
  listener.OnAction(Event{});
  ASSERT_EQ(true, action);
}