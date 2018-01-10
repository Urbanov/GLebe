#include "scene.h"
#include "parameters.h"
#include "../model/primitives.h"

void Scene::init()
{
	// camera
	m_camera = std::make_shared<Camera>(glm::vec3(CAMERA_X, CAMERA_Y, CAMERA_Z), CAMERA_YAW, CAMERA_PITCH);

	// lights
	auto sun = std::make_shared<Light>(glm::vec3(SUN_X, SUN_Y, SUN_Z));
	sun->setAmbientColor(glm::vec3(SUN_AMBIENT_R, SUN_AMBIENT_G, SUN_AMBIENT_B))
		.setDiffuseColor(glm::vec3(SUN_DIFFUSE_R, SUN_DIFFUSE_G, SUN_DIFFUSE_B))
		.setSpecularColor(glm::vec3(SUN_SPECULAR_R, SUN_SPECULAR_G, SUN_SPECULAR_B))
		.setIntensity(SUN_INTENSITY);
	m_lights.push_back(std::move(sun));

	auto lamp_primary = std::make_shared<Light>(glm::vec3(LAMP_X, LAMP_Y, LAMP_Z));
	lamp_primary->setAmbientColor(glm::vec3(LAMP_AMBIENT_R, LAMP_AMBIENT_G, LAMP_AMBIENT_B))
		.setDiffuseColor(glm::vec3(LAMP_DIFFUSE_R, LAMP_DIFFUSE_G, LAMP_DIFFUSE_B))
		.setSpecularColor(glm::vec3(LAMP_SPECULAR_R, LAMP_SPECULAR_G, LAMP_SPECULAR_B))
		.setAttenuation(LAMP_ATTENUATION_CONSTANT, LAMP_ATTENUATION_LINEAR, LAMP_ATTENUATION_QUADRATIC)
		.setIntensity(LAMP_INTENSITY);
	m_controlled_lights.push_back(lamp_primary);
	m_lights.push_back(std::move(lamp_primary));

	auto lamp_secondary = std::make_shared<Light>(glm::vec3(-LAMP_X, LAMP_Y, LAMP_Z));
	lamp_secondary->setAmbientColor(glm::vec3(LAMP_AMBIENT_R, LAMP_AMBIENT_G, LAMP_AMBIENT_B))
		.setDiffuseColor(glm::vec3(LAMP_DIFFUSE_R, LAMP_DIFFUSE_G, LAMP_DIFFUSE_B))
		.setSpecularColor(glm::vec3(LAMP_SPECULAR_R, LAMP_SPECULAR_G, LAMP_SPECULAR_B))
		.setAttenuation(LAMP_ATTENUATION_CONSTANT, LAMP_ATTENUATION_LINEAR, LAMP_ATTENUATION_QUADRATIC)
		.setIntensity(LAMP_INTENSITY);
	m_controlled_lights.push_back(lamp_secondary);
	m_lights.push_back(std::move(lamp_secondary));

	// skybox
	m_skybox = std::make_shared<Skybox>(SKY_TOP, SKY_BOTTOM, SKY_FRONT, SKY_BACK, SKY_LEFT, SKY_RIGHT);

	// base
	auto base = std::make_shared<Model>(
		Primitives::cube(BASE_WIDTH, BASE_HEIGHT, BASE_DEPTH),
		Material::create(BASE_TEXTURE, BASE_SHININESS, glm::vec3(BASE_SPECULAR_R, BASE_SPECULAR_G, BASE_SPECULAR_B))
	);
	m_models.push_back(std::move(base));

	// frame
	auto frame_left_support = std::make_shared<Model>(
		Primitives::cube(FRAME_SUPPORT_WIDTH, FRAME_SUPPORT_HEIGHT, FRAME_SUPPORT_DEPTH), 
		Material::create(FRAME_TEXTURE)
	);
	frame_left_support->setPosition(glm::vec3(FRAME_LEFT_SUPPORT_X, FRAME_LEFT_SUPPORT_Y, FRAME_LEFT_SUPPORT_Z));

	auto frame_right_support = std::make_shared<Model>(*frame_left_support);
	frame_right_support->setPosition(glm::vec3(FRAME_RIGHT_SUPPORT_X, FRAME_RIGHT_SUPPORT_Y, FRAME_RIGHT_SUPPORT_Z));

	auto frame_top = std::make_shared<Model>(
		Primitives::cube(FRAME_TOP_WIDTH, FRAME_TOP_HEIGHT, FRAME_TOP_DEPTH), 
		Material::create(FRAME_TEXTURE)
	);
	frame_top->setPosition(glm::vec3(FRAME_TOP_X, FRAME_TOP_Y, FRAME_TOP_Z));

	m_models.push_back(std::move(frame_left_support));
	m_models.push_back(std::move(frame_right_support));
	m_models.push_back(std::move(frame_top));

	// conveyor belt
	auto belt_front = std::make_shared<Model>(
		Primitives::cylinder(BELT_CORNER_RADIUS, BELT_CORNER_HEIGHT, BELT_CORNER_SEGMENTS),
		Material::create(BELT_CORNER_TEXTURE, BELT_SHININESS, glm::vec3(BELT_SPECULAR_R, BELT_SPECULAR_G, BELT_SPECULAR_B))
	);
	belt_front->setRotation(glm::vec3(BELT_CORNER_PITCH, BELT_CORNER_YAW, BELT_CORNER_ROLL))
		.setPosition(glm::vec3(BELT_CORNER_FRONT_X, BELT_CORNER_FRONT_Y, BELT_CORNER_FRONT_Z));

	auto belt_back = std::make_shared<Model>(*belt_front);
	belt_back->setPosition(glm::vec3(BELT_CORNER_BACK_X, BELT_CORNER_BACK_Y, BELT_CORNER_BACK_Z));

	auto belt_top = std::make_shared<Model>(
		Primitives::plane(BELT_WIDTH, BELT_HEIGHT),
		Material::create(BELT_TEXTURE, BELT_SHININESS, glm::vec3(BELT_SPECULAR_R, BELT_SPECULAR_G, BELT_SPECULAR_B))
	);
	belt_top->setRotation(glm::vec3(BELT_PITCH, BELT_YAW, BELT_ROLL))
		.setPosition(glm::vec3(BELT_TOP_X, BELT_TOP_Y, BELT_TOP_Z));

	auto belt_bottom = std::make_shared<Model>(*belt_top);
	belt_bottom->setPosition(glm::vec3(BELT_BOTTOM_X, BELT_BOTTOM_Y, BELT_BOTTOM_Z));

	auto pulley_front = std::make_shared<Model>(
		Primitives::cylinder(PULLEY_RADIUS, PULLEY_HEIGHT, PULLEY_SEGMENTS),
		Material::create(PULLEY_TEXTURE, PULLEY_SHININESS, glm::vec3(PULLEY_SPECULAR_R, PULLEY_SPECULAR_G, PULLEY_SPECULAR_B))
	);
	pulley_front->setRotation(glm::vec3(PULLEY_PITCH, PULLEY_YAW, PULLEY_ROLL))
		.setPosition(glm::vec3(PULLEY_FRONT_X, PULLEY_FRONT_Y, PULLEY_FRONT_Z));

	auto pulley_back = std::make_shared<Model>(*pulley_front);
	pulley_back->setPosition(glm::vec3(PULLEY_BACK_X, PULLEY_BACK_Y, PULLEY_BACK_Z));

	auto belt_front_anim = std::make_shared<Animation>(belt_front);
	belt_front_anim->setKeyFrames()(PULLEY_PERIOD, RotationRelative(glm::vec3(0.0f, 0.0f, 360.0f)));

	auto belt_back_anim = std::make_shared<Animation>(belt_back);
	belt_back_anim->setKeyFrames()(PULLEY_PERIOD, RotationRelative(glm::vec3(0.0f, 0.0f, 360.0f)));

	auto pulley_front_anim = std::make_shared<Animation>(pulley_front);
	pulley_front_anim->setKeyFrames()(PULLEY_PERIOD, RotationRelative(glm::vec3(0.0f, 0.0f, 360.0f)));

	auto pulley_back_anim = std::make_shared<Animation>(pulley_back);
	pulley_back_anim->setKeyFrames()(PULLEY_PERIOD, RotationRelative(glm::vec3(0.0f, 0.0f, 360.0f)));

	auto belt_top_anim = std::make_shared<Animation>(belt_top);
	belt_top_anim->setKeyFrames()(BELT_PERIOD, DisplacementAbsolute(glm::vec2(-1.0f, 0.0f)));

	auto belt_bottom_anim = std::make_shared<Animation>(belt_bottom);
	belt_bottom_anim->setKeyFrames()(BELT_PERIOD, DisplacementAbsolute(glm::vec2(1.0f, 0.0f)));

	m_models.push_back(std::move(belt_front));
	m_models.push_back(std::move(belt_back));
	m_models.push_back(std::move(belt_top));
	m_models.push_back(std::move(belt_bottom));
	m_models.push_back(std::move(pulley_front));
	m_models.push_back(std::move(pulley_back));

	m_animations.push_back(std::move(belt_front_anim));
	m_animations.push_back(std::move(belt_back_anim));
	m_animations.push_back(std::move(pulley_front_anim));
	m_animations.push_back(std::move(pulley_back_anim));
	m_animations.push_back(std::move(belt_top_anim));
	m_animations.push_back(std::move(belt_bottom_anim));

	// cylinder
	auto cylinder = std::make_shared<Model>(
		Primitives::cylinder(CYLINDER_RADIUS, CYLINDER_HEIGHT, CYLINDER_SEGMENTS),
		Material::create(CYLINDER_TEXTURE, CYLINDER_SHININESS, glm::vec3(CYLINDER_SPECULAR_R, CYLINDER_SPECULAR_G, CYLINDER_SPECULAR_B))
	);
	cylinder->setPosition(glm::vec3(CYLINDER_X, CYLINDER_Y, CYLINDER_Z))
		.setRotation(glm::vec3(CYLINDER_PITCH, CYLINDER_YAW, CYLINDER_ROLL));

	auto cylinder_anim = std::make_shared<Animation>(cylinder, CAN_UNDER_CYLINDER_TIMESTAMP - CYLINDER_STOP_TIMESTAMP);
	cylinder_anim->setKeyFrames()
		(CYLINDER_PUSH_TIMESTAMP)
		(CYLINDER_STOP_TIMESTAMP, PositionRelative(glm::vec3(0.0f, CYLINDER_Y_SHIFT, 0.0f)))
		(CYLINDER_RELEASE_TIMESTAMP)
		(CYLINDER_PERIOD, PositionRelative(glm::vec3(0.0f, -CYLINDER_Y_SHIFT, 0.0f)));

	m_models.push_back(std::move(cylinder));
	m_animations.push_back(std::move(cylinder_anim));

	// cans
	auto can_primary = std::make_shared<Model>(
		Primitives::cylinder(CAN_RADIUS, CAN_HEIGHT, CAN_SEGMENTS),
		Material::create(CAN_TEXTURE, CAN_SHININESS, glm::vec3(CAN_SPECULAR_R, CAN_SPECULAR_G, CAN_SPECULAR_B))
	);
	can_primary->setPosition(glm::vec3(CAN_X, CAN_Y, CAN_Z))
		.setRotation(glm::vec3(CAN_PITCH, CAN_YAW, CAN_ROLL))
		.setOpacity(0.0f);

	auto can_primary_anim = std::make_shared<Animation>(can_primary);
	can_primary_anim->setKeyFrames()
		(0, PositionRelative(glm::vec3(0, CAN_Y_SHIFT, 0)))
		(CAN_ON_GROUND_TIMESTAMP, PositionRelative(glm::vec3(0, -CAN_Y_SHIFT, 0)), OpacityAbsolute(1.0f))
		(CAN_UNDER_CYLINDER_TIMESTAMP, PositionRelative(glm::vec3(0, 0, CAN_Z_SHIFT)))
		(CAN_INVISIBLE_TIMESTAMP, OpacityAbsolute(0.0f))
		(CAN_PERIOD);

	auto can_secondary = std::make_shared<Model>(*can_primary);
	auto can_secondary_anim = std::make_shared<Animation>(can_secondary, CAN_PERIOD / 2);
	can_secondary_anim->copyKeyFrames(*can_primary_anim);

	m_models.push_back(std::move(can_primary));
	m_animations.push_back(std::move(can_primary_anim));
	m_models.push_back(std::move(can_secondary));
	m_animations.push_back(std::move(can_secondary_anim));

	// crushed cans
	auto crushed_can_primary = std::make_shared<Model>(
		Primitives::cylinder(CRUSHED_CAN_RADIUS, CRUSHED_CAN_HEIGHT, CRUSHED_CAN_SEGMENTS),
		Material::create(CAN_TEXTURE, CAN_SHININESS, glm::vec3(CAN_SPECULAR_R, CAN_SPECULAR_G, CAN_SPECULAR_B))
	);
	crushed_can_primary->setPosition(glm::vec3(CRUSHED_CAN_X, CRUSHED_CAN_Y, CRUSHED_CAN_Z))
		.setRotation(glm::vec3(CRUSHED_CAN_PITCH, CRUSHED_CAN_YAW, CRUSHED_CAN_ROLL))
		.setOpacity(0.0f);
	
	auto crushed_can_primary_anim = std::make_shared<Animation>(crushed_can_primary, CAN_UNDER_CYLINDER_TIMESTAMP);
	crushed_can_primary_anim->setKeyFrames()
		(0, OpacityAbsolute(1.0f))
		(CRUSHED_CAN_AT_EDGE_TIMESTAMP, PositionRelative(glm::vec3(0, 0, CRUSHED_CAN_Z_SHIFT)));
	for (int time = 1; time <= static_cast<GLint>(CRUSHED_CAN_FALL_TIME) * FALL_TIME_RESOLUTION; ++time) {
		GLfloat elapsed = static_cast<GLfloat>(time) / FALL_TIME_RESOLUTION;
		GLfloat quadratic_diff = elapsed * elapsed - (elapsed - 0.1f) * (elapsed - 0.1f);
		(*crushed_can_primary_anim)(
			elapsed + CRUSHED_CAN_AT_EDGE_TIMESTAMP,
			PositionRelative(glm::vec3(0, CRUSHED_CAN_Y_SHIFT * quadratic_diff, CRUSHED_CAN_Z_SHIFT / (CRUSHED_CAN_AT_EDGE_TIMESTAMP * FALL_TIME_RESOLUTION))),
			RotationRelative(glm::vec3(CRUSHED_CAN_FALL_PITCH / (CRUSHED_CAN_FALL_TIME * FALL_TIME_RESOLUTION), 0.0f, 0.0f)),
			OpacityRelative(-1.0f * quadratic_diff)
		);
	}
	(*crushed_can_primary_anim)(CRUSHED_CAN_PERIOD);

	auto crushed_can_secondary = std::make_shared<Model>(*crushed_can_primary);
	auto crushed_can_secondary_anim = std::make_shared<Animation>(crushed_can_secondary, CAN_UNDER_CYLINDER_TIMESTAMP + CRUSHED_CAN_PERIOD / 2);
	crushed_can_secondary_anim->copyKeyFrames(*crushed_can_primary_anim);
	
	m_models.push_back(std::move(crushed_can_primary));
	m_animations.push_back(std::move(crushed_can_primary_anim));
	m_models.push_back(std::move(crushed_can_secondary));
	m_animations.push_back(std::move(crushed_can_secondary_anim));
}

void Scene::tick(GLfloat delta)
{
	for (const auto& animation : m_animations) {
		animation->tick(delta);
	}
}

void Scene::moveForward(GLfloat delta)
{
	m_camera->forward(delta);
}

void Scene::moveBackward(GLfloat delta)
{
	m_camera->backward(delta);
}

void Scene::moveRight(GLfloat delta)
{
	m_camera->right(delta);
}

void Scene::moveLeft(GLfloat delta)
{
	m_camera->left(delta);
}

void Scene::moveUp(GLfloat delta)
{
	m_camera->up(delta);
}

void Scene::moveDown(GLfloat delta)
{
	m_camera->down(delta);
}

void Scene::lookAround(GLfloat x_delta, GLfloat y_delta)
{
	m_camera->rotate(x_delta, y_delta);
}

void Scene::lampsLighten(GLfloat delta)
{
	for (const auto& light : m_controlled_lights) {
		light->lighten(delta);
	}
}

void Scene::lampsDarken(GLfloat delta)
{
	for (const auto& light : m_controlled_lights) {
		light->darken(delta);
	}
}
