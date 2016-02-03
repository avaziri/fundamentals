// Copyright Andrew Vaziri 2016
#include "../include/queue.h"
#include "gtest/gtest.h"

// The fixture for testing class Foo.
class QueueTest : public ::testing::Test {
 protected:
  fund::Queue* queue;
  // You can remove any or all of the following functions if its body
  // is empty.

  QueueTest() {
    // You can do set-up work for each test here.
  }

  virtual ~QueueTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
    queue = new fund::Queue();
    queue->add(3);
    queue->add(2);
    queue->add(1);
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
    // delete list;
  }

  // Objects declared here can be used by all tests in the test case for Foo.
};

TEST_F(QueueTest, toStringAndAddWork) {
  EXPECT_EQ(queue->toString(), "[3,2,1]");
}

TEST_F(QueueTest, toStringEmpty) {
  queue->remove();
  queue->remove();
  queue->remove();
  EXPECT_EQ(queue->toString(), "[]");
}

TEST_F(QueueTest, removeEmpty) {
  queue->remove();
  queue->remove();
  queue->remove();
  queue->remove();
  EXPECT_EQ(queue->toString(), "[]");
}

TEST_F(QueueTest, peekWorks) {
  queue->peek();
  queue->peek();
  int i = queue->peek();
  EXPECT_EQ(i, 3);
}

TEST_F(QueueTest, peekHandlesNullPointer) {
  queue->remove();
  queue->remove();
  queue->remove();
  try {
    queue->peek();
  } catch (int e) {
    ASSERT_TRUE(1);
  }
}

TEST_F(QueueTest, isemptyIsEmpty) {
  queue->remove();
  queue->remove();
  queue->remove();
  bool b = queue->isEmpty();
  EXPECT_EQ(b, 1);
}

TEST_F(QueueTest, isemptyIsNotEmpty) {
  bool b = queue->isEmpty();
  EXPECT_EQ(b, 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
