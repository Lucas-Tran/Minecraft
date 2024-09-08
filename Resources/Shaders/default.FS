#version 330 core

out vec4 fragColor;

in vec2 fragUVCoordinates;

uniform sampler2D texture_0;

void main() {
   fragColor = texture(texture_0, fragUVCoordinates);//vec4(1.0f, 0.5f, 1.0f, 0.5f);
}