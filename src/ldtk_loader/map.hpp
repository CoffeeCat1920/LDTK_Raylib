#pragma once

#include "ldtk_loader/def/layer/intGrid.hpp"
#include "nlohmann/json_utils.hpp"
#include <filesystem>
#include <string>
#include <vector>

class Map {
  
private:
  std::filesystem::path jsonRootPath;
  json jsonRootData;

  std::string iid;

  std::vector<IntGridLayerDef> inGridLayersDefs;

  void LoadJson();
  void ParseLayersDefs();

public:

  Map(std::filesystem::path jsonRootPath);
  
  void Init();
  void Draw();
};
