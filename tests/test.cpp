#include "test.hpp"

void testDrawLine(RenderWindow* screen) {
  printText(screen, "Drawing Lines", Vector2f(200, 10), Color::Magenta, Text::Bold);
  pair <double, double> point_1, point_2;
  VertexArray v(LinesStrip);
  Vertex *line;

  for (int i = 0; i < 6; i++) {
    double x1, y1, x2, y2;
    x1 = 100.0 * i;
    y1 = 150.0;
    if (i % 2) y1 = 50.0;
    x2 = x1 + 100.0;
    y2 = 50.0;
    if (i % 2) y2 = 150.0;

    point_1 = make_pair(x1, y1);
    point_2 = make_pair(x2, y2);
    line = drawLine(point_1, point_2);
    v.append(line[0]);
    v.append(line[1]);
  }

  paintLine(v, Color::Blue);

  (*screen).draw(v);
}

void testQuadraticBezier(RenderWindow* screen) {
  printText(screen, "Quadratic Bezier", Vector2f(200, 180), Color::Magenta, Text::Bold);
  for (int i = 0; i < 7; i++) {
    unsigned int iters = i + 1;
    VertexArray curveArray(LineStrip);
    Vector2f point_1, point_2, point_3;
    point_1 = Vector2f(100.0 * i +   0.0, 250.0);
    point_2 = Vector2f(100.0 * i +  50.0, 200.0);
    point_3 = Vector2f(100.0 * i + 100.0, 250.0);

    quadraticBezier(curveArray, point_1, point_2, point_3, iters, false);
    paintLine(curveArray, Color::Blue);
    (*screen).draw(curveArray);
  }
}

void testCubicBezier(RenderWindow* screen) {
  printText(screen, "Cubic Bezier", Vector2f(200, 280), Color::Magenta, Text::Bold);
  for (int i = 0; i < 7; i++) {
    unsigned int iters = i + 3;
    VertexArray curveArray(LineStrip);
    Vector2f point_1, point_2, point_3, point_4;
    point_1 = Vector2f(100.0 * i,         360.0);
    point_2 = Vector2f(100.0 * i,         310.0);
    point_3 = Vector2f(100.0 * i + 100.0, 310.0);
    point_4 = Vector2f(100.0 * i + 100.0, 360.0);

    cubicBezier(curveArray, point_1, point_2, point_3, point_4, iters, false);
    paintLine(curveArray, Color::Blue);
    (*screen).draw(curveArray);
  }
}

void testChaikransAlgorithm(RenderWindow* screen) {
  printText(screen, "Chaikran's Algorithm", Vector2f(200, 400), Color::Magenta, Text::Bold);
  VertexArray v(LinesStrip);
  for (int i = 0; i < 7; i++) {
    v.append(Vertex(Vector2f(100.0 * i, 450.0 + 100.0 * (i%2))));
  }

  // Paint Rect
  paintLine(v, Color::Blue);
  (*screen).draw(v);

  // Run Chaikrans
  chaikinsAlgorithm(v, 2);

  // Paint Curve
  paintLine(v, Color::Magenta);
  (*screen).draw(v);
}