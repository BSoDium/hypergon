#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>

/**
 * Set of coordinates in 4D space.
 * @todo: Add 4th dimension
 */
struct Vertex
{
  float x, y, z;
  float r, g, b;
  float nx, ny, nz;
  Vertex() : x(0.0f), y(0.0f), z(0.0f), r(1.0f), g(1.0f), b(1.0f), nx(0.0f), ny(1.0f), nz(0.0f) {}
  Vertex(float x, float y, float z) : x(x), y(y), z(z), r(1.0f), g(1.0f), b(1.0f), nx(0.0f), ny(1.0f), nz(0.0f) {}
  Vertex(float x, float y, float z, float r, float g, float b) : x(x), y(y), z(z), r(r), g(g), b(b), nx(0.0f), ny(1.0f), nz(0.0f) {}
  Vertex(float x, float y, float z, float r, float g, float b, float nx, float ny, float nz) : x(x), y(y), z(z), r(r), g(g), b(b), nx(nx), ny(ny), nz(nz) {}
  bool equals(Vertex v)
  {
    return x == v.x && y == v.y && z == v.z;
  }
  std::vector<float> getAttributes()
  {
    return {x, y, z, r, g, b, nx, ny, nz};
  }
  void setAttributes(std::vector<float> attributes)
  {
    x = attributes[0];
    y = attributes[1];
    z = attributes[2];
    r = attributes[3];
    g = attributes[4];
    b = attributes[5];
    nx = attributes[6];
    ny = attributes[7];
    nz = attributes[8];
  }
};

#endif // VERTEX_HPP