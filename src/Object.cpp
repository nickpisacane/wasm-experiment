#include "Vector2.h"
#include "Object.h"

Object::Object() : Object(0, 0) {}

Object::Object(int x, int y) :
  position(x, y),
  velocity(0, 0),
  acceleration(0, 0) {
}

void Object::update() {
  this->velocity.add(this->acceleration);
  this->position.add(this->velocity);
}