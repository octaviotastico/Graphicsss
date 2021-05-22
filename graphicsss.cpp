/*
  Used library:
  - SFML: https://www.sfml-dev.org/documentation/2.5.1/

  Compile:
  - g++ -o a graphicsss.cpp -lsfml-graphics -lsfml-window -lsfml-system

  Execute:
  - ./a
*/

#include "graphicsss.hpp"
#include "tests/tests.h"

using namespace std;
using namespace sf;

// Screen Variables
int width = 1024;
int height = 768;
int FPSLimit = 30; // 165;

// Camera Variables
int cam_height = 1500;
int draw_distance = 2000;
float cam_depth = 1.0;

// Colors
Color black = Color(0, 0, 0);
Color white = Color(255, 255, 255);
Color dark_green = Color(0, 154, 0);
Color brigt_green = Color(16, 200, 16);
Color dark_gray = Color(107, 107, 107);
Color bright_gray = Color(105, 105, 105);

// Screen
RenderWindow graphic_screen(VideoMode(width, height), "cool graphicsss");

// Aux functions uwu
void printVertexArray(VertexArray* v) {
  cout<<"---SIZE---"<<endl;
  for(size_t i = 0; i < (*v).getVertexCount(); i++) {
    cout << "VertexArray[" << i << "] = (" << (*v)[i].position.x << ", " << (*v)[i].position.y << ")" << endl;
  }
}

// Just draws a line on screen
void drawLine(Vertex* v, int x1, int y1, int x2, int y2) {
  v[0] = Vertex(Vector2f(x1, y1));
  v[1] = Vertex(Vector2f(x2, y2));
}

// Generates a curve given 3 points using an affine combination
void drawAffineCombinationP3(VertexArray* v, Vector2f p1, Vector2f p2, Vector2f p3, unsigned int it) {
  double t, t1, t2, t3;
  for (unsigned int i = 0; i < it + 1; i++) {
    t = (double)i / it;
    t1 = (1 - (2 * t) + (t * t));
    t2 = (2 * t * (1 - t));
    t3 = (t * t);

    // This is the same, but I changed it because
    // previously, I needed to set the length of the
    // VertexArray when creating it. Instead of:
    // VertexArray curveArray(LineStrip);
    // I needed to add a second argument like this
    // VertexArray curveArray(LineStrip, 124);

    // (*v)[i].position = Vector2f(
    //   (t1 * p1.x) + (t2 * p2.x) + (t3 * p3.x),
    //   (t1 * p1.y) + (t2 * p2.y) + (t3 * p3.y)
    // );

    (*v).append(Vertex(Vector2f(
      (t1 * p1.x) + (t2 * p2.x) + (t3 * p3.x),
      (t1 * p1.y) + (t2 * p2.y) + (t3 * p3.y)
    )));
  }
}

// Generates a curve given 4 points using an affine combination
void drawAffineCombinationP4(VertexArray* v, Vector2f p1, Vector2f p2, Vector2f p3, Vector2f p4, unsigned int it) {
  double t, t1, t2, t3, t4;
  for (unsigned int i = 0; i < it + 1; i++) {
    t = (double)i / it;
    t1 = ((1 - t) * (1 - t) * (1 - t));
    t2 = (3 * t * ((1 - t) * (1 - t)));
    t3 = (3 * (t * t) * (1 - t));
    t4 = (t * t * t);

    (*v).append(Vertex(Vector2f(
      (t1 * p1.x) + (t2 * p2.x) + (t3 * p3.x) + (t4 * p4.x),
      (t1 * p1.y) + (t2 * p2.y) + (t3 * p3.y) + (t4 * p4.y)
    )));
  }
}

int main() {
  // 60 FPS broder
  graphic_screen.setFramerateLimit(FPSLimit);

  // Testing drawLine
  testDrawLine(&graphic_screen);

  // Testing drawAffineCombinationP3
  testDrawAffineCombinationP3(&graphic_screen);

  // Testing drawAffineCombinationP4
  testDrawAffineCombinationP4(&graphic_screen);

  // Showing stuff on screen
  graphic_screen.display();

  // Infinite loop so the screen won't close
  while (graphic_screen.isOpen());

  return 0;
}
