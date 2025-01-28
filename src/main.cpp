#include "Editor.h"
#include "HelperFunctions.h"
#include "TextBuffer.h"
#include <iostream>

int main() {
  Editor editor;
  editor.Insert('H');
  editor.Insert('e');
  editor.Insert('l');
  editor.Insert('l');
  editor.Insert('o');
  editor.Insert(' ');
  editor.Insert('W');
  editor.Insert('o');
  editor.Insert('r');
  editor.Insert('l');
  editor.Insert('d');
  editor.Insert('!');
  editor.Insert('\n');

  editor.Erase();
  editor.Erase();
  editor.Erase();
  editor.Erase();

  // Hello Worl
  // editor.SetCaret({0, 2});
  // editor.SetCaret({0, 10});

  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Insert('H');
  editor.Insert('\n');
  editor.Insert('e');
  editor.Insert('l');
  editor.Insert('l');
  editor.Insert('o');
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.SetCaret({1, 0});
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.SetCaret({0, 0});
  editor.Erase();
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.Insert('\n');
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.SetCaret({0, 0});
  editor.Insert('A');
  editor.Insert('k');
  editor.Insert('a');
  editor.Insert('s');
  editor.Insert('h');
  PrintText(editor);
  std::cout << "\n---------------\n";

  editor.SetCaret({0, 5});
  PrintText(editor);
  std::cout << "\n---------------\n";
}
