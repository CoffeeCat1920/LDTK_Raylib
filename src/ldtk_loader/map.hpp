#pragma once

#include "nlohmann/json_utils.hpp"
#include <filesystem>
#include <string>

class Map {
  
private:
  std::filesystem::path jsonRootPath;
  json jsonRootData;

  std::string iid;

  void LoadJson();

public:

  Map(std::filesystem::path jsonRootPath);
  
  void Init();
  void Draw();
};
