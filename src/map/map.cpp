#include <filesystem>
#include <fstream>

#include "map.hpp"
#include "nlohmann/json_utils.hpp"

json LoadJson(const std::filesystem::path& tileSetRelPath) {
  std::ifstream file(tileSetRelPath);
  if (!file.is_open()) {
    throw std::runtime_error("ERROR: Couldn't find Tileset [" + tileSetRelPath.string() + "]\n");
  }

  json mapData;
  file >> mapData;
  return mapData;
}

std::filesystem::path GetTilesetAbsolutePath(const json &mapData) {
  std::string tileSetSource = mapData["tilesets"][0]["source"].get<std::string>().replace(0, 2, "./assets/");
  return std::filesystem::path(tileSetSource);
}

Map::Map(std::filesystem::path tileSetRelPath) :
  tileSetRelPath(tileSetRelPath)
{
  json mapData = LoadJson(tileSetRelPath);
}
