#pragma once

template <typename Type>
class Attribute {
private:
	Type m_attribute;

public:
	explicit Attribute(const Type& attribute)
		: m_attribute(attribute)
	{}

	explicit Attribute(Type&& attribute)
		: m_attribute(attribute)
	{}

	virtual ~Attribute() = 0
	{}

	const Type& value() const
	{
		return m_attribute;
	}
};

class PositionAbsolute : public Attribute<glm::vec3> {
public:
	template <typename T>
	PositionAbsolute(T&& attribute)
		: Attribute(std::forward<T>(attribute))
	{}
};

class RotationAbsolute : public Attribute<glm::vec3> {
public:
	template <typename T>
	RotationAbsolute(T&& attribute)
		: Attribute(std::forward<T>(attribute))
	{}
};

class OpacityAbsolute : public Attribute<GLfloat> {
public:
	template <typename T>
	OpacityAbsolute(T&& attribute)
		: Attribute(std::forward<T>(attribute))
	{}
};

class DisplacementAbsolute : public Attribute<glm::vec2> {
public:
	template <typename T>
	DisplacementAbsolute(T&& attribute)
		: Attribute(std::forward<T>(attribute))
	{}
};

class PositionRelative : public Attribute<glm::vec3> {
public:
	template <typename T>
	PositionRelative(T&& attribute)
		: Attribute(std::forward<T>(attribute))
	{}
};

class RotationRelative : public Attribute<glm::vec3> {
public:
	template <typename T>
	RotationRelative(T&& attribute)
		: Attribute(std::forward<T>(attribute))
	{}
};

class OpacityRelative : public Attribute<GLfloat> {
public:
	template <typename T>
	OpacityRelative(T&& attribute)
		: Attribute(std::forward<T>(attribute))
	{}
};

class DisplacementRelative : public Attribute<glm::vec2> {
public:
	template <typename T>
	DisplacementRelative(T&& attribute)
		: Attribute(std::forward<T>(attribute))
	{}
};
