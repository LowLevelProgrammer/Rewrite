#pragma once

#include <cstddef>
#include <ostream>

struct Offset {
  size_t y;
  size_t x;

  Offset(size_t y, size_t x) : y(y), x(x) {}

  bool operator==(const Offset &other) const {
    return y == other.y && x == other.x;
  }
  bool operator==(Offset &other) const { return y == other.y && x == other.x; }
  bool operator==(Offset &&other) const { return y == other.y && x == other.x; }

  friend std::ostream &operator<<(std::ostream &os, const Offset &offset) {
    os << "Offset(y: " << offset.y << ", x: " << offset.x << ")";
    return os;
  }
};
