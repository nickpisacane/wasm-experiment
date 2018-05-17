#ifndef __VECTOR2_H__
#define __VECTOR2_H__

class Vector2 {
public:
  Vector2(int _x, int _y);

  int x;
  int y;

  double angleBetween(const Vector2& vector) const;
  double angle() const;
  int mag() const;
  void copy(Vector2& vector) const;
  int dot(const Vector2& vector) const;

  void add(const Vector2& vector);
  void sub(const Vector2& vector);
  void scale(int scalar);
  
};

#endif