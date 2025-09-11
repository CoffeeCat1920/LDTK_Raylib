#pragma once 

#include "nlohmann/json_utils.hpp"
#include "raylib/raylib.h"
#include <cstdint>
#include <map>
#include <sys/types.h>

struct IntGridTile {
  uint16_t groupUid;
  uint16_t tileSetUid;
  Rectangle rec;
};

enum IntGridValueGroup {
  COLLISION,
  UNGROUPED
};

class IntGridLayerDef  {

private:
  json layersData;

  std::map<uint32_t, IntGridTile> intGridValues;
  std::map<uint32_t, IntGridValueGroup> intGridValuesGroups;

  void ParseIntGridValues();
  void ParseIntGridValuesGroup();
  
public:
  IntGridLayerDef(json layersData);

};
