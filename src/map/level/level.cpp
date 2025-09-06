#include "level.hpp"
#include "map/layers/intGrid.hpp"
#include "nlohmann/json_utils.hpp"
#include <cstdint>
#include <cstdint>
#include <filesystem>
#include <string>
#include <sys/types.h>
#include <vector>

Level::Level(json levelData) {
   
  id = levelData["iid"].get<std::string>();

  if (levelData.contains("layerInstances") && !levelData["layerInstances"].empty()) {

    if (levelData["__type"] == "IntGrid") {
      for (const auto& layerInstance : levelData["layerInstances"]) {
        std::string id = layerInstance["iid"];
        uint8_t width = layerInstance["__cWid"]; 
        uint8_t height = layerInstance["__cHei"];
        std::filesystem::path tileSetRelPath = layerInstance["__tilesetRelPath"];
        std::vector<uint32_t> intGridCsv = layerInstance["intGridCsv"].get<std::vector<uint32_t>>();
        IntGrid::Layer layer(id, width, height, tileSetRelPath, intGridCsv);
      }
    }

  }
  
}
