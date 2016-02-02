// Copyright Andrew Vaziri 2016
#include "../include/stack.h"
#include "gtest/gtest.h"

// The fixture for testing class Foo.
class StackTest : public ::testing::Test {
 protected:
  fund::Stack* stack;
  // You can remove any or all of the following functions if its body
  // is empty.

  StackTest() {
    // You can do set-up work for each test here.
  }

  virtual ~StackTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
    stack = new fund::Stack();
    stack->push(3);
    stack->push(2);
    stack->push(1);
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
    // delete list;
  }

  // Objects declared here can be used by all tests in the test case for Foo.
};

TEST_F(StackTest, printandpushwork) {
  EXPECT_EQ(stack->toString(), "[1,2,3]");
}

TEST_F(StackTest, printEmpty) {
  stack->pop();
  stack->pop();
  stack->pop();
  EXPECT_EQ(stack->toString(), "[]");
}

TEST_F(StackTest, popTooMuch) {
  stack->pop();
  stack->pop();
  stack->pop();
  try {
    stack->pop();
  } catch (int e) {
    ASSERT_TRUE(1);
  }
  EXPECT_EQ(stack->toString(), "[]");
}

TEST_F(StackTest, peekworks) {
  stack->peek();
  stack->peek();
  int i = stack->peek();
  EXPECT_EQ(i, 1);
}

TEST_F(StackTest, peekHandlesNullPointer) {
  stack->pop();
  stack->pop();
  stack->pop();
  try {
    stack->peek();
  } catch (int e) {
    ASSERT_TRUE(1);
  }
}

TEST_F(StackTest, isemptyIsEmpty) {
  stack->pop();
  stack->pop();
  stack->pop();
  bool b = stack->isEmpty();
  EXPECT_EQ(b, 1);
}

TEST_F(StackTest, isemptyIsNotEmpty) {
  bool b = stack->isEmpty();
  EXPECT_EQ(b, 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
