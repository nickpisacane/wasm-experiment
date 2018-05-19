#include <stdint.h>

#include "Rect.h"
#include "Vector2.h"
#include "Scene.h"
#include "BouncingRect.h"

BouncingRect::BouncingRect(
  int x, int y, uint32_t w, uint32_t h, uint32_t c, Vector2 v
) : Rect(x, y, w, h, c) {
  
  this->velocity = v;
} 

void BouncingRect::update(Scene& scene) {
  int x = this->position.x;
  int y = this->position.y;

  if (x <= 0 || x + this->width >= scene.width()) {
    this->velocity.x *= -1;
  }
  if (y <= 0 || y + this->height >= scene.height()) {
    this->velocity.y *= -1;
  }

  Object::update(scene);
}