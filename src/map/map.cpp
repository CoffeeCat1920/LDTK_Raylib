#include "map.hpp"

#include <fstream>

void Map::LoadJson() {
  std::ifstream file(jsonRootPath);
  if (!file.is_open()) {
    throw std::runtime_error("ERROR: Couldn't find Tileset [" + jsonRootPath.string() + "]\n");
  }

  file >> jsonRootData;
}

Map::Map(std::filesystem::path jsonRootPath) :
  jsonRootPath(jsonRootPath) {
    LoadJson(); 
  }

void Map::Init() {
  level.Init(jsonRootData); 
}
