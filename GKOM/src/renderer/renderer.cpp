#include "renderer.h"

Renderer::Renderer(ShaderProgram&& scene_shader, ShaderProgram&& skybox_shader)
	: m_scene_shader(scene_shader)
	, m_skybox_shader(skybox_shader)
{}

void Renderer::render(const Scene& scene) const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// skybox
	m_skybox_shader.Use();
	scene.m_camera->applyView(m_skybox_shader.get_programID());
	scene.m_skybox->render(m_skybox_shader.get_programID());

	// lights
	m_scene_shader.Use();
	scene.m_camera->applyView(m_scene_shader.get_programID());
	for (auto light : scene.m_lights) {
		light->render(m_scene_shader.get_programID());
	}

	// models
	std::vector<std::shared_ptr<Model>> transparent_models;
	for (const auto& model : scene.m_models) {
		if (model->getOpacity() < 1.0) {
			transparent_models.push_back(model);
		}
		else {
			model->render(m_scene_shader.get_programID());
		}
	}
	for (const auto& model : transparent_models) {
		model->render(m_scene_shader.get_programID());
	}
}