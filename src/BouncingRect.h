#ifndef __BOUNCING_RECT_H__
#define __BOUNCING_RECT_H__

#include <stdint.h>

#include "Rect.h"
#include "Vector2.h"
#include "Scene.h"

class BouncingRect : public Rect {
public:
  BouncingRect(int x, int y, uint32_t w, uint32_t h, uint32_t c, Vector2 v);

  virtual void update(Scene& scene);
};

#endif