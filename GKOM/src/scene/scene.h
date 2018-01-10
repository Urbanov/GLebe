#pragma once
#include <memory>
#include <vector>
#include "../model/model.h"
#include "../animation/animation.h"
#include "../light/light.h"
#include "../model/skybox.h"
#include "camera.h"

class Scene {
	friend class Renderer;

private:
	std::vector<std::shared_ptr<Model>> m_models;
	std::vector<std::shared_ptr<Light>> m_lights;
	std::vector<std::shared_ptr<Light>> m_controlled_lights;
	std::vector<std::shared_ptr<Animation>> m_animations;
	std::shared_ptr<Skybox> m_skybox;
	std::shared_ptr<Camera> m_camera;

public:
	void init();
	void tick(GLfloat delta);
	void moveForward(GLfloat delta);
	void moveBackward(GLfloat delta);
	void moveRight(GLfloat delta);
	void moveLeft(GLfloat delta);
	void moveUp(GLfloat delta);
	void moveDown(GLfloat delta);
	void lookAround(GLfloat x_delta, GLfloat y_delta);
	void lampsLighten(GLfloat delta);
	void lampsDarken(GLfloat delta);
};
