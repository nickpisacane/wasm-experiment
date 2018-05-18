#include <emscripten.h>

#include "Scene.h"
#include "Rect.h"

Scene scene(50, 50);

EM_JS(void, js_init_image_data, (uint8_t* p, int o, int w, int h), {
  var arr = new Uint8ClampedArray(Module.wasmMemory.buffer, p, o);
  console.log(p);
  window.$imageData = new ImageData(arr, w, h);
});

EM_JS(void, js_render_image_data, (), {
  window.$ctx.putImageData(window.$imageData, 0, 0);
});

void initScene() {
  scene.add(new Rect(0, 0, 10, 10, 0x00ff00ff));
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