#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "stb_image.h"

const char *vertexShaderSource =
"#version 330 core\n"
"\n"
"layout (location = 0) in vec3 vertexPosition;\n"
"layout (location = 1) in vec2 UVCoordinates;\n"
"\n"
"out vec2 fragUVCoordinates;\n"
"\n"
"void main() {\n"
"   gl_Position = vec4(vertexPosition, 1.0f);\n"
"   fragUVCoordinates = UVCoordinates;\n"
"}";

const char *fragmentShaderSource =
"#version 330 core\n"
"\n"
"out vec4 fragColor;"
"\n"
"in vec2 fragUVCoordinates;\n"
"\n"
"uniform sampler2D texture_0;\n"
"\n"
"void main() {\n"
"   fragColor = texture(texture_0, fragUVCoordinates);//vec4(1.0f, 0.5f, 1.0f, 0.5f);\n"
"}";

float vertices[] = {
    -0.5f, -0.5f,  0.0f,        0.0f, 0.0f,
     0.5f, -0.5f,  0.0f,        1.0f, 0.0f,
     0.5f,  0.5f,  0.0f,        1.0f, 1.0f,
    -0.5f,  0.5f,  0.0f,        0.0f, 1.0f,
};

unsigned int elements[] = {
    0, 1, 2,
    0, 2, 3
};

const int WINDOW_WIDTH = 500, WINDOW_HEIGHT = 500;

void FrameBufferSizeCallback(GLFWwindow *window, int width, int height);

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
#endif

    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello Window", NULL, NULL);

    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);
    gladLoadGL();


    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);


    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    unsigned int VBO, VAO, EBO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(0));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    
    glBindVertexArray(0);


    // JUST TRYING TO BE FUNNY


    unsigned int dancingTexture;
    glGenTextures(1, &dancingTexture);
    glBindTexture(GL_TEXTURE_2D, dancingTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    int width, height, channelCount;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *imageData = stbi_load("Resources/Textures/Dancing.png", &width, &height, &channelCount, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(imageData);
    glBindTexture(GL_TEXTURE_2D, 0);


    unsigned int jumpingTexture;
    glGenTextures(1, &jumpingTexture);
    glBindTexture(GL_TEXTURE_2D, jumpingTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    stbi_set_flip_vertically_on_load(true);
    imageData = stbi_load("Resources/Textures/Jumping.png", &width, &height, &channelCount, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(imageData);
    glBindTexture(GL_TEXTURE_2D, 0);


    glUseProgram(shaderProgram);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, dancingTexture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, jumpingTexture);


    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    

    glClear(GL_COLOR_BUFFER_BIT);

    glUniform1i(glGetUniformLocation(shaderProgram, "texture_0"), 0);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void *)(0));
    glBindVertexArray(0);

    glUniform1i(glGetUniformLocation(shaderProgram, "texture_0"), 1);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void *)(3 * sizeof(unsigned int)));
    glBindVertexArray(0);

    glfwSwapBuffers(window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glDeleteProgram(shaderProgram);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);

    glfwTerminate();
    return 0;
}

void FrameBufferSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}