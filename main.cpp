#include <iostream>
#include <raylib.h>

int main(int argno, char** args){
  const int screen_width = 1024;
  const int screen_hieght = 768;
  InitWindow(screen_width, screen_hieght, "Synth");
  SetTargetFPS(60);

  while(WindowShouldClose() == false){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Synth", 100, 100, 20, RED);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
