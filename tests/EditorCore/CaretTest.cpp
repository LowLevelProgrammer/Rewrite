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
    buffer.InsertNewline({2, 5});
    buffer.InsertChar('A', {3, 0});
    buffer.InsertChar('n', {3, 1});
    buffer.InsertChar('o', {3, 2});
    buffer.InsertChar('t', {3, 3});
    buffer.InsertChar('h', {3, 4});
    buffer.InsertChar('e', {3, 5});
    buffer.InsertChar('r', {3, 6});
    buffer.InsertChar(' ', {3, 7});
    buffer.InsertChar('S', {3, 8});
    buffer.InsertChar('t', {3, 9});
    buffer.InsertChar('r', {3, 10});
    buffer.InsertChar('i', {3, 11});
    buffer.InsertChar('n', {3, 12});
    buffer.InsertChar('g', {3, 13});
    buffer.InsertNewline({3, 14});
    buffer.InsertChar('T', {4, 0});
    buffer.InsertChar('e', {4, 1});
    buffer.InsertChar('s', {4, 2});
    buffer.InsertChar('t', {4, 3});
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
  EXPECT_DEATH(caret.SetPosition({5, 0}), "Offset not within row bounds");
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
  // 4. "Another String"
  // 5. "Test|"
  caret.SetPosition({4, 4});
  EXPECT_EQ(caret.GetPosition(), Offset(4, 4));

  caret.MoveRight();
  // 4. "Another String"
  // 5. "Test|"
  EXPECT_EQ(caret.GetPosition(), Offset(4, 4));
}

TEST_F(CaretTest, MoveLeftAtSOF) {
  // "|Hello"
  caret.MoveLeft();

  // "|Hello"
  EXPECT_EQ(caret.GetPosition(), Offset(0, 0));
}

TEST_F(CaretTest, MoveLeftAtSOL) {
  // "Hello"
  // "World!"
  // "|Akash"
  caret.SetPosition({2, 0});

  caret.MoveLeft();
  // "Hello"
  // "World!|"
  // "Akash"
  EXPECT_EQ(caret.GetPosition(), Offset(1, 6));
}

TEST_F(CaretTest, MoveLeft) {
  caret.SetPosition({1, 3});
  // "Hello"
  // "Wor|ld!"

  caret.MoveLeft();
  // "Wo|rld!"
  EXPECT_EQ(caret.GetPosition(), Offset({1, 2}));
}

TEST_F(CaretTest, MoveUpWithinBouds) {
  caret.SetPosition({1, 2});
  // "Hello"
  // "Wo|rld!"
  // "Akash"

  caret.MoveUp();
  // "He|llo"
  // "World!"
  // "Akash"
  EXPECT_EQ(caret.GetPosition(), Offset(0, 2));
}

TEST_F(CaretTest, MoveUpToASmallerLine) {
  caret.SetPosition({3, 11});
  // 3. "Akash"
  // 4. "Another Str|ing"

  caret.MoveUp();
  // 3. "Akash|"
  // 4. "Another String"
  EXPECT_EQ(caret.GetPosition(), Offset(2, 5));
}

TEST_F(CaretTest, MoveUpToASmallerLine2) {
  caret.SetPosition({1, 6});
  // 1. "Hello"
  // 2. "World!|"

  caret.MoveUp();
  // 1. "Hello"
  // 2. "World!"
  EXPECT_EQ(caret.GetPosition(), Offset(0, 5));
}

TEST_F(CaretTest, MoveUpAtFirstLine) {
  caret.MoveUp();
  EXPECT_EQ(caret.GetPosition(), Offset(0, 0));
}

TEST_F(CaretTest, MoveUpAtFirstLine2) {
  caret.SetPosition({0, 3});

  caret.MoveUp();
  EXPECT_EQ(caret.GetPosition(), Offset(0, 3));
}

TEST_F(CaretTest, MoveDownWithinBounds) {
  caret.SetPosition({2, 3});

  caret.MoveDown();
  EXPECT_EQ(caret.GetPosition(), Offset(3, 3));
}

TEST_F(CaretTest, MoveDownToASmallerLine) {
  caret.SetPosition({1, 6});
  // 2. "World!|"
  // 3. "Akash"

  caret.MoveDown();
  EXPECT_EQ(caret.GetPosition(), Offset(2, 5));
}

TEST_F(CaretTest, MoveDownToASmallerLine2) {
  caret.SetPosition({3, 14});
  // 4. "Another String|"
  // 5. "Test"

  caret.MoveDown();
  // 4. "Another String"
  // 5. "Test|"
  EXPECT_EQ(caret.GetPosition(), Offset(4, 4));
}

TEST_F(CaretTest, MoveDownAtLastLine) {
  caret.SetPosition({4, 2});

  caret.MoveDown();
  EXPECT_EQ(caret.GetPosition(), Offset(4, 2));
}

TEST_F(CaretTest, MoveDownAtLastLine2) {
  caret.SetPosition({4, 0});

  caret.MoveDown();
  EXPECT_EQ(caret.GetPosition(), Offset(4, 0));
}
