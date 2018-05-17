#include <stdint.h>

#include "Image.h"

Image::Image(uint32_t width, uint32_t height) :
  _width(width),
  _height(height) {
  
  this->_buffer = new uint8_t[this->bufferLength()];
}

Image::~Image() {
  delete[] this->_buffer;
}

uint32_t Image::width() {
  return this->_width;
}

uint32_t Image::height() {
  return this->_height;
}

uint8_t* Image::buffer() {
  return this->_buffer;
}

uint32_t Image::bufferLength() {
  return 4 * this->_width * this->_height;
}

bool Image::set(uint32_t x, uint32_t y, uint32_t rgba) {
  if (x > this->_width || y >this->_height) {
    return false;
  }

  uint32_t index = 4 * (x + y * this->_width);
  
  this->_buffer[index] = rgba & 0xff000000 >> 24;
  this->_buffer[index] = rgba & 0x00ff0000 >> 16;
  this->_buffer[index] = rgba & 0x0000ff00 >> 8;
  this->_buffer[index] = rgba & 0x000000ff;

  return true;
}