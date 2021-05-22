#ifndef GRAPHICSSS
#define GRAPHICSSS

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void drawLine(Vertex* v, int x1, int y1, int x2, int y2);

void drawAffineCombinationP3(VertexArray* v, Vector2f p1, Vector2f p2, Vector2f p3, unsigned int it);

void drawAffineCombinationP4(VertexArray* v, Vector2f p1, Vector2f p2, Vector2f p3, Vector2f p4, unsigned int it);

void printVertexArray(VertexArray* v);

#endif