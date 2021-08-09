#include "includes.hpp"

/*
* Takes an array of vertex, and rotates it by the given values.
*
* @param v: VertexArray -> The pointer of an array containing all the vertex in the figure.
* @param angle: double -> The amount of units you want to rotate your figure.
*
* @returns It saves in your vertex array the rotated figure.
*/
void rotate2D(VertexArray* v, double angle) {
  // TODO: Delete this matrix
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

/*
* Takes an array of vertex, and translates it by the given values.
*
* @param v: VertexArray -> The pointer of an array containing all the vertex in the figure.
* @param x: double -> The amount of units you want to translate your figure on the x axis.
* @param y: double -> The amount of units you want to translate your figure on the y axis.
*
* @returns It saves in your vertex array the translated figure.
*/
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

/*
* Takes an array of vertex, and scales it by the given values.
*
* @param v: VertexArray -> The pointer of an array containing all the vertex in the figure.
* @param x: double -> The amount of units you want to scale your figure on the x axis.
* @param y: double -> The amount of units you want to scale your figure on the y axis.
*
* @returns It saves in your vertex array the scaled figure.
*/
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
