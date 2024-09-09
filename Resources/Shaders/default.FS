#version 330 core

out vec4 fragColor;

in vec3 outColor;
in vec3 normal;

uniform sampler2D texture_0;

uniform vec3 lightDirection;

void main() {
   float intensity = max(0.0f, dot(normal, -lightDirection));
   fragColor = vec4(outColor * intensity, 1.0f);
}