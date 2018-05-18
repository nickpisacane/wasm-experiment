#ifndef __SCENE_H__
#define __SCENE_H__

#include <stdint.h>
#include <vector>

#include "Image.h"
#include "Object.h"

class Scene {
public:
  Scene(uint32_t width, uint32_t height);
  ~Scene();

  void resize(uint32_t width, uint32_t height);
  void render();
  void add(Object* obj);
  uint32_t width();
  uint32_t height();

  Image* image;
private:
  uint32_t _width;
  uint32_t _height;

  std::vector<Object*> objects;
};

#endif