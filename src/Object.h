#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Image.h"

class Object {
public:
  virtual void draw(Image&) = 0;
};

#endif