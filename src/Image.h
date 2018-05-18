#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <stdint.h>

class Image {
public:
  Image(uint32_t width, uint32_t height);
  ~Image();
  uint32_t width();
  uint32_t height();
  uint8_t* buffer();
  uint32_t bufferLength();
  bool set(uint32_t x, uint32_t y, uint32_t rgba);
  uint32_t get(uint32_t x, uint32_t y);
private:
  uint32_t _width;
  uint32_t _height;
  uint8_t* _buffer;
};

#endif