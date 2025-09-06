#include "./intGrid.hpp"
#include "raylib/raylib.h"
#include "core/settings.hpp"
#include <cstdint>
#include <filesystem>
#include <string>
#include <utility>

IntGrid::Layer::Layer(std::string id, uint32_t layerDefId, uint8_t width, uint8_t height, 
    std::filesystem::path tileSetRelPath, std::vector<uint32_t>& intGridCsv) :
  id(id),
  layerDefId(layerDefId),
  width(width),
  height(height),
  intGridCsv(std::move(intGridCsv))
{
  this->tileSetTexture = LoadTexture(tileSetRelPath.c_str());
}

void IntGrid::Draw(IntGridDef layerDef, Layer layer) {
  for (int x = 0; x < layer.width; x++) {
    for (int y = 0; y < layer.height; y++) {
      Rectangle src = layerDef.tiles[y * layer.width + x].rec;
      DrawTextureRec(layer.tileSetTexture, src, Vector2{(float)x * BLOCK, (float)y * BLOCK}, WHITE);
    }
  }
} 
