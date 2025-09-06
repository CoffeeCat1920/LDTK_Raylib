#pragma once

#include "map/definations/definations.hpp"
#include "map/layers/intGrid.hpp"
#include "nlohmann/json_utils.hpp"
#include <map>
#include <string>
#include <vector>

enum Direction { e, w, n ,s };

struct Neighbour {
  std::string id;
  Direction dir;
};

class Level {
  
private:
  std::string id;

  std::map<uint32_t, IntGridDef> intGridDefs;
  std::map<std::string, IntGrid::Layer> intGridInstances;
  std::map<std::string, std::vector<Neighbour>> neighbours;

  void parseIntGridDefs(const json& defs);
  void parseIntGridInstances(const json& levels);
public:
  Level(const json& levelData);  

  void Draw();
};
