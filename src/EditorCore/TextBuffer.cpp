#include "TextBuffer.h"

#include "CustomAssert.h"
#include "Types.h"
#include <string>

TextBuffer::TextBuffer() { m_Lines.push_back(""); }
TextBuffer::~TextBuffer() {}

void TextBuffer::InsertLine(std::string line, Offset offset) {}

void TextBuffer::InsertChar(char character, Offset offset) {
  ASSERT_WITHIN_OR_EDGE_BOUNDS(offset, m_Lines);
  m_Lines[offset.y].insert(m_Lines[offset.y].begin() + offset.x, character);
}

void TextBuffer::InsertNewline(Offset offset) {
  ASSERT_WITHIN_OR_EDGE_BOUNDS(offset, m_Lines);
  std::string textToDisplace = m_Lines[offset.y].substr(offset.x);
  m_Lines[offset.y].erase(offset.x);
  m_Lines.insert(m_Lines.begin() + offset.y + 1, textToDisplace);
}

void TextBuffer::RemoveLine(size_t yOffset) {}

void TextBuffer::RemoveChar(Offset offset) {
  // Return if buffer is empty
  if (m_Lines.size() == 1 && m_Lines[0].size() == 0 && offset == Offset(0, 0)) {
    return;
  }
  ASSERT_WITHIN_BOUNDS(offset, m_Lines);
  m_Lines[offset.y].erase(m_Lines[offset.y].begin() + offset.x);
}

void TextBuffer::RemoveNewline(Offset offset) {
  ASSERT_NEWLINE_CHAR(offset, m_Lines);
  std::string textToDisplace = m_Lines[offset.y + 1];
  m_Lines.erase(m_Lines.begin() + offset.y + 1);
  m_Lines[offset.y].append(textToDisplace);
}

size_t TextBuffer::NumLines() { return m_Lines.size(); }

long TextBuffer::NumCharAtLineOffset(size_t yOffset) {
  if (yOffset >= m_Lines.size() || yOffset < 0) {
    return -1;
  }
  return m_Lines[yOffset].size();
}

long TextBuffer::NumCharAtLine(size_t lineNumber) {
  if (lineNumber > m_Lines.size() || lineNumber < 1) {
    return -1;
  }
  return m_Lines[lineNumber - 1].size();
}

std::string TextBuffer::ToString() {
  std::string str;
  for (int i = 0; i < m_Lines.size(); i++) {
    str += m_Lines[i];
    if (i != m_Lines.size() - 1) {
      str += '\n';
    }
  }
  return str;
}

std::optional<std::string> TextBuffer::GetLineAtOffset(size_t yOffset) {
  if (yOffset >= 0 && yOffset < m_Lines.size())
    return m_Lines[yOffset];
  return std::nullopt;
}

std::optional<std::string> TextBuffer::GetLine(size_t lineNumber) {
  if (lineNumber < 1 || lineNumber > m_Lines.size())
    return std::nullopt;
  return m_Lines[lineNumber - 1];
}
