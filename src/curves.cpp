#include "include.hpp"

/*
* Generates a cuadratic bezier curve given 3 points using an affine combination
*
* @param v: (VertexArray) The pointer of an array containing all the vertex in the figure.
* @param p1: (Vector2f) The Vertex p1 of the square.
* @param p2: (Vector2f) The Vertex p2 of the square.
* @param p3: (Vector2f) The Vertex p3 of the square.
* @param it: (unsigned int) The amount of iterations you want (the more iterations, more smooth the curve).
* @param rewrite: (bool) If true, it rewrites the content in v. If false, appends to v (for empty VertexArrays).
*
* @returns It saves in your vertex array the rotated figure.
*/
void quadraticBezier(VertexArray* v, Vector2f p1, Vector2f p2, Vector2f p3, unsigned int it, bool rewrite = false) {
  double t, t1, t2, t3;
  for (unsigned int i = 0; i < it + 1; i++) {
    t = (double)i / it;
    t1 = (1 - (2 * t) + (t * t));
    t2 = (2 * t * (1 - t));
    t3 = (t * t);

    if (rewrite) {
      (*v)[i].position = Vector2f(
        (t1 * p1.x) + (t2 * p2.x) + (t3 * p3.x),
        (t1 * p1.y) + (t2 * p2.y) + (t3 * p3.y)
      );
    } else {
      (*v).append(Vertex(Vector2f(
        (t1 * p1.x) + (t2 * p2.x) + (t3 * p3.x),
        (t1 * p1.y) + (t2 * p2.y) + (t3 * p3.y)
      )));
    }

  }
}

/*
* Generates a cubic bezier curve given 4 points using an affine combination
*
* @param v: (VertexArray) The pointer of an array containing all the vertex in the figure.
* @param p1: (Vector2f) The Vertex p1 of the square.
* @param p2: (Vector2f) The Vertex p2 of the square.
* @param p3: (Vector2f) The Vertex p3 of the square.
* @param p4: (Vector2f) The Vertex p4 of the square.
* @param it: (unsigned int) The amount of iterations you want (the more iterations, more smooth the curve).
* @param rewrite: (bool) If true, it rewrites the content in v. If false, appends to v (for empty VertexArrays).
*
* @returns It saves in your vertex array the rotated figure.
*/
void cubicBezier(VertexArray* v, Vector2f p1, Vector2f p2, Vector2f p3, Vector2f p4, unsigned int it, bool rewrite = false) {
  double t, t1, t2, t3, t4;
  for (unsigned int i = 0; i < it + 1; i++) {
    t = (double)i / it;
    t1 = ((1 - t) * (1 - t) * (1 - t));
    t2 = (3 * t * ((1 - t) * (1 - t)));
    t3 = (3 * (t * t) * (1 - t));
    t4 = (t * t * t);

    if (rewrite) {
      (*v)[i].position = (Vector2f(
        (t1 * p1.x) + (t2 * p2.x) + (t3 * p3.x) + (t4 * p4.x),
        (t1 * p1.y) + (t2 * p2.y) + (t3 * p3.y) + (t4 * p4.y)
      ));
    } else {
      (*v).append(Vertex(Vector2f(
        (t1 * p1.x) + (t2 * p2.x) + (t3 * p3.x) + (t4 * p4.x),
        (t1 * p1.y) + (t2 * p2.y) + (t3 * p3.y) + (t4 * p4.y)
      )));
    }
  }
}

/*
* Given a polygon <v>, this function slices off every corner <it> times, until you get a sufficiently smooth curve
*
* @param v: (VertexArray) The VertexArray containing all the vertex in the figure.
* @param it: (unsigned int) The amount of iterations you want (the more iterations, more smooth the curve).
*
* @returns It saves in your vertex array the rotated figure.
*/
void chaikinsAlgorithm(VertexArray &v, unsigned int it) {
  for (unsigned int i = 0; i < it; i++) {
    size_t v_sz = v.getVertexCount();
    // VertexArray v_aux(LineStrip, v_sz * 2);
    VertexArray v_aux(LineStrip);
    for(unsigned int i = 0; i < v_sz - 1; i++) {
      v_aux.append(Vertex(getVectorPercentage(v[i], v[i+1], 0.2)));
      v_aux.append(Vertex(getVectorPercentage(v[i], v[i+1], 0.8)));
    }
    swap(v, v_aux);
    v_aux.clear();
  }
}
