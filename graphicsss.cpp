#include "tests/tests.h"
#include "src/include.hpp"

int main() {
  // Screen
  RenderWindow graphic_screen(VideoMode(width, height), "cool graphicsss");
  // 60 FPS
  graphic_screen.setFramerateLimit(FPSLimit);
  // Testing drawLine
  testDrawLine(&graphic_screen);
  // Testing quadraticBezier
  testQuadraticBezier(&graphic_screen);
  // Testing cubicBezier
  testCubicBezier(&graphic_screen);
  // Showing stuff on screen
  graphic_screen.display();
  // Infinite loop so the screen won't close
  while (graphic_screen.isOpen());
  return 0;
}
