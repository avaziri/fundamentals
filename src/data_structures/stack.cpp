// Copyright Andrew Vaziri 2016
#include "../../include/stack.h"

#include <string>
#include <sstream>

namespace fund {

StackNode::StackNode(int d) {
  data = d;
  next = 0;
}

StackNode::~StackNode() {
}

Stack::Stack()
: top(0) {
}

Stack::~Stack() {
  while (top != 0) {
    StackNode* next = top->next;
    delete top;
    top = next;
  }
}

int Stack::pop() {
  if (top != 0) {
    int data = top->data;
    StackNode* next = top->next;
    delete top;
    top = next;
    return data;
  } else {
    throw 1337;
  }
}

void Stack::push(int val) {
  StackNode* new_top = new StackNode(val);
  new_top->next = top;
  top = new_top;
}

int Stack::peek() {
  if (top !=0) {
    return top->data;
  } else {
    throw 1337;  // Throw some error
  }
}

bool Stack::isEmpty() {
  if (top == 0) {
    return 1;
  } else {
    return 0;
  }
}


std::string Stack::toString() {
  std::stringstream ss;
  ss << "[";
  if (top != 0) {
    ss << top->data;
    StackNode* next = top->next;
    while (next != 0) {
      ss << "," << next->data;
      next = next->next;
    }
  }
  ss << "]";
  return ss.str();
}

}  // namespace fund
