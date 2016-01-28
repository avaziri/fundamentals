// Copyright Andrew Vaziri 2016
#include <string>
#include "../../include/linked_list.h"

namespace fund {

Node::Node(int d) {
  data = d;
  next = 0;  // Initialize as null pointer
}

LinkedList::LinkedList()
  : head(0) {
}

void LinkedList::appendToTail(int d) {
  Node* tail = new Node(d);
  Node* n = head;
  if (n != 0) {  // Do not attempt to access null head
    while (n->next != 0) {
      n = n->next;
    }
    n->next = tail;
  } else {
    head = tail;
  }
  return;
}

int LinkedList::peek() {
  if (head != 0) {
    return head->data;
  } else {
    throw std::invalid_argument("head pointer is null, cant peek at value");
  }
}

int LinkedList::pop() {
  if (head != 0) {
    Node* next = head->next;
    int out = head->data;
    delete head;
    head = next;
    return out;
  } else {
    throw std::invalid_argument("head pointer is null, cant pop off value");
  }
}

void LinkedList::push(int i) {
  Node* next = new Node(i);
  if (head != 0) {
    next->next = head;
    head = next;
  } else {
    head = next;
  }
}

void LinkedList::deleteNode(int val) {
  if (head == 0) return;
  Node* n = head;
  // If the head is the node to be deleted, do so, and adjust the linked list
  // head pointer accordingly.
  if (head->data == val) {
    head = head->next;
    delete n;
    return;
  }
  while (n->next != 0) {
    if (n->next->data == val) {
      Node* delete_me = n->next;
      n->next = n->next->next;
      delete delete_me;
      return;
    }
    n = n->next;
  }
  // TODO(vaziri@gatech.edu) Perhaps add a warning here that the node to be
  // deleted was not found within the linked list
  return;
}

std::string LinkedList::toString() {
  Node* n = head;
  std::stringstream ss;
  ss << "[";
  if (n != 0) {  // Do not attempt to access null head
    ss << n->data;
    while (n->next != 0) {
      ss << ", " << n->next->data;
      n = n->next;
    }
  }
  ss << "]";
  return ss.str();
}

LinkedList::~LinkedList() {
  Node* n;
  while (head != 0) {
    n = head->next;
    delete head;
    head = n;
  }
  return;
}

}  // namespace fund
