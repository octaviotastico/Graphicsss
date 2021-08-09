#include "tests/test.hpp"

int main() {
  // Screen
  RenderWindow window(VideoMode(width, height), "cool graphicsss");
  // 60 FPS
  window.setFramerateLimit(FPSLimit);

  // Infinite loop so the screen won't close
  while (window.isOpen()) {

    // Testing drawLine
    testDrawLine(&window);

    // Testing quadraticBezier
    testQuadraticBezier(&window);

    // Testing cubicBezier
    testCubicBezier(&window);

    // Testing chaikransAlgorithm
    testChaikransAlgorithm(&window);

    // Displaying and then sleeping
    window.display();
    this_thread::sleep_for(chrono::milliseconds(5000));
    window.clear();
  }

  return 0;
}
