#include "tests.h"

void testQuadraticBezier(RenderWindow* screen) {
  Vector2f p0(0, 175), p00(50, 125), p000(100, 175);

  unsigned int iters1 = 1;
  VertexArray curveArray1(LineStrip);
  quadraticBezier(curveArray1, p0, p00, p000, iters1);
  printVertexArray(curveArray1);
  (*screen).draw(curveArray1);

  Vector2f p1(100, 175), p2(150, 125), p3(200, 175);

  unsigned int iters2 = 2;
  VertexArray curveArray2(LineStrip);
  quadraticBezier(curveArray2, p1, p2, p3, iters2);
  printVertexArray(curveArray2);
  (*screen).draw(curveArray2);

  Vector2f p4(200, 175), p5(250, 125), p6(300, 175);

  unsigned int iters3 = 3;
  VertexArray curveArray3(LineStrip);
  quadraticBezier(curveArray3, p4, p5, p6, iters3);
  printVertexArray(curveArray3);
  (*screen).draw(curveArray3);

  Vector2f p7(300, 175), p8(350, 125), p9(400, 175);

  unsigned int iters4 = 4;
  VertexArray curveArray4(LineStrip);
  quadraticBezier(curveArray4, p7, p8, p9, iters4);
  printVertexArray(curveArray4);
  (*screen).draw(curveArray4);

  Vector2f p10(400, 175), p11(450, 125), p12(500, 175);

  unsigned int iters5 = 5;
  VertexArray curveArray5(LineStrip);
  quadraticBezier(curveArray5, p10, p11, p12, iters5);
  (*screen).draw(curveArray5);

  Vector2f p13(500, 175), p14(550, 125), p15(600, 175);

  unsigned int iters100 = 100;
  VertexArray curveArray100(LineStrip);
  quadraticBezier(curveArray100, p13, p14, p15, iters100);
  (*screen).draw(curveArray100);
}