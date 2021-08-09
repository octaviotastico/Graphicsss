#ifndef INCLUDES
#define INCLUDES

// Imports all libraries and namespaces
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <chrono>
#include <thread>

// Namespaces used
using namespace std;
using namespace sf;

// 2D geometry cpp
void rotate2D(VertexArray* v, double angle);
void translate2D(VertexArray* v, double x_t, double y_t);
void scale2D(VertexArray* v, double s_x, double s_y);

// 3D geometry cpp
void rotate3D_x(vector<Vector3f>* v, double angle);
void rotate3D_y(vector<Vector3f>* v, double angle);
void rotate3D_z(vector<Vector3f>* v, double angle);
void translate3D(vector<Vector3f>* v, double x_t, double y_t, double z_t);
void scale3D(vector<Vector3f>* v, double s_x, double s_y);

// Curves cpp
void quadraticBezier(VertexArray &v, Vector2f p1, Vector2f p2, Vector2f p3, unsigned int it, bool rewrite);
void cubicBezier(VertexArray &v, Vector2f p1, Vector2f p2, Vector2f p3, Vector2f p4, unsigned int it, bool rewrite);
void chaikinsAlgorithm(VertexArray &v, unsigned int it);

// Helpers cpp
void printVertexArray(VertexArray &v);
Vertex* drawLine(pair<double, double> &p1, pair<double, double> &p2);
Vector2f getVectorPercentage(Vector2f v1, Vector2f v2, float p);
Vector2f getVectorPercentage(Vertex v1, Vertex v2, float p);
void paintLine(VertexArray &v, Color color);
void paintLineGradient(VertexArray &v, Color color1, Color color2, float p);
void printText(RenderWindow* window, string text, Vector2f position, Color color, Text::Style style);

///// Constants /////

// Screen Variables
const int width = 1024;
const int height = 768;
const int FPSLimit = 30; // 165;

// Camera Variables
const int cam_height = 1500;
const int draw_distance = 2000;
const float cam_depth = 1.0;

// Colors
const Color black = Color(0, 0, 0);
const Color white = Color(255, 255, 255);
const Color dark_green = Color(0, 154, 0);
const Color brigt_green = Color(16, 200, 16);
const Color dark_gray = Color(107, 107, 107);
const Color bright_gray = Color(105, 105, 105);

#endif