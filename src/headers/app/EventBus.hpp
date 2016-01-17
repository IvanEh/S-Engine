// #include <unordered_map>
// #include <vector>
// #include <string>
// 
// #include "Events.hpp"
// 
// using std::unordered_map;
// 
// namespace s_engine {
// namespace app {
// 
// class EventBus {
// private:
//   unordered_map<string, vector<Listener>> listeners; 
//   unordered_map<string, vector<Event>> eventQueue;
//   
//   static const EventBus& instance;
//   
//   EventBus();
// public:
//   
//   void Subscribe(string eventKey, Listener listener);
//   void Poll(string eventKey, Event event);
// };
// 
// }
// }