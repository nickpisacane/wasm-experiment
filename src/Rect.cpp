#include <stdint.h>
#include <cmath>

#include "Object.h"
#include "Image.h"
#include "Rect.h"

Rect::Rect(int x, int y, uint32_t _width, uint32_t _height, uint32_t _color) :
  Object(x, y),
  width(_width),
  height(_height),
  color(_color) {
  
}

bool Rect::outOfBounds(Image& image) {
  return this->position.x > image.width() ||
    this->position.x <= -this->width ||
    this->position.y > image.height() ||
    this->position.y <= -this->height;
}

void Rect::draw(Image& image) {
  int x = fmax(0, this->position.x);
  int xs = this->position.x + this->width;
  int y = fmax(0, this->position.y);
  int ys = this->position.y + this->height;


  for (int i = x; i < xs; i++) {
    for (int j = y; j < ys; j++) {
      image.set(i, j, this->color);
    }
  }
}