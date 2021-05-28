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
void drawAffineCombinationP3(VertexArray* v, Vector2f p1, Vector2f p2, Vector2f p3, unsigned int it, bool rewrite = false) {
  double t, t1, t2, t3;
  for (unsigned int i = 0; i < it + 1; i++) {
    t = (double)i / it;
    t1 = (1 - (2 * t) + (t * t));
    t2 = (2 * t * (1 - t));
    t3 = (t * t);

    if (rewrite) {
      (*v)[i].position = Vector2f(
        (t1 * p1.x) + (t2 * p2.x) + (t3 * p3.x),
        (t1 * p1.y) + (t2 * p2.y) + (t3 * p3.y)
      );
    } else {
      (*v).append(Vertex(Vector2f(
        (t1 * p1.x) + (t2 * p2.x) + (t3 * p3.x),
        (t1 * p1.y) + (t2 * p2.y) + (t3 * p3.y)
      )));
    }

  }
}

// Generates a curve given 4 points using an affine combination
void drawAffineCombinationP4(VertexArray* v, Vector2f p1, Vector2f p2, Vector2f p3, Vector2f p4, unsigned int it, bool rewrite = false) {
  double t, t1, t2, t3, t4;
  for (unsigned int i = 0; i < it + 1; i++) {
    t = (double)i / it;
    t1 = ((1 - t) * (1 - t) * (1 - t));
    t2 = (3 * t * ((1 - t) * (1 - t)));
    t3 = (3 * (t * t) * (1 - t));
    t4 = (t * t * t);

    if (rewrite) {
      (*v)[i].position = (Vector2f(
        (t1 * p1.x) + (t2 * p2.x) + (t3 * p3.x) + (t4 * p4.x),
        (t1 * p1.y) + (t2 * p2.y) + (t3 * p3.y) + (t4 * p4.y)
      ));
    } else {
      (*v).append(Vertex(Vector2f(
        (t1 * p1.x) + (t2 * p2.x) + (t3 * p3.x) + (t4 * p4.x),
        (t1 * p1.y) + (t2 * p2.y) + (t3 * p3.y) + (t4 * p4.y)
      )));
    }
  }
}

Vector2f getVectorPercentage(Vector2f v1, Vector2f v2, double p) {
  return (p * (v2 - v1)) + v1;
}

// Need to test thissss
void chaikinsAlgorithm(VertexArray* v, unsigned int it) {
  for (unsigned int i = 0; i < it; i++) {
    size_t v_sz = (*v).getVertexCount();
    VertexArray v_aux(LineStrip, v_sx * 2);
    for(unsigned int i = 0; i < v_sx - 1; i++) {
      v_aux.append(Vertex(getVectorPercentage((*v)[i], (*v)[i+1], 0.2)));
      v_aux.append(Vertex(getVectorPercentage((*v)[i], (*v)[i+1], 0.8)));
    }
    v = v_aux;
  }
}

void rotate2D(VertexArray* v, double angle) {
  // Need to delete this matrix, because its
  // slower (and stupid) to multiply this sh!t
  // instead of coming up with a better solution
  double RotationMatrix[3][3] = {
    { cos(angle), sin(angle), 0},
    {-sin(angle), cos(angle), 0},
    {          0,          0, 1}
  };
  for(unsigned int i = 0; i < 3; i++) {
    double new_x = 0, new_y = 0;
    for(unsigned int j = 0; j < 3; j++) {
      new_x += RotationMatrix[j][i] * (*v)[i].position.x;
      new_y += RotationMatrix[j][i] * (*v)[i].position.y;
    }
    (*v)[i] = Vertex(Vector2f(new_x, new_y));
  }
}

void translate2D(VertexArray* v, double x_t, double y_t) {
  double TranslateMatrix[3][3] = {
    {  1,   0, 0},
    {  0,   1, 0},
    {x_t, y_t, 1},
  };
  for(unsigned int i = 0; i < 3; i++) {
    double new_x = 0, new_y = 0;
    for(unsigned int j = 0; j < 3; j++) {
      new_x += TranslateMatrix[j][i] * (*v)[i].position.x;
      new_y += TranslateMatrix[j][i] * (*v)[i].position.y;
    }
    (*v)[i] = Vertex(Vector2f(new_x, new_y));
  }
}

void scale2D(VertexArray* v, double s_x, double s_y) {
  double ScaleMatrix[3][3] = {
    { s_x,   0, 0},
    {   0, s_y, 0},
    {   0,   0, 1},
  };
  for(unsigned int i = 0; i < 3; i++) {
    double new_x = 0, new_y = 0;
    for(unsigned int j = 0; j < 3; j++) {
      new_x += ScaleMatrix[j][i] * (*v)[i].position.x;
      new_y += ScaleMatrix[j][i] * (*v)[i].position.y;
    }
    (*v)[i] = Vertex(Vector2f(new_x, new_y));
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
