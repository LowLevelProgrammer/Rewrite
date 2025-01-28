#include "Editor.h"

#include <memory>

Editor::Editor()
    : m_TextBuffer(std::make_unique<TextBuffer>()),
      m_Caret(std::make_unique<Caret>(*m_TextBuffer)) {}

Editor::~Editor() {}

void Editor::Insert(char character) {
  Offset offset = m_Caret->GetPosition();
  switch (character) {
  case '\n':
    m_TextBuffer->InsertNewline(offset);
    break;
  default:
    m_TextBuffer->InsertChar(character, offset);
  }
  m_Caret->MoveRight();
}

void Editor::Erase() {
  auto [y, x] = m_Caret->GetPosition();

  if (x > 0) {
    m_TextBuffer->RemoveChar({y, x - 1});
    m_Caret->MoveLeft();
  } else if (y > 0) {
    size_t newlineY = y - 1;
    size_t newlineX = m_TextBuffer->NumCharAtLineOffset(newlineY);
    m_TextBuffer->RemoveNewline({newlineY, newlineX});
    m_Caret->SetPosition({newlineY, newlineX});
  }
}

void Editor::SetCaret(Offset caretOffset) { m_Caret->SetPosition(caretOffset); }
