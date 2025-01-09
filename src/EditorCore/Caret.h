#pragma once

#include "TextBuffer.h"
#include "Types.h"

class Caret {
public:
  Caret(TextBuffer &textBuffer);
  ~Caret();

  void MoveLeft();
  void MoveRight();
  void MoveUp();
  void MoveDown();
  void SetPosition(Offset offset);

  inline Offset GetPosition() const { return m_CaretPosition; }

private:
  Offset m_CaretPosition;
  TextBuffer &m_TextBuffer;
};
