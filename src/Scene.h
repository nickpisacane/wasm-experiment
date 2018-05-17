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

  void getImageData(uint8_t* image, uint32_t& offset);
private:
  uint32_t _width;
  uint32_t _height;
  Image* image;
  std::vector<Object*> objects;
};

#endif