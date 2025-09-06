#include "level.hpp"
#include "map/definations/definations.hpp"
#include "map/layers/intGrid.hpp"
#include "nlohmann/json_utils.hpp"
#include "raylib/raylib.h"
#include <cstdint>
#include <cstdint>
#include <filesystem>
#include <map>
#include <string>
#include <sys/types.h>
#include <vector>

Level::Level(const json& levelData) {
   
  id = levelData["iid"].get<std::string>();

  if (levelData.contains("defs") && !levelData["defs"].empty()) {

    if (levelData.contains("layers") && !levelData["layers"].empty()) {

      for (const auto& layer : levelData["layers"]) {

        if (layer["__type"] == "IntGrid") {

          IntGridDef intGridDef;
          intGridDef.uid = layer["uid"]; 

          if (layer.contains("intGridValues") && !layer["intGridValues"].empty()) {
            for(const auto& intGridValue : layer["intGridValues"]) {
              uint32_t value = intGridValue["value"];

              Tile tile;

              tile.groupUid = intGridValue["groupUid"];
              tile.tileSetUid = intGridValue["tileSetUid"];
              const auto& tileVals = intGridValue["tile"];
              tile.rec = {
                tileVals["x"],
                tileVals["y"],
                tileVals["w"],
                tileVals["h"]
              };

              intGridDef.tiles[value] = tile; 
            }
          }

          intGridDefs[intGridDef.uid] = intGridDef;
        }
      }
    }
  }

  if (levelData.contains("layerInstances") && !levelData["layerInstances"].empty()) {

    for (const auto& layerInstance : levelData["layerInstances"]) {

      if (layerInstance["__type"] == "IntGrid") {
        std::string id = layerInstance["iid"];
        uint32_t layerDefId = layerInstance["layerDefUid"];
        uint8_t width = layerInstance["__cWid"]; 
        uint8_t height = layerInstance["__cHei"];
        std::filesystem::path tileSetRelPath = layerInstance["__tilesetRelPath"];
        std::vector<uint32_t> intGridCsv = layerInstance["intGridCsv"].get<std::vector<uint32_t>>();
        IntGrid::Layer layer(id, layerDefId, width, height, tileSetRelPath, intGridCsv);

        intGridInstances[id] = layer;
      }

    }

  }
  
}
