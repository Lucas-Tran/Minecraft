#version 330 core

out vec4 fragmentColor;

struct Light {
   vec3 direction;

   vec3 color;

   float ambientIntensity;
   float diffuseIntensity;
   float specularIntensity;
};

in vec3 outColor;
in vec3 normal;
in vec3 fragmentPosition;


uniform Light directionalLight;

uniform vec3 viewPosition;

vec3 CalculateDirectionalLight(Light light, vec3 inColor) {
   vec3 ambient = light.color * light.ambientIntensity * inColor;
   vec3 diffuse = light.color * light.diffuseIntensity * inColor;
   vec3 specular = light.color * light.specularIntensity * inColor;

   diffuse *= max(dot(-light.direction, normal), 0.0f);

   vec3 viewDirection = normalize(viewPosition - fragmentPosition);
   vec3 reflectDirection = reflect(light.direction, normal);
   specular *= pow(max(dot(viewDirection, reflectDirection), 0.0f), 32);

   return (ambient + diffuse + specular);
}

void main() {
   fragmentColor = vec4(CalculateDirectionalLight(directionalLight, outColor), 1.0f);
}