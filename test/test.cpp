#include <stdint.h>
#include <iostream>
#include <iomanip>

#include "Scene.h"
#include "Image.h"
#include "Rect.h"

using namespace std;

#define P(c) (c & 0xff000000) >> 24, (c & 0xff0000) >> 16, (c & 0xff00) >> 8, c & 0xff
#define E 0, 0, 0, 0
#define W P(0xffffffff)
#define R P(0xff0000ff)
#define G P(0x00ff00ff)
#define B P(0x0000ffff)

#define TEST(name, funcCall) \
  do { \
    try { \
      funcCall; \
      cout << name << ": PASS" << endl; \
    } catch (const char* message) { \
      cout << name << " (FAIL): " << message << endl; \
    } \
  } while (0); \


bool compareBuffer(uint8_t* x, uint8_t* y, uint32_t len) {
  for (int i = 0; i < len; i++) {
    if (x[i] != y[i]) return false;
  }
  return true;
}

uint8_t basic_expected[4 * 4 * 4] = {
  E, E, E, E,
  E, R, R, E,
  E, R, R, E,
  E, E, E, E
};

void printBuffer(uint8_t* buf, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < 4 * width; j++) {
      cout << setw(3) << (int)buf[4 * width * i + j] << ' ';
    }
    cout << endl;
  }
}

void basicTest() {
  Scene s(4, 4);
  s.add(new Rect(1, 1, 2, 2, 0xff0000ff));
  s.render();
  uint8_t* buf = s.image->buffer();
  printBuffer(buf, 4, 4);
  cout << "---------------------" << endl;
  printBuffer(basic_expected, 4, 4);
  if (!compareBuffer(basic_expected, buf, 4 * 4 * 4)) {
    throw "Buffers are not equal.";
  }
}

void basicTestImage() {
  Image image(4, 4);
  image.set(1, 1, 0xff0000ff);
  image.set(1, 2, 0xff0000ff);
  image.set(2, 1, 0xff0000ff);
  image.set(2, 2, 0xff0000ff);
  uint8_t* buf = image.buffer();
  printBuffer(buf, 4, 4);
  cout << "---------------------" << endl;
  printBuffer(basic_expected, 4, 4);
  if (!compareBuffer(basic_expected, buf, 4 * 4 * 4)) {
    throw "Buffers are not equal.";
  }
}

int main() {
  TEST("basic (image)", basicTestImage());
  TEST("basic (scene)", basicTest());
}