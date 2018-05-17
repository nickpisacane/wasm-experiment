#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Image.h"
#include "Vector2.h"

class Object {
public:
  Object();
  Object(int x, int y);

  Vector2 position;
  Vector2 velocity;
  Vector2 acceleration;

  virtual void update();

  virtual bool outOfBounds(Image&) = 0;
  virtual void draw(Image&) = 0;
};

#endif