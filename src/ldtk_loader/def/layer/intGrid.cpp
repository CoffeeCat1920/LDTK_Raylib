#include "intGrid.hpp"
#include "nlohmann/json_utils.hpp"
#include "raylib/raylib.h"
#include <cstdint>

IntGridLayerDef::IntGridLayerDef(json layersData) :
  layersData(layersData){
  ParseIntGridValues();  
}

void IntGridLayerDef::ParseIntGridValues() {
  if (layersData.contains("intGridValues") && !layersData["intGridValues"].empty()) {
    for (const auto& intGridValue : layersData["intGridValues"]) {
      uint64_t value = intGridValue["value"];
      IntGridTile tile; 
      if (intGridValue.contains("tile")) {
        auto const& tileData = intGridValue["tile"]; 
        tile.tileSetUid = tileData["tileSetUid"];
        tile.groupUid = tileData["groupUid"];
        Rectangle rec {
          tileData["x"],
          tileData["y"],
          tileData["w"],
          tileData["h"]
        };
        tile.rec = rec;
      }
      intGridValues[value] = tile;
    }
  }
} 

void IntGridLayerDef::ParseValuesGroup() {
  if (layersData.contains("intGridValuesGroups") && !layersData["intGridValuesGroups"].empty()) {
    for (auto const& intGridValuesGroup : layersData["intGridValuesGroups"]) {
      uint32_t uid = intGridValuesGroup["uid"]; 
      IntGridValueGroup group;
      std::string identifier = intGridValuesGroup["identifier"];
      if (identifier == "Collision") {
        group = IntGridValueGroup::COLLISION;
      } else {
        group = IntGridValueGroup::UNGROUPED;
      }

      intGridValuesGroups[uid] = group;
    }
  }
}
