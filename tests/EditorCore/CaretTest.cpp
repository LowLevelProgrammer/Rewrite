#include <gtest/gtest-death-test.h>
#include <gtest/gtest.h>

#include "Caret.h"
#include "TextBuffer.h"

class CaretTest : public testing::Test {
protected:
  CaretTest() : caret(buffer) {}

  void SetUp() override {
    buffer.InsertChar('H', {0, 0});
    buffer.InsertChar('e', {0, 1});
    buffer.InsertChar('l', {0, 2});
    buffer.InsertChar('l', {0, 3});
    buffer.InsertChar('o', {0, 4});
    buffer.InsertNewline({0, 5});
    buffer.InsertChar('W', {1, 0});
    buffer.InsertChar('o', {1, 1});
    buffer.InsertChar('r', {1, 2});
    buffer.InsertChar('l', {1, 3});
    buffer.InsertChar('d', {1, 4});
    buffer.InsertChar('!', {1, 5});
    buffer.InsertNewline({1, 6});
    buffer.InsertChar('A', {2, 0});
    buffer.InsertChar('k', {2, 1});
    buffer.InsertChar('a', {2, 2});
    buffer.InsertChar('s', {2, 3});
    buffer.InsertChar('h', {2, 4});
  }

  TextBuffer buffer;
  Caret caret;
};

TEST_F(CaretTest, Initialize) { EXPECT_EQ(caret.GetPosition(), Offset(0, 0)); }

TEST_F(CaretTest, SetCaretValid) {
  caret.SetPosition({0, 0});
  EXPECT_EQ(caret.GetPosition(), Offset(0, 0));
}

TEST_F(CaretTest, SetCaretValid2) {
  // "Hello|"
  caret.SetPosition({0, 5});
  EXPECT_EQ(caret.GetPosition(), Offset(0, 5));
}

TEST_F(CaretTest, SetCaretValid3) {
  // "|World!"
  caret.SetPosition({1, 0});
  EXPECT_EQ(caret.GetPosition(), Offset(1, 0));
}

TEST_F(CaretTest, SetCaretValid4) {
  // "World!|"
  caret.SetPosition({1, 6});
  EXPECT_EQ(caret.GetPosition(), Offset(1, 6));
}

TEST_F(CaretTest, SetCaretValid5) {
  // "Akash|"
  caret.SetPosition({2, 5});
  EXPECT_EQ(caret.GetPosition(), Offset(2, 5));
}

TEST_F(CaretTest, SetCaretInvalid) {
  EXPECT_DEATH(caret.SetPosition({0, 6}),
               "Offset not within or at the edge of column bounds");
}
TEST_F(CaretTest, SetCaretInvalid2) {
  EXPECT_DEATH(caret.SetPosition({1, 7}),
               "Offset not within or at the edge of column bounds");
}
TEST_F(CaretTest, SetCaretInvalid3) {
  EXPECT_DEATH(caret.SetPosition({2, 6}),
               "Offset not within or at the edge of column bounds");
}
TEST_F(CaretTest, SetCaretInvalid4) {
  EXPECT_DEATH(caret.SetPosition({3, 0}), "Offset not within row bounds");
}

TEST_F(CaretTest, MoveRight) {
  // "|Hello"
  caret.MoveRight();
  // "H|ello"
  EXPECT_EQ(caret.GetPosition(), Offset(0, 1));
}

TEST_F(CaretTest, MoveRight2) {
  EXPECT_EQ(caret.GetPosition(), Offset(0, 0));
  caret.MoveRight();
  caret.MoveRight();
  caret.MoveRight();
  caret.MoveRight();
  caret.MoveRight();
  // "Hello|"
  EXPECT_EQ(caret.GetPosition(), Offset(0, 5));
}

TEST_F(CaretTest, MoveRightAtEOL) {
  caret.SetPosition({0, 5});
  // "Hello|"
  EXPECT_EQ(caret.GetPosition(), Offset(0, 5));

  caret.MoveRight();
  // "Hello"
  // "|World!"
  EXPECT_EQ(caret.GetPosition(), Offset(1, 0));
}

TEST_F(CaretTest, MoveRightAtEOF) {
  caret.SetPosition({2, 5});
  // "Hello"
  // "World!"
  // "Akash|"
  EXPECT_EQ(caret.GetPosition(), Offset(2, 5));

  caret.MoveRight();
  // "Hello"
  // "World!"
  // "Akash|"
  EXPECT_EQ(caret.GetPosition(), Offset(2, 5));
}
