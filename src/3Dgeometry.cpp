#include "includes.hpp"

/*
* Takes an array of vertex, and rotates it by the given values.
*
* @param v: VertexArray -> The pointer of an array containing all the vertex in the figure.
* @param angle: double -> The amount of units you want to rotate your figure.
*
* @returns It saves in your vertex array the rotated figure.
*/
void rotate3D_x(vector<Vector3f>* v, double angle) {
  // TODO: Delete this matrix
  double RotationMatrix[4][4] = {
    {1,           0,          0, 0},
    {0,  cos(angle), sin(angle), 0},
    {0, -sin(angle), cos(angle), 0},
    {0,           0,          0, 0},
  };
  for(unsigned int i = 0; i < 4; i++) {
    double new_x = 0, new_y = 0, new_z = 0;
    for(unsigned int j = 0; j < 4; j++) {
      new_x += RotationMatrix[j][i] * (*v)[i].x;
      new_y += RotationMatrix[j][i] * (*v)[i].y;
      new_z += RotationMatrix[j][i] * (*v)[i].z;
    }
    (*v)[i] = Vector3f(new_x, new_y, new_z);
  }
}

/*
* Takes an array of vertex, and rotates it by the given values.
*
* @param v: VertexArray -> The pointer of an array containing all the vertex in the figure.
* @param angle: double -> The amount of units you want to rotate your figure.
*
* @returns It saves in your vertex array the rotated figure.
*/
void rotate3D_y(vector<Vector3f>* v, double angle) {
  // TODO: Delete this matrix
  double RotationMatrix[4][4] = {
    { cos(angle), 0, sin(angle), 0},
    {          0, 1,          0, 0},
    {-sin(angle), 0, cos(angle), 0},
    {          0, 0,          0, 1},
  };
  for(unsigned int i = 0; i < 4; i++) {
    double new_x = 0, new_y = 0, new_z = 0;
    for(unsigned int j = 0; j < 4; j++) {
      new_x += RotationMatrix[j][i] * (*v)[i].x;
      new_y += RotationMatrix[j][i] * (*v)[i].y;
      new_z += RotationMatrix[j][i] * (*v)[i].z;
    }
    (*v)[i] = Vector3f(new_x, new_y, new_z);
  }
}

/*
* Takes an array of vertex, and rotates it by the given values.
*
* @param v: VertexArray -> The pointer of an array containing all the vertex in the figure.
* @param angle: double -> The amount of units you want to rotate your figure.
*
* @returns It saves in your vertex array the rotated figure.
*/
void rotate3D_z(vector<Vector3f>* v, double angle) {
  // TODO: Delete this matrix
  double RotationMatrix[4][4] = {
    {cos(angle), -sin(angle), 0, 0},
    {sin(angle),  cos(angle), 0, 0},
    {         0,           0, 1, 0},
    {         0,           0, 0, 1},
  };
  for(unsigned int i = 0; i < 4; i++) {
    double new_x = 0, new_y = 0, new_z = 0;
    for(unsigned int j = 0; j < 4; j++) {
      new_x += RotationMatrix[j][i] * (*v)[i].x;
      new_y += RotationMatrix[j][i] * (*v)[i].y;
      new_z += RotationMatrix[j][i] * (*v)[i].z;
    }
    (*v)[i] = Vector3f(new_x, new_y, new_z);
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
void translate3D(vector<Vector3f>* v, double x_t, double y_t, double z_t) {
  double TranslateMatrix[4][4] = {
    {  1,   0,   0, 0},
    {  0,   1,   0, 0},
    {  0,   0,   1, 0},
    {x_t, y_t, z_t, 1},
  };
  for(unsigned int i = 0; i < 4; i++) {
    double new_x = 0, new_y = 0, new_z = 0;
    for(unsigned int j = 0; j < 4; j++) {
      new_x += TranslateMatrix[j][i] * (*v)[i].x;
      new_y += TranslateMatrix[j][i] * (*v)[i].y;
      new_z += TranslateMatrix[j][i] * (*v)[i].z;
    }
    (*v)[i] = Vector3f(new_x, new_y, new_z);
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
void scale3D(vector<Vector3f>* v, double s_x, double s_y, double s_z) {
  double ScaleMatrix[4][4] = {
    { s_x,   0,   0, 0},
    {   0, s_y,   0, 0},
    {   0,   0, s_z, 0},
    {   0,   0,   0, 1},
  };
  for(unsigned int i = 0; i < 4; i++) {
    double new_x = 0, new_y = 0, new_z = 0;
    for(unsigned int j = 0; j < 4; j++) {
      new_x += ScaleMatrix[j][i] * (*v)[i].x;
      new_y += ScaleMatrix[j][i] * (*v)[i].y;
      new_z += ScaleMatrix[j][i] * (*v)[i].z;
    }
    (*v)[i] = Vector3f(new_x, new_y, new_z);
  }
}
