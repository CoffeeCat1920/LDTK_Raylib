#pragma once

#include "raylib/raylib.h"
#include <cstdint>
#include <map>
#include <sys/types.h>

struct Tile {
  uint32_t tileSetUid;
  Rectangle rec;
  uint32_t groupUid;
};

struct IntGridDef {
  uint32_t uid;
  std::map<uint64_t, Tile> tiles;
};
