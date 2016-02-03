// Copyright Andrew Vaziri 2016
#ifndef INCLUDE_QUEUE_H_
#define INCLUDE_QUEUE_H_

#include <string>

namespace fund {
class QueueNode {
  friend class Queue;
 private:
  QueueNode* next;
  QueueNode* prev;
  int data;
  explicit QueueNode(int data);
};

class Queue {
 public:
  Queue();
  ~Queue();
  void add(int data);
  int remove();
  int peek();
  bool isEmpty();
  std::string toString();
 private:
  QueueNode* head;
  QueueNode* tail;
};
}  // namespace fund
#endif  // INCLUDE_QUEUE_H_
