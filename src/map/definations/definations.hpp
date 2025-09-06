#pragma once

#include "raylib/raylib.h"
#include <cstdint>
#include <map>
#include <string>

struct LayerDef {
  std::string identifier;
  std::map<uint64_t, Rectangle> intGridValues;
};
