// Copyright Andrew Vaziri 2016
#ifndef INCLUDE_LINKED_LIST_H_
#define INCLUDE_LINKED_LIST_H_
#include <sstream>
#include <stdexcept>
#include <string>

namespace fund {
class Node {
  friend class LinkedList;
 public:
    explicit Node(int d);
 private:
    int data;
    Node* next;
};

class LinkedList {
 public:
    void deleteNode(int val);
    void appendToTail(int d);
    int peek();
    int pop();
    void push(int i);
    std::string toString();
    LinkedList();
    ~LinkedList();
 private:
    Node* head;
};
}  // namespace fund

#endif  // INCLUDE_LINKED_LIST_H_
