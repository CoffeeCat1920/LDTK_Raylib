#pragma once

#include "map/map.hpp"

class Game {
  
private:
  Map map;
  
public:

  Game();

  void Init();
  void Update();
  void Draw();
};
