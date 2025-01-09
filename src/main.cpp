#include "TextBuffer.h"
#include <iostream>

int main() {
  // TextBuffer tb;
  // tb.InsertChar('H', {0, 0});
  // tb.InsertChar('e', {0, 1});
  // tb.InsertChar('l', {0, 2});
  // tb.InsertChar('l', {0, 3});
  // tb.InsertChar('o', {0, 4});
  // tb.InsertChar(' ', {0, 5});
  // tb.InsertChar('W', {0, 6});
  // tb.InsertChar('o', {0, 7});
  // tb.InsertChar('r', {0, 8});
  // tb.InsertChar('l', {0, 9});
  // tb.InsertChar('d', {0, 10});
  // tb.InsertChar('!', {0, 11});
  //
  // std::cout << tb.ToString();
  // std::cout << "\n--------------------\n";
  //
  // tb.InsertNewline({0, 5});
  // std::cout << tb.ToString();
  // std::cout << "\n--------------------\n";
  //
  // tb.RemoveChar({0, 4});
  // std::cout << tb.ToString();
  // std::cout << "\n--------------------\n";
  //
  // tb.RemoveNewline({0, 4});
  // std::cout << tb.ToString();
  // std::cout << "\n--------------------\n";
  //
  // std::cout << tb.NumLines() << std::endl;
  // std::cout << tb.NumCharAtLine(1) << std::endl;
  // std::cout << tb.NumCharAtLine(2) << std::endl;

  TextBuffer tb;

  tb.InsertChar('H', {0, 0});
  tb.InsertChar('e', {0, 1});
  tb.InsertChar('l', {0, 2});
  tb.InsertChar('l', {0, 3});
  tb.InsertChar('o', {0, 4});
  std::cout << tb.ToString();
  std::cout << "\n--------------------\n";

  tb.RemoveChar({0, 4});
  tb.RemoveChar({0, 3});
  tb.RemoveChar({0, 2});
  tb.RemoveChar({0, 1});
  tb.RemoveChar({0, 0});
  std::cout << tb.ToString();
  std::cout << "\n--------------------\n";
  tb.RemoveChar({0, 0});
  tb.RemoveChar({0, 0});
  tb.RemoveChar({0, 0});
}
