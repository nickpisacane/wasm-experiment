#include <stdint.h>
#include <vector>

#include "Image.h"
#include "Object.h"
#include "Scene.h"

Scene::Scene(uint32_t width, uint32_t height) :
  image(nullptr),
  _bg(0, 0, width, height, 0xffffffff),
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
  this->_bg.draw(*this->image);
  for (Object* obj : this->objects) {
    obj->update(*this);
    obj->draw(*this->image);
  }
}

void Scene::add(Object* obj) {
  this->objects.push_back(obj);
}

uint32_t Scene::width() {
  return this->_width;
}

uint32_t Scene::height() {
  return this->_height;
}

void Scene::setBackgroundColor(uint32_t bg) {
  this->_bg.color = bg;
}