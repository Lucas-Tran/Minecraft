#version 330 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 color;
layout (location = 2) in vec3 inNormal;

out vec3 outColor;
out vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
   gl_Position = projection * view * model * vec4(vertexPosition, 1.0f);
   outColor = color;
   normal = normalize(transpose(inverse(mat3(model))) * inNormal);
}