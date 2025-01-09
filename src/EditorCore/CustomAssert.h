#pragma once

#include <cassert>

#define ASSERT_WITHIN_ROW_BOUNDS(offset, lines)                                \
  assert(offset.y < lines.size() && offset.y >= 0 &&                           \
         "Offset not within row bounds")

#define ASSERT_WITHIN_OR_EDGE_ROW_BOUNDS(offset, lines)                        \
  assert(offset.y <= lines.size() && offset.y >= 0 &&                          \
         "Offset not with or at the edge of row bounds")

#define ASSERT_WITHIN_COLUMN_BOUNDS(offset, lines)                             \
  ASSERT_WITHIN_ROW_BOUNDS(offset, lines);                                     \
  assert(offset.x < lines.size() && offset.x >= 0 &&                           \
         "Offset not within column bounds")

#define ASSERT_WITHIN_OR_EDGE_COLUMN_BOUNDS(offset, lines)                     \
  ASSERT_WITHIN_ROW_BOUNDS(offset, lines);                                     \
  assert(offset.x <= lines[offset.y].size() && offset.x >= 0 &&                \
         "Offset not within or at the edge of column bounds")

#define ASSERT_WITHIN_BOUNDS(offset, lines)                                    \
  assert(offset.y < lines.size() && offset.y >= 0 &&                           \
         offset.x < lines[offset.y].size() && offset.x >= 0 &&                 \
         "Offset not within bounds")

#define ASSERT_WITHIN_OR_EDGE_BOUNDS(offset, lines)                            \
  assert(offset.y <= lines.size() && offset.y >= 0 &&                          \
         offset.x <= lines[offset.y].size() && offset.x >= 0 &&                \
         "Offset not within or at the edge of the bounds")

#define ASSERT_LINE_WITHIN_BOUNDS(lineNo, lines)                               \
  assert(lineNo <= lines.size() && lineNo > 0 &&                               \
         "Line number not within bounds")

#define ASSERT_EOL(offset, lines)                                              \
  ASSERT_WITHIN_OR_EDGE_COLUMN_BOUNDS(offset, lines);                          \
  assert(offset.x == lines[offset.y].size() && "Offset not at EOL")

#define ASSERT_NEWLINE_CHAR(offset, lines)                                     \
  ASSERT_EOL(offset, lines);                                                   \
  assert(lines.size() > offset.y + 1 &&                                        \
         "Offset doesn't contain a newline character")
