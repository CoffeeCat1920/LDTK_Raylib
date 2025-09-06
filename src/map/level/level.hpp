#pragma once

#include "map/layers/intGrid.hpp"
#include "nlohmann/json_utils.hpp"
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
  std::vector<IntGrid::Layer> intGridLayers;
  Neighbour neighbour;

public:
  Level(json levelData);  
};
