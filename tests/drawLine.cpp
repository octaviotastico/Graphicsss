#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "tests.h"

void testDrawLine(RenderWindow* screen) {
  Vertex line1[2];
  drawLine((Vertex*)line1, 0, 0, 100, 100);
  (*screen).draw(line1, 2, Lines);

  Vertex line2[2];
  drawLine((Vertex*)line2, 100, 100, 200, 0);
  (*screen).draw(line2, 2, Lines);

  Vertex line3[2];
  drawLine((Vertex*)line3, 200, 0, 300, 100);
  (*screen).draw(line3, 2, Lines);

  Vertex line4[2];
  drawLine((Vertex*)line4, 300, 100, 400, 0);
  (*screen).draw(line4, 2, Lines);
}