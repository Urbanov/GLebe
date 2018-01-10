#pragma once
#include <vector>
#include "keyframe.h"
#include "../model/model.h"
#include "attribute.h"

class Animation {
private:
	std::shared_ptr<Model> m_model;
	std::vector<KeyFrame> m_keyframes;
	GLfloat m_duration;
	mutable GLfloat m_elapsed;

	void apply(const KeyFrame& keyframe) const;

public:
	explicit Animation(std::shared_ptr<Model> model);
	Animation(std::shared_ptr<Model> model, GLfloat delay);
	void tick(GLfloat delta);
	Animation& setKeyFrames();
	void copyKeyFrames(const Animation& other);

	template <typename Attribute>
	void useAttribute(Attribute& attribute);

	template <typename... Args> 
	Animation& operator()(GLfloat timestamp, Args&&... args)
	{
		if (timestamp > 0) {
			KeyFrame frame = m_keyframes.back();
			frame.timestamp = timestamp;
			m_keyframes.push_back(std::move(frame));
		}
		unpack(args...);
		m_duration = timestamp;
		return *this;
	}

	template <typename First, typename... Rest>
	void unpack(const First& attribute, const Rest&... args)
	{
		useAttribute(attribute);
		unpack(args...);
	}

	void unpack() const
	{
		// dummy
	}
};
