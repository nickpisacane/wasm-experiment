#include <emscripten.h>

#include "Scene.h"
#include "BouncingRect.h"
#include "Vector2.h"

Scene scene(600, 400);

EM_JS(void, js_init_image_data, (uint8_t* p, int o, int w, int h), {
  var arr = new Uint8ClampedArray(Module.wasmMemory.buffer, p, o);
  window.$imageData = new ImageData(arr, w, h);
});

EM_JS(void, js_render_image_data, (), {
  window.$ctx.putImageData(window.$imageData, 0, 0);
});

void initScene() {
  scene.setBackgroundColor(0x1b1b1cff);
  scene.add(new BouncingRect(400, 100, 100, 100, 0x76ff03ff, Vector2(-5, -2)));
  scene.add(new BouncingRect(10, 10, 50, 50, 0x304ffeff, Vector2(-4, 3)));
  scene.add(new BouncingRect(20, 20, 25, 25, 0xdd2c00ff, Vector2(-3, -6)));
  js_init_image_data(
    scene.image->buffer(),
    scene.image->bufferLength(),
    scene.width(),
    scene.height()
  );
}

void render() {
  scene.render();
  js_render_image_data();
}

int main() {
  initScene();
  emscripten_set_main_loop(render, 60, 1);
}