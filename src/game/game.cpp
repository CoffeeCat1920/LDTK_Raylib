#include "game.hpp"
#include "map/map.hpp"

Game::Game() :
  map("./assets/tileMap/test.json")
{} 

void Game::Init() {
  map.Init();
}
void Game::Update() {}

void Game::Draw() {
  map.Draw();
}
