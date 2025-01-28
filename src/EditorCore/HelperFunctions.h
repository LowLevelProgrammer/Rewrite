#pragma once

#include "Editor.h"
#include "TextBuffer.h"
#include <iostream>
#include <string>
#include <vector>

inline void PrintText(const Editor &editor) {
  std::vector<std::string> buffer = editor.GetTextBuffer()->GetBuffer();
  auto caret = editor.GetCaret()->GetPosition();

  buffer[caret.y].insert(buffer[caret.y].begin() + caret.x, '|');

  for (int i = 0; i < buffer.size(); i++) {
    if (i < buffer.size() - 1) {
      std::cout << buffer[i] << std::endl;
    } else {
      std::cout << buffer[i];
    }
  }
}
