#pragma once

#include "raylib/raylib.h"
#include <cstdint>
#include <filesystem>
#include <map>
#include <string>
#include <vector>

namespace IntGrid {

struct LayerDef {
  std::string identifier;
  std::map<uint64_t, Rectangle> intGridValues;
};

struct Layer {
  uint8_t width, height, offSetX, offSetY;
  std::filesystem::path tileSetRelPath;
  std::vector<uint32_t> intGridCsv;
  Texture2D tileSetTexture;
  Layer(); 
};

void Draw(LayerDef layerDef, Layer layer);

};
