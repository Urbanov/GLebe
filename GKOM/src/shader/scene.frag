#version 330 core
#define LIGHTS 3

out vec4 color;

struct Material {
	sampler2D diffuse;
	vec2 displacement;
	vec3 specular;
	float shininess;
	float opacity;
};

struct Light {
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float intensity;
	float constant;
	float linear;
	float quadratic;
};

in vec2 vTexCoord;
in vec3 vNormal;
in vec3 vFragPosition;

uniform vec3 viewPosition;
uniform Material material;
uniform Light lights[LIGHTS];

vec3 calculateLight(Light light, vec3 norm, vec3 viewDirection)
{
	vec3 lightDirection = normalize(light.position - vFragPosition);
	vec3 reflectDirection = reflect(-lightDirection, norm);

	vec3 ambient = light.ambient * texture(material.diffuse, vTexCoord + material.displacement).rgb;
	vec3 diffuse = light.diffuse * max(dot(norm, lightDirection), 0.0) * texture(material.diffuse, vTexCoord + material.displacement).rgb;
	vec3 specular = light.specular * pow(max(dot(viewDirection, reflectDirection), 0.0), material.shininess) * material.specular;

	float distance = length(light.position - vFragPosition);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	//float attenuation = 1.0f / (light.constant);

	ambient *= attenuation;
	diffuse *= attenuation * light.intensity;
	specular *= attenuation * light.intensity;

	return (ambient + diffuse + specular);
}

void main()
{
	vec3 norm = normalize(vNormal);
	vec3 viewDirection = normalize(viewPosition - vFragPosition);

	vec3 lightSum = vec3(0.0);
	for (int i = 0; i < LIGHTS; ++i) {
		lightSum += calculateLight(lights[i], norm, viewDirection);
	}
	color = vec4(lightSum, material.opacity);
}