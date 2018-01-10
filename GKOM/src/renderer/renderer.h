#pragma once
#include "../scene/scene.h"
#include "../shader/shprogram.h"

class Renderer {
private:
	ShaderProgram m_scene_shader;
	ShaderProgram m_skybox_shader;

public:
	Renderer(ShaderProgram&& scene_shader, ShaderProgram&& skybox_shader);
	void render(const Scene& scene) const;
};
