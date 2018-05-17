#ifndef __RECT_H__
#define __RECT_H__

#include <stdint.h>

#include "Image.h"
#include "Object.h"

class Rect : public Object {
public:
  Rect(int x, int y, uint32_t _width, uint32_t _height, uint32_t _color);
  
  uint32_t width;
  uint32_t height;
  uint32_t color;

  virtual bool outOfBounds(Image&);
  virtual void draw(Image& image);
};

#endif