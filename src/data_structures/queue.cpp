// Copyright Andrew Vaziri 2016
#include "../../include/queue.h"
#include <string>
#include <sstream>
#include <iostream>

namespace fund {
QueueNode::QueueNode(int i)
  : data(i), next(0), prev(0) {
}

Queue::Queue()
    : head(0), tail(0) {
}

Queue::~Queue() {
  while (head != 0) {
    remove();
  }
}

void Queue::add(int data) {
  QueueNode* new_tail = new QueueNode(data);
  if (tail != 0) {
    tail->next = new_tail;
    new_tail->prev = tail;
    tail = new_tail;
  } else {
    tail = new_tail;
    head = new_tail;
  }
}

int Queue::remove() {
  int data;
  if (head != 0) {
    data = head->data;
    QueueNode* next = head->next;
    delete head;
    if (next != 0) {
      head = next;
      head->prev = 0;
    } else {
      head = 0;
      tail = 0;
    }
  }
  return data;
}

int Queue::peek() {
  if (head != 0) {
    return head->data;
  } else {
    throw 1337;
  }
}

bool Queue::isEmpty() {
  if (head == 0) {
    return 1;
  } else {
    return 0;
  }
}

std::string Queue::toString() {
  std::stringstream ss;
  QueueNode* n = head;
  ss << "[";
  if (n != 0) {
    ss << n->data;
    while (n->next != 0) {
      std::cout << "Node value : " << n->data << " Node Address: " <<
      n << " Next Node address: " << n->next << std::endl;
        n->next;
      ss << "," << n->next->data;
      n = n->next;
    }
  }
  ss << "]";
  return ss.str();
}
}  // namespace fund
