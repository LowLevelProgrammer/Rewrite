#pragma once

#include "Types.h"
#include <optional>
#include <string>
#include <vector>

class TextBuffer {
public:
  TextBuffer();
  ~TextBuffer();

  void InsertLine(std::string content, Offset offset);
  void InsertChar(char character, Offset offset);
  void InsertNewline(Offset offset);
  void RemoveLine(size_t yOffset);
  void RemoveChar(Offset offset);
  void RemoveNewline(Offset offset);

  size_t NumLines();
  long NumCharAtLineOffset(size_t yOffset);
  long NumCharAtLine(size_t lineNumber);

  std::string ToString();
  std::optional<std::string> GetLineAtOffset(size_t yOffset);
  std::optional<std::string> GetLine(size_t lineNumber);

private:
  std::vector<std::string> m_Lines;
};
