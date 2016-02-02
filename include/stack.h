// Copyright Andrew Vaziri 2016
#ifndef INCLUDE_STACK_H_
#define INCLUDE_STACK_H_
#include <string>
namespace fund {

class StackNode {
  friend class Stack;
 public:
  StackNode(int data);
  ~StackNode();
 private:
  int data;
  StackNode* next;
};

class Stack {
 public:
  Stack();
  ~Stack();
  int pop();
  void push(int val);
  int peek();
  bool isEmpty();
  std::string toString();
 private:
  StackNode* top;
};

}  // namespace fund
#endif  // INCLUDE_STACK_H_
