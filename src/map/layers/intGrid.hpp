#pragma once

#include "raylib/raylib.h"
#include "map/definations/definations.hpp"
#include <cstdint>
#include <filesystem>
#include <sys/types.h>
#include <vector>

namespace IntGrid {

struct Layer {
  std::string id;
  uint32_t layerDefId;
  uint8_t width, height;
  std::vector<uint32_t> intGridCsv;
  Texture2D tileSetTexture;

  Layer(std::string id, uint32_t layerDefId, uint8_t width, uint8_t height, 
      std::filesystem::path tileSetRelPath, std::vector<uint32_t>& intGridCsv); 
};

void Draw(IntGridDef layerDef, Layer layer);
  
};
