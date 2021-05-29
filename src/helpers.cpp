#include "include.hpp"

/*
* Prints a given VertexArray
*
* @param v: VertexArray -> The VertexArray you want to print.
*/
void printVertexArray(VertexArray &v) {
  size_t v_sz = v.getVertexCount();
  cout << "SIZE: " << v_sz << endl;
  cout << "ARRAY: " << endl;
  for(unsigned int i = 0; i < v_sz; i++) {
    cout << "V[" << i << "] = (" << v[i].position.x << ", " << v[i].position.y << ")" << endl;
  }
}

/*
* Returns a line
*
* @param v: pair<double, double> -> The first point on the line.
* @param p1: pair<double, double> -> The first point on the line.
* @param p2: pair<double, double> -> The last point on the line.
*
* @returns returns a Vertex array (i.e: a line)
*/
Vertex* drawLine(Vertex* v, pair<double, double> &p1, pair<double, double> &p2) {
  Vertex* line = (Vertex*)malloc(sizeof(Vertex));
  line[0] = Vertex(Vector2f(p1.first, p1.second));
  line[1] = Vertex(Vector2f(p2.first, p2.second));
  return line;
}

/*
* Takes an array of vertex, and rotates it by the given values.
*
* @param v1: Vector2d -> The Vertex v1.
* @param v2: Vector2d -> The Vertex v2.
* @param p: double -> The percentage you want to travel on the line.
*
* @returns It saves in your vertex array the rotated figure.
*/
Vector2f getVectorPercentage(Vector2f v1, Vector2f v2, float p) {
  return (p * (v2 - v1)) + v1;
}
Vector2f getVectorPercentage(Vertex v1, Vertex v2, float p) {
  return (p * (v2.position - v1.position)) + v1.position;
}
