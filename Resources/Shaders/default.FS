#version 330 core

const uint SPOT_LIGHTS = 1U;
const uint POINT_LIGHTS = 1U;

out vec4 outfragmentColor;

struct DirectionalLight {
   vec3 direction;

   vec3 color;

   float ambientIntensity;
   float diffuseIntensity;
   float specularIntensity;
};

struct PointLight {
   vec3 position;

   vec3 color;

   float ambientIntensity;
   float diffuseIntensity;
   float specularIntensity;

   float quadratic;
   float linear;
   float constant;
};

struct SpotLight {
   vec3 position;
   vec3 direction;

   float innerCutOff;
   float outerCutOff;

   vec3 color;

   float ambientIntensity;
   float diffuseIntensity;
   float specularIntensity;

   float quadratic;
   float linear;
   float constant;
};

in vec3 normal;
in vec3 fragmentPosition;
in vec2 fragmentTextureCoordinates;


uniform DirectionalLight directionalLight;
uniform PointLight pointLights[POINT_LIGHTS];
uniform SpotLight spotLights[SPOT_LIGHTS];

uniform sampler2D texture_0;

uniform vec3 viewPosition;

vec3 CalculateDirectionalLight(DirectionalLight light, vec3 viewDirection, vec3 inColor);
vec3 CalculatePointLight(PointLight light, vec3 viewDirection, vec3 inColor);
vec3 CalculateSpotLight(SpotLight light, vec3 viewDirection, vec3 inColor);

void main() {
   vec3 fragmentColor = vec3(texture(texture_0, fragmentTextureCoordinates));
   vec3 viewDirection = normalize(viewPosition - fragmentPosition);
   vec3 result = CalculateDirectionalLight(directionalLight, viewDirection, fragmentColor);
   result += CalculatePointLight(pointLights[0], viewDirection, fragmentColor);
   result += CalculateSpotLight(spotLights[0], viewDirection, fragmentColor);
   outfragmentColor = vec4(result, 1.0f);
}

vec3 CalculateDirectionalLight(DirectionalLight light, vec3 viewDirection, vec3 inColor) {
   vec3 ambient = light.color * light.ambientIntensity * inColor;
   vec3 diffuse = light.color * light.diffuseIntensity * inColor;
   vec3 specular = light.color * light.specularIntensity * inColor;

   diffuse *= max(dot(-light.direction, normal), 0.0f);

   vec3 reflectDirection = reflect(light.direction, normal);
   specular *= pow(max(dot(viewDirection, reflectDirection), 0.0f), 32);

   vec3 result = (ambient + diffuse + specular);
   return result;
}

vec3 CalculatePointLight(PointLight light, vec3 viewDirection, vec3 inColor) {
   vec3 ambient = light.color * light.ambientIntensity * inColor;
   vec3 diffuse = light.color * light.diffuseIntensity * inColor;
   vec3 specular = light.color * light.specularIntensity * inColor;

   vec3 lightDirection = normalize(fragmentPosition - light.position);
   diffuse *= max(dot(-lightDirection, normal), 0);

   vec3 reflectDirection = reflect(lightDirection, normal);
   specular *= pow(max(dot(viewDirection, reflectDirection), 0.0f), 32);

   float distance = distance(light.position, fragmentPosition);
   float attenuation = 1 / (light.quadratic * pow(distance, 2) + light.linear * distance + light.constant);
   
   vec3 result = (ambient + diffuse + specular) * attenuation;
   return result;
}

vec3 CalculateSpotLight(SpotLight light, vec3 viewDirection, vec3 inColor) {
   vec3 ambient = light.color * light.ambientIntensity * inColor;
   vec3 diffuse = light.color * light.diffuseIntensity * inColor;
   vec3 specular = light.color * light.specularIntensity * inColor;

   vec3 lightDirection = normalize(fragmentPosition - light.position);
   diffuse *= max(dot(-lightDirection, normal), 0);

   vec3 reflectDirection = reflect(lightDirection, normal);
   specular *= pow(max(dot(viewDirection, reflectDirection), 0.0f), 32);

   float distance = distance(light.position, fragmentPosition);
   float attenuation = 1 / (light.quadratic * pow(distance, 2) + light.linear * distance + light.constant);

   float theta = dot(lightDirection, light.direction);
   float epsilon = light.outerCutOff - light.innerCutOff;
   float intensity = clamp((light.outerCutOff - theta) / epsilon, 0.0f, 1.0f);

   vec3 result = (ambient + diffuse + specular) * attenuation * intensity;
   return result;
}