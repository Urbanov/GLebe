#include "animation.h"

void Animation::apply(const KeyFrame& keyframe) const
{
	m_model->setPosition(keyframe.position)
		.setRotation(keyframe.rotation)
		.setOpacity(keyframe.opacity)
		.setTextureDisplacement(keyframe.displacement);
}

Animation::Animation(std::shared_ptr<Model> model)
	: m_model(std::move(model))
	, m_duration(0)
	, m_elapsed(0)
{}

Animation::Animation(std::shared_ptr<Model> model, GLfloat delay)
	: m_model(std::move(model))
	, m_duration(0)
	, m_elapsed(-delay)
{}

void Animation::tick(GLfloat delta)
{
	m_elapsed += delta;
	if (m_elapsed < 0) {
		return;
	}

	m_elapsed = fmod(m_elapsed, m_duration);
	for (auto frame = m_keyframes.begin(); frame != m_keyframes.end(); ++frame) {
		if (m_elapsed == frame->timestamp) {
			apply(*frame);
			break;
		}
		if (m_elapsed > frame->timestamp) {
			apply(KeyFrame::interpolate(*frame, *std::next(frame), m_elapsed));
		}
	}
}

Animation& Animation::setKeyFrames()
{
	m_keyframes.emplace_back(0.0f, m_model->getPosition(), m_model->getRotation(), m_model->getOpacity(), m_model->getTextureDisplacement());
	return *this;
}

void Animation::copyKeyFrames(const Animation& other)
{
	m_keyframes = other.m_keyframes;
	m_duration = other.m_duration;
}

template <>
void Animation::useAttribute(const PositionAbsolute& attribute)
{
	m_keyframes.back().position = attribute.value();
}

template <>
void Animation::useAttribute(const PositionRelative& attribute)
{
	m_keyframes.back().position += attribute.value();
}

template <>
void Animation::useAttribute(const RotationAbsolute& attribute)
{
	m_keyframes.back().rotation = attribute.value();
}

template <>
void Animation::useAttribute(const RotationRelative& attribute)
{
	m_keyframes.back().rotation += attribute.value();
}

template <>
void Animation::useAttribute(const OpacityAbsolute& attribute)
{
	m_keyframes.back().opacity = attribute.value();
}

template <>
void Animation::useAttribute(const OpacityRelative& attribute)
{
	m_keyframes.back().opacity += attribute.value();
}

template <>
void Animation::useAttribute(const DisplacementAbsolute& attribute)
{
	m_keyframes.back().displacement = attribute.value();
}

template <>
void Animation::useAttribute(const DisplacementRelative& attribute)
{
	m_keyframes.back().displacement += attribute.value();
}