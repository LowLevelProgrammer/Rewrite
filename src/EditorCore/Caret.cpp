#include "Caret.h"
#include "CustomAssert.h"
#include <algorithm>
#include <cstddef>

Caret::Caret(TextBuffer &textBuffer)
    : m_CaretPosition(0, 0), m_TextBuffer(textBuffer) {}

Caret::~Caret() {}

void Caret::MoveLeft() {
  if (m_CaretPosition.x > 0)
    m_CaretPosition.x--;
  else if (m_CaretPosition.y > 0) {
    m_CaretPosition.y--;
    m_CaretPosition.x = m_TextBuffer.NumCharAtLineOffset(m_CaretPosition.y);
  }
}

void Caret::MoveRight() {
  if (m_CaretPosition.x < m_TextBuffer.NumCharAtLineOffset(m_CaretPosition.y)) {
    m_CaretPosition.x++;
  } else if (m_CaretPosition.y + 1 < m_TextBuffer.NumLines()) {
    m_CaretPosition.y++;
    m_CaretPosition.x = 0;
  }
}

void Caret::MoveUp() {
  if (m_CaretPosition.y > 0) {
    m_CaretPosition.y--;
    m_CaretPosition.x =
        std::min(m_CaretPosition.x,
                 (size_t)m_TextBuffer.NumCharAtLineOffset(m_CaretPosition.y));
  }
}

void Caret::MoveDown() {
  if (m_CaretPosition.y + 1 < m_TextBuffer.NumLines()) {
    m_CaretPosition.y++;
    m_CaretPosition.x =
        std::min(m_CaretPosition.x,
                 (size_t)m_TextBuffer.NumCharAtLineOffset(m_CaretPosition.y));
  }
}

void Caret::SetPosition(Offset offset) {
  ASSERT_WITHIN_OR_EDGE_COLUMN_BOUNDS(offset, m_TextBuffer.GetBuffer());
  m_CaretPosition = offset;
}
