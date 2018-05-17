#include <stdint.h>
#include <vector>

#include "Image.h"
#include "Object.h"
#include "Scene.h"

Scene::Scene(uint32_t width, uint32_t height) :
  image(nullptr),
  objects() {

  this->resize(width, height);
}

Scene::~Scene() {
  delete this->image;
  for (Object* obj : this->objects) {
    delete obj;
  }
}

void Scene::resize(uint32_t width, uint32_t height) {
  if (this->image != nullptr) {
    delete this->image;
  }

  this->image = new Image(width, height);
  this->_width = width;
  this->_height = height;
}

void Scene::render() {
  for (Object* obj : this->objects) {
    obj->update();
    obj->draw(*this->image);
  }
}

uint32_t Scene::width() {
  return this->_width;
}

uint32_t Scene::height() {
  return this->_height;
}

void Scene::getImageData(uint8_t* image, uint32_t& offset) {
  image = this->image->buffer();
  offset = this->image->bufferLength();
}