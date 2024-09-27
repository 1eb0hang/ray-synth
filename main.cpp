#include <iostream>
#include <cmath>

#include <raylib.h>

struct Oscillator{
  float phase;
};

void UpdateSignal(float* signal, float frequency, float sample_duration){
  for(int t = 0;t<1024; t+=1){
    signal[t] = sin(2.0f* M_PI  * frequency * sample_duration* (float)t);
  }
}

int main(int argno, char** args){
  const int screen_width = 1024;
  const int screen_hieght = 768;
  InitWindow(screen_width, screen_hieght, "Synth");
  SetTargetFPS(60);

  Oscillator osc = { .phase = 0.0f };
  float signal[1024];  // should change to std::vector
  float frequency = 5;
  unsigned int sample_rate = screen_width;
  float sample_duration = (1.0f/sample_rate);
  UpdateSignal(signal, frequency, sample_duration);

  while(WindowShouldClose() == false){
    BeginDrawing();
    ClearBackground(BLACK); 
    for(int i = 0; i<std::end(signal)-std::begin(signal); i+=1){
      DrawPixel(i, (screen_hieght/2) + (int)(signal[i] * (double)100), RED);
    }
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
