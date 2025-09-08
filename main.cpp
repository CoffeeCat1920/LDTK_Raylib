#include "include/core/settings.hpp"
#include "raylib/raylib.h"
#include "core/colors.hpp"

#include "game/game.hpp"

int main () {
  
  InitWindow( RENDERING_WIDTH, RENDERING_HEIGHT, "LDtk + Raylib");
  Game game;

  game.Init();

  while ( !WindowShouldClose() )
  { 

    game.Update();

    BeginDrawing();

    ClearBackground(GRUVBOX_DARK0);

    game.Draw();

    EndDrawing();
    
  }

  CloseWindow();

  return 0;
}
