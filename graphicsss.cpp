/*

Used library:
- SFML: https://www.sfml-dev.org/documentation/2.5.1/

Compile:
- g++ -o a graphicsss.cpp -lsfml-graphics -lsfml-window -lsfml-system

Execute:
- ./a

*/

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// Screen Variables
int width = 1024;
int height = 768;
// int FPSLimit = 165;
int FPSLimit = 30;

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

void drawLine(Vertex* v, int x1, int y1, int x2, int y2) {
  v[0] = Vertex(Vector2f(x1, y1));
  v[1] = Vertex(Vector2f(x2, y2));
}

void drawAffineCombination(VertexArray* v, Vector2f p1, Vector2f p2, Vector2f p3, unsigned int it) {
  double t, t1, t2, t3;
  for (unsigned int i = 0; i < it + 1; i++) {
    t = (double)i / it;
    t1 = (1 - (2 * t) + (t * t));
    t2 = (2 * t) * (1 - t);
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

void printVertexArray(VertexArray* v) {
  cout<<"---SIZE---"<<endl;
  for(size_t i = 0; i < (*v).getVertexCount(); i++) {
    cout << "VertexArray[" << i << "] = (" << (*v)[i].position.x << ", " << (*v)[i].position.y << ")" << endl;
  }
}

void testDrawLine(RenderWindow* screen) {
  Vertex line[2];
  int x1 = 10, y1 = 10, x2 = 100, y2 = 100;
  drawLine((Vertex*)line, x1, y1, x2, y2);
  (*screen).draw(line, 2, Lines);
}

void testDrawAffineCombination(RenderWindow* screen) {
  Vector2f p0(0, 100), p00(50, 50), p000(100, 100);

  unsigned int iters1 = 1;
  VertexArray curveArray1(LineStrip);
  drawAffineCombination(&curveArray1, p0, p00, p000, iters1);
  printVertexArray(&curveArray1);
  (*screen).draw(curveArray1);

  Vector2f p1(100, 100), p2(150, 50), p3(200, 100);

  unsigned int iters2 = 2;
  VertexArray curveArray2(LineStrip);
  drawAffineCombination(&curveArray2, p1, p2, p3, iters2);
  printVertexArray(&curveArray2);
  (*screen).draw(curveArray2);

  Vector2f p4(200, 100), p5(250, 50), p6(300, 100);

  unsigned int iters3 = 3;
  VertexArray curveArray3(LineStrip);
  drawAffineCombination(&curveArray3, p4, p5, p6, iters3);
  printVertexArray(&curveArray3);
  (*screen).draw(curveArray3);

  Vector2f p7(300, 100), p8(350, 50), p9(400, 100);

  unsigned int iters4 = 4;
  VertexArray curveArray4(LineStrip);
  drawAffineCombination(&curveArray4, p7, p8, p9, iters4);
  printVertexArray(&curveArray4);
  (*screen).draw(curveArray4);

  Vector2f p10(400, 100), p11(450, 50), p12(500, 100);

  unsigned int iters5 = 5;
  VertexArray curveArray5(LineStrip);
  drawAffineCombination(&curveArray5, p10, p11, p12, iters5);
  printVertexArray(&curveArray5);
  (*screen).draw(curveArray5);

  Vector2f p13(500, 100), p14(550, 50), p15(600, 100);

  unsigned int iters100 = 100;
  VertexArray curveArray100(LineStrip);
  drawAffineCombination(&curveArray100, p13, p14, p15, iters100);
  // printVertexArray(&curveArray100);
  (*screen).draw(curveArray100);
}

int main() {
  // 60 FPS broder
  graphic_screen.setFramerateLimit(FPSLimit);

  // Testing drawLine
  testDrawLine(&graphic_screen);

  // Testing drawAffineCombination
  testDrawAffineCombination(&graphic_screen);

  // Showing stuff on screen
  graphic_screen.display();

  // Infinite loop so the screen won't close
  while (graphic_screen.isOpen());

  return 0;
}
