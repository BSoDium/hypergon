#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>

struct Color
{
  float r;
  float g;
  float b;
  float a;

  /**
   * Create a new empty color instance (default: black).
   */
  Color()
  {
    this->r = 0.0f;
    this->g = 0.0f;
    this->b = 0.0f;
    this->a = 1.0f;
  }

  /**
   * Create a new color instance from its rgba values.
   */
  Color(float r, float g, float b, float a)
  {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
  }

  /**
   * Create a new color instance from its hex value.
   */
  Color(std::string hex)
  {
    this->r = std::stoi(hex.substr(1, 2), 0, 16) / 255.0f;
    this->g = std::stoi(hex.substr(3, 2), 0, 16) / 255.0f;
    this->b = std::stoi(hex.substr(5, 2), 0, 16) / 255.0f;
    this->a = std::stoi(hex.substr(7, 2), 0, 16) / 255.0f;
  }
};

#endif // COLOR_HPP