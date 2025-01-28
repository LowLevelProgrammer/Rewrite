#pragma once

#include "Caret.h"
#include "TextBuffer.h"
#include "Types.h"
#include <memory>

class Editor {
public:
  Editor();
  ~Editor();

  void Insert(char character);
  void Erase();
  void SetCaret(Offset caretOffset);

  const std::unique_ptr<TextBuffer> &GetTextBuffer() const {
    return m_TextBuffer;
  }
  const std::unique_ptr<Caret> &GetCaret() const { return m_Caret; }

private:
  std::unique_ptr<TextBuffer> m_TextBuffer;
  std::unique_ptr<Caret> m_Caret;
};
