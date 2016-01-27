// Copyright Andrew Vaziri 2016
#include "../include/linked_list.h"
#include "gtest/gtest.h"

// The fixture for testing class Foo.
class LinkedListTest : public ::testing::Test {
 protected:
  fund::LinkedList* list;
  // You can remove any or all of the following functions if its body
  // is empty.

  LinkedListTest() {
    // You can do set-up work for each test here.
  }

  virtual ~LinkedListTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
    list = new fund::LinkedList();
    list->appendToTail(2);
    list->appendToTail(-1);
    list->appendToTail(4);
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
    delete list;
  }

  // Objects declared here can be used by all tests in the test case for Foo.
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(LinkedListTest, initialize) {
  EXPECT_EQ(list->toString(), "[2, -1, 4]");
}

// Tests that Foo does Xyz.
TEST_F(LinkedListTest, methodPrintWorksWithNullHead) {
  list->deleteNode(2);
  list->deleteNode(-1);
  list->deleteNode(4);
  EXPECT_EQ(list->toString(), "[]");
}

// Tests that Foo does Xyz.
TEST_F(LinkedListTest, methodAppendToTailWorks) {
  list->appendToTail(1);
  EXPECT_EQ(list->toString(), "[2, -1, 4, 1]");
}

// Tests that Foo does Xyz.
TEST_F(LinkedListTest, methodAppendToTailHandlesNullList) {
  list->deleteNode(2);
  list->deleteNode(-1);
  list->deleteNode(4);
  EXPECT_EQ(list->toString(), "[]");
  list->appendToTail(5);
  EXPECT_EQ(list->toString(), "[5]");
}

// Tests that Foo does Xyz.
TEST_F(LinkedListTest, methodDeleteNodeHandlesMidListDeletion) {
  list->deleteNode(-1);
  EXPECT_EQ(list->toString(), "[2, 4]");
}

TEST_F(LinkedListTest, methodDeleteNodeHandlesHeadDeletion) {
  list->deleteNode(2);
  EXPECT_EQ(list->toString(), "[-1, 4]");
}

TEST_F(LinkedListTest, methodDeleteNodeHandlesTailDeletion) {
  list->deleteNode(4);
  EXPECT_EQ(list->toString(), "[2, -1]");
}

TEST_F(LinkedListTest, methodDeleteNodeHandlesNoSuchNode) {
  list->deleteNode(4000);
  EXPECT_EQ(list->toString(), "[2, -1, 4]");
}

TEST_F(LinkedListTest, methodDeleteNodeHandlesNullHead) {
  list->deleteNode(2);
  list->deleteNode(-1);
  list->deleteNode(4);
  list->deleteNode(7);
  EXPECT_EQ(list->toString(), "[]");
}

TEST_F(LinkedListTest, methodPeekHandlesNonNullHead) {
  EXPECT_EQ(list->peek(), 2);
}

TEST_F(LinkedListTest, methodPeekHandlesNullHead) {
  list->deleteNode(2);
  list->deleteNode(-1);
  list->deleteNode(4);
  try {
    list->peek();
  } catch (std::invalid_argument& ex) {
    ASSERT_STREQ(ex.what(), "head pointer is null, cant peek at value");
    return;
  }
  ASSERT_TRUE(0);  // If the code gets to this point the test has failed
}

TEST_F(LinkedListTest, methodPopHandlesNonNullHead) {
  EXPECT_EQ(list->pop(), 2);
  EXPECT_EQ(list->pop(), -1);
  EXPECT_EQ(list->pop(), 4);
}

TEST_F(LinkedListTest, methodPopHandlesNullHead) {
  list->deleteNode(2);
  list->deleteNode(-1);
  list->deleteNode(4);
  try {
    list->pop();
  } catch (std::invalid_argument& ex) {
    ASSERT_STREQ(ex.what(), "head pointer is null, cant pop off value");
    return;
  }
  ASSERT_TRUE(0);  // If the code gets to this point the test has failed
}

TEST_F(LinkedListTest, methodPushHandlesNonNullHead) {
  list->push(0);
  EXPECT_EQ(list->peek(), 0);
}

TEST_F(LinkedListTest, methodPushHandlesNullHead) {
  list->deleteNode(2);
  list->deleteNode(-1);
  list->deleteNode(4);
  list->push(0);
  EXPECT_EQ(list->peek(), 0);
}

TEST_F(LinkedListTest, destructorHandlesNonNull) {
  list->~LinkedList();
  EXPECT_EQ(list->toString(), "[]");
}

TEST_F(LinkedListTest, destructorHandlesNull) {
  list->deleteNode(2);
  list->deleteNode(-1);
  list->deleteNode(4);
  list->~LinkedList();
  EXPECT_EQ(list->toString(), "[]");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
