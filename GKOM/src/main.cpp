#include <iostream>
#include "shader/shprogram.h"
#include "scene/scene.h"
#include "window/window.h"
#include "renderer/renderer.h"

int main()
{
	auto info = R"(STEROWANIE:
- kamera przod/tyl/lewo/prawo: strzalki kierunkowe
- kamera gora/dol: page up/page down
- obrot kamery: lpm + przesuniecie
- zwiekszenie/zmniejszenie intensywnosci swiatla: a/z)";
	std::cout << info << std::endl;

	try {
		Window window(1280, 1024, "Projekt GKOM");
		Scene scene;
		Renderer renderer(
			ShaderProgram("src/Shader/scene.vert", "src/Shader/scene.frag"),
			ShaderProgram("src/Shader/skybox.vert", "src/Shader/skybox.frag")
		);
		
		scene.init();

		while (!window.shouldClose()) {
			// handle user input
			if (window.isKeyPressed(GLFW_KEY_UP)) {
				scene.moveForward(window.frameTime());
			}
			if (window.isKeyPressed(GLFW_KEY_DOWN)) {
				scene.moveBackward(window.frameTime());
			}
			if (window.isKeyPressed(GLFW_KEY_LEFT)) {
				scene.moveLeft(window.frameTime());
			}
			if (window.isKeyPressed(GLFW_KEY_RIGHT)) {
				scene.moveRight(window.frameTime());
			}
			if (window.isKeyPressed(GLFW_KEY_PAGE_UP)) {
				scene.moveUp(window.frameTime());
			}
			if (window.isKeyPressed(GLFW_KEY_PAGE_DOWN)) {
				scene.moveDown(window.frameTime());
			}
			if (window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
				scene.lookAround(window.getCursorOffsetX(), window.getCursorOffsetY());
			}
			if (window.isKeyPressed(GLFW_KEY_A)) {
				scene.lampsLighten(window.frameTime());
			}
			if (window.isKeyPressed(GLFW_KEY_Z)) {
				scene.lampsDarken(window.frameTime());
			}

			// run animations
			scene.tick(window.frameTime());

			// render scene
			renderer.render(scene);

			// prepare next frame
			window.nextFrame();
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
