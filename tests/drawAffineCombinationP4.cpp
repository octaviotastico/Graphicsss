#include "tests.h"

void testDrawAffineCombinationP4(RenderWindow* screen) {

  Vector2f p1(0, 250), p2(0, 200), p3(100, 200), p4(100, 250);

  unsigned int iters1 = 3;
  VertexArray curveArray1(LineStrip);
  drawAffineCombinationP4(&curveArray1, p1, p2, p3, p4, iters1);
  (*screen).draw(curveArray1);

  Vector2f p5(100, 250), p6(100, 200), p7(200, 200), p8(200, 250);

  unsigned int iters2 = 4;
  VertexArray curveArray2(LineStrip);
  drawAffineCombinationP4(&curveArray2, p5, p6, p7, p8, iters2);
  (*screen).draw(curveArray2);

  Vector2f p9(200, 250), p10(200, 200), p11(300, 200), p12(300, 250);

  unsigned int iters3 = 5;
  VertexArray curveArray3(LineStrip);
  drawAffineCombinationP4(&curveArray3, p9, p10, p11, p12, iters3);
  (*screen).draw(curveArray3);

  Vector2f p13(300, 250), p14(300, 200), p15(400, 200), p16(400, 250);

  unsigned int iters4 = 6;
  VertexArray curveArray4(LineStrip);
  drawAffineCombinationP4(&curveArray4, p13, p14, p15, p16, iters4);
  (*screen).draw(curveArray4);

}