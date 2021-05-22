// #include <bits/stdc++.h>
// #include <SFML/Graphics.hpp>

// using namespace std;
// using namespace sf;

// void testDrawAffineCombination(RenderWindow* screen) {
//   Vector2f p0(0, 100), p00(50, 50), p000(100, 100);

//   unsigned int iters1 = 1;
//   VertexArray curveArray1(LineStrip);
//   drawAffineCombination(&curveArray1, p0, p00, p000, iters1);
//   printVertexArray(&curveArray1);
//   (*screen).draw(curveArray1);

//   Vector2f p1(100, 100), p2(150, 50), p3(200, 100);

//   unsigned int iters2 = 2;
//   VertexArray curveArray2(LineStrip);
//   drawAffineCombination(&curveArray2, p1, p2, p3, iters2);
//   printVertexArray(&curveArray2);
//   (*screen).draw(curveArray2);

//   Vector2f p4(200, 100), p5(250, 50), p6(300, 100);

//   unsigned int iters3 = 3;
//   VertexArray curveArray3(LineStrip);
//   drawAffineCombination(&curveArray3, p4, p5, p6, iters3);
//   printVertexArray(&curveArray3);
//   (*screen).draw(curveArray3);

//   Vector2f p7(300, 100), p8(350, 50), p9(400, 100);

//   unsigned int iters4 = 4;
//   VertexArray curveArray4(LineStrip);
//   drawAffineCombination(&curveArray4, p7, p8, p9, iters4);
//   printVertexArray(&curveArray4);
//   (*screen).draw(curveArray4);

//   Vector2f p10(400, 100), p11(450, 50), p12(500, 100);

//   unsigned int iters5 = 5;
//   VertexArray curveArray5(LineStrip);
//   drawAffineCombination(&curveArray5, p10, p11, p12, iters5);
//   printVertexArray(&curveArray5);
//   (*screen).draw(curveArray5);

//   Vector2f p13(500, 100), p14(550, 50), p15(600, 100);

//   unsigned int iters100 = 100;
//   VertexArray curveArray100(LineStrip);
//   drawAffineCombination(&curveArray100, p13, p14, p15, iters100);
//   // printVertexArray(&curveArray100);
//   (*screen).draw(curveArray100);
// }