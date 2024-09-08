#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ShaderProgram.h"

#include "VBO.h"
#include "EBO.h"
#include "VAO.h"

#include <Texture2D.h>


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

    ShaderProgram shaderProgram("default");


    VAO VAO;

    VBO VBO(vertices, sizeof(vertices));

    EBO EBO(elements, sizeof(elements));

    VAO.SetVertexAttribute(0, 3, 5, 0);
    VAO.SetVertexAttribute(1, 2, 5, 3);

    VAO::Unbind();

    // JUST TRYING TO BE FUNNY

    Texture2D dancingTexture("Dancing.png", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);
    Texture2D jumpingTexture("Jumping.png", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);


    shaderProgram.Use();

    dancingTexture.BindWithSlot(GL_TEXTURE0);
    jumpingTexture.BindWithSlot(GL_TEXTURE1);


    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    

    glClear(GL_COLOR_BUFFER_BIT);

    shaderProgram.SetUniformInteger("texture_0", 0);
    VAO.Bind();
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void *)(0));
    VAO::Unbind();

    shaderProgram.SetUniformInteger("texture_0", 1);
    VAO.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void *)(3 * sizeof(unsigned int)));
    VAO::Unbind();

    glfwSwapBuffers(window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}

void FrameBufferSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}