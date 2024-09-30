#include <iostream>
#include <cmath>
#include <vector>

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
  int direction = 1;
  InitWindow(screen_width, screen_hieght, "Synth");
  SetTargetFPS(60);

  Oscillator osc = { .phase = 0.0f };
  float signal[1024];  // should change to std::vector
  float frequency = 1;
  unsigned int sample_rate = screen_width;
  float sample_duration = (1.0f/sample_rate);

  while(WindowShouldClose() == false){
    UpdateSignal(signal, frequency, sample_duration);
    if(frequency>= 10){
      direction = -1;
    }else if(frequency <= 1){
      direction = 1;
    }
    frequency += (direction * 0.05f);
    BeginDrawing();
    ClearBackground(WHITE);

    for(int i = 0; i<std::end(signal)-std::begin(signal); i+=1){
      DrawPixel(i, (screen_hieght/2) + (int)(signal[i] * (double)100), BLACK);
    }
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
