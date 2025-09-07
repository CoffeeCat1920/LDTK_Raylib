#pragma once

#include "map/level/level.hpp"
#include "nlohmann/json_utils.hpp"
#include <filesystem>

class Map {
  
private:
  std::filesystem::path jsonRootPath;
  json jsonRootData; 
  Level level;
  
  void LoadJson(); 

public:

  Map(std::filesystem::path jsonRootPath);

  void Init();
}; 
