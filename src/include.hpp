#ifndef INCLUDE
#define INCLUDE

// Imports all libraries and namespaces
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

// // Imports all local files
// #include "curves.hpp"
// #include "helpers.hpp"
// #include "2Dgeometry.hpp"

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

// Curves cpp
void quadraticBezier(VertexArray* v, Vector2f p1, Vector2f p2, Vector2f p3, unsigned int it);
void cubicBezier(VertexArray* v, Vector2f p1, Vector2f p2, Vector2f p3, Vector2f p4, unsigned int it);
void chaikinsAlgorithm(VertexArray &v, unsigned int it) {

// Helpers cpp
void printVertexArray(VertexArray &v);
Vertex* drawLine(Vertex* v, pair<double, double> &p1, pair<double, double> &p2);
Vector2f getVectorPercentage(Vector2f v1, Vector2f v2, double p);

// 2D geometry cpp
void rotate2D(VertexArray* v, double angle);
void translate2D(VertexArray* v, double x_t, double y_t);
void scale2D(VertexArray* v, double s_x, double s_y);

#endif