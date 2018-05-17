#include <cmath>

#include "Vector2.h"

Vector2::Vector2(int _x, int _y) :
  x(_x),
  y(_y) {

}

// Copy the vector into a vector
void Vector2::copy(Vector2& vector) const {
  vector.x = this->x;
  vector.y = this->y;
}

// Positive angle between two vectors
double Vector2::angleBetween(const Vector2& vector) const {
  return acos((float)this->dot(vector) / (this->mag() * vector.mag()));
}

// Absolute angle between vector and x-axis
double Vector2::angle() const {
  double angle = atan2(this->y, this->x);
  
  if (angle < 0) {
    angle += 2 * M_PI;
  }

  return angle;
}

// Magnitude of Vector
int Vector2::mag() const {
  return pow(this->x, 2) + pow(this->y, 2);
}

// Dot product of the  vectors
int Vector2::dot(const Vector2& vector) const {
  return this->x * vector.x + this->y * vector.y;
}

// ADd a vector
void Vector2::add(const Vector2& vector) {
  this->x += vector.x;
  this->y += vector.y;
}

// Subtract a vector
void Vector2::sub(const Vector2& vector) {
  this->x -= vector.x;
  this->y -= vector.y;
}

// Scale the vector
void Vector2::scale(int scalar) {
  this->x *= scalar;
  this->y *= scalar;
}