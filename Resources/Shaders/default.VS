#version 330 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec2 UVCoordinates;

out vec2 fragUVCoordinates;

uniform mat4 projection;
uniform mat4 view;

void main() {
   gl_Position = projection * view * vec4(vertexPosition, 1.0f);
   fragUVCoordinates = UVCoordinates;
}