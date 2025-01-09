#include <gtest/gtest.h>

#include "TextBuffer.h"

class TextBufferTest : public ::testing::Test {
protected:
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
  }

  TextBuffer buffer;
};

TEST_F(TextBufferTest, ToString) {
  EXPECT_EQ(buffer.ToString(), "Hello\nWorld");
}

TEST_F(TextBufferTest, NumLines) { EXPECT_EQ(buffer.NumLines(), 2); }

TEST_F(TextBufferTest, GetLineValid) {
  EXPECT_EQ(buffer.GetLineAtOffset(0).value(), "Hello");
  EXPECT_EQ(buffer.GetLineAtOffset(1).value(), "World");
}

TEST_F(TextBufferTest, NumCharAtLine) {
  EXPECT_EQ(buffer.NumCharAtLineOffset(0), 5);
  EXPECT_EQ(buffer.NumCharAtLineOffset(1), 5);
}

TEST_F(TextBufferTest, GetLineInvalid) {
  EXPECT_FALSE(buffer.GetLineAtOffset(2).has_value());
}

TEST_F(TextBufferTest, InsertChar) {
  buffer.InsertChar('!', {1, 5});
  EXPECT_EQ(buffer.GetLineAtOffset(1).value(), "World!");
}

TEST_F(TextBufferTest, InsertNewline) {
  buffer.InsertNewline({1, 2});
  EXPECT_EQ(buffer.GetLineAtOffset(1).value(), "Wo");
  EXPECT_EQ(buffer.GetLineAtOffset(2).value(), "rld");
}

TEST_F(TextBufferTest, RemoveChar) {
  buffer.RemoveChar({0, 4});
  EXPECT_EQ(buffer.GetLineAtOffset(0).value(), "Hell");
}

TEST_F(TextBufferTest, RemoveAllCharsInLine) {
  buffer.RemoveChar({0, 4});
  buffer.RemoveChar({0, 3});
  buffer.RemoveChar({0, 2});
  buffer.RemoveChar({0, 1});
  buffer.RemoveChar({0, 0}); // Line should now be empty
  EXPECT_EQ(buffer.GetLineAtOffset(0).value(), "");
}

TEST_F(TextBufferTest, RemoveAllCharsInLine2) {
  buffer.RemoveChar({0, 0});
  buffer.RemoveChar({0, 0});
  buffer.RemoveChar({0, 0});
  buffer.RemoveChar({0, 0});
  buffer.RemoveChar({0, 0}); // Line should now be empty
  EXPECT_EQ(buffer.GetLineAtOffset(0).value(), "");
}

// TEST_F(TextBufferTest, RemoveCharFromEmptyLine) {
//   buffer.RemoveChar({0, 0});
//   buffer.RemoveChar({0, 0});
//   buffer.RemoveChar({0, 0});
//   buffer.RemoveChar({0, 0});
//   buffer.RemoveChar({0, 0}); // Line should now be empty
//   buffer.RemoveChar({0, 0});
//   buffer.RemoveChar(
//       {0, 0}); // Ensure no errors occur when removing from an empty line
//   EXPECT_EQ(buffer.GetLineAtOffset(0).value(), "");
// }
