#include "map.hpp"
#include <filesystem>
#include <fstream>


Map::Map(std::filesystem::path jsonRootPath) :
  jsonRootPath(jsonRootPath) {
    LoadJson();
    iid = jsonRootData["iid"];
  }

void Map::LoadJson() {
  std::ifstream file(jsonRootPath);
  if (!file.is_open()) {
    throw std::runtime_error("ERROR: Couldn't find Tileset [" + jsonRootPath.string() + "]\n");
  }
  file >> jsonRootData;
}

void Map::Init() {}
void Map::Draw() {}
