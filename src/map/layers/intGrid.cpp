#include "./intGrid.hpp"
#include "raylib/raylib.h"
#include "core/settings.hpp"

IntGrid::Layer::Layer() {
  this->tileSetTexture = LoadTexture(tileSetRelPath.c_str());
}

void IntGrid::Draw(LayerDef layerDef, Layer layer) {
  for (int x = 0; x < layer.width; x++) {
    for (int y = 0; y < layer.height; y++) {
      Rectangle src = layerDef.intGridValues[y * layer.width + x];
      DrawTextureRec(layer.tileSetTexture, src, Vector2{(float)x * BLOCK, (float)y * BLOCK}, WHITE);
    }
  }
} 
