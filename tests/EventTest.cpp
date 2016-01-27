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

TEST(EventBusTest, CallbackTest) {
  bool action = false;
  
  EventBus& eventBus = EventBus::GetEventBus();
  Listener listener( [&action] (Event& e) { action = true; } );
  eventBus.Subscribe("test-event", listener);
  EXPECT_EQ(false, action);
  eventBus.Poll("test-event", Event{});
  EXPECT_EQ(false, action);
  eventBus.NotifyAll();
  EXPECT_EQ(true, action);
}

TEST(EventBusTest, MultipleExecutions) {
  bool action = false;
  
  EventBus& eventBus = EventBus::GetEventBus();
  Listener listener( [&action] (Event& e) { action = true; } );
  
  eventBus.Subscribe("test-event", listener);
  EXPECT_EQ(false, action);
  
  eventBus.Poll("test-event", Event{});
  EXPECT_EQ(false, action);
  
  eventBus.NotifyAll();
  EXPECT_EQ(true, action);
  action = false;
  
  eventBus.NotifyAll();
  EXPECT_EQ(false, action);
}

TEST(EventBusTest, MultipleCallbacksAndExecutions) {
  int callbackExCount = 0;
  constexpr int CALLBACKS_COUNT = 10;
  
  EventBus& eventBus = EventBus::GetEventBus();
  Listener listener( [&callbackExCount] (Event& e) { callbackExCount++; } );
  
  for(int i = 0; i < CALLBACKS_COUNT; i++) {
    eventBus.Subscribe("test-event", listener);
  }
  EXPECT_EQ(0, callbackExCount);
  
  eventBus.Poll("test-event", Event{});
   EXPECT_EQ(0, callbackExCount);
   
  eventBus.NotifyAll();
  EXPECT_EQ(CALLBACKS_COUNT, callbackExCount);
  
  eventBus.NotifyAll();
  EXPECT_EQ(CALLBACKS_COUNT, callbackExCount);
  
  eventBus.Poll("test-event", Event{});
  EXPECT_EQ(CALLBACKS_COUNT, callbackExCount);
   
  eventBus.NotifyAll();
  EXPECT_EQ(2*CALLBACKS_COUNT, callbackExCount);
}

