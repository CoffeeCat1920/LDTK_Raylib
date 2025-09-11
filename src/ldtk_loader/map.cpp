#include "map.hpp"
#include "ldtk_loader/def/layer/intGrid.hpp"
#include "nlohmann/json_utils.hpp"
#include <filesystem>
#include <fstream>


Map::Map(std::filesystem::path jsonRootPath) :
  jsonRootPath(jsonRootPath) 
{
  LoadJson();
  ParseLayersDefs();
  iid = jsonRootData["iid"];
}

void Map::LoadJson() {
  std::ifstream file(jsonRootPath);
  if (!file.is_open()) {
    throw std::runtime_error("ERROR: Couldn't find Tileset [" + jsonRootPath.string() + "]\n");
  }
  file >> jsonRootData;
}

void Map::ParseLayersDefs() {
  if (jsonRootData.contains("defs") && !jsonRootData["defs"].empty()) {
    const auto& defs = jsonRootData["defs"];
    if (defs.contains("layers") && !defs["layers"].empty()) {
      const auto& layers = defs["layers"];
      for (const auto& layer : layers) {
        std::string type = layer["__type"];
        if (type == "IntGrid") {
          IntGridLayerDef layerDef(layer);
        }
      }
    }
  }
}

void Map::Init() {}
void Map::Draw() {}
