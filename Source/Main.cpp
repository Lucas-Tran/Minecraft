#include "ShaderProgram.h"

#include "VBO.h"
#include "EBO.h"
#include "VAO.h"

#include "Texture2D.h"

#include "Camera.h"

#include "EngineProcessor.h"


float vertices[] = {
    -0.5f, -0.5f,  0.0f,        0.0f, 0.0f,
     0.5f, -0.5f,  0.0f,        1.0f, 0.0f,
     0.5f,  0.5f,  0.0f,        1.0f, 1.0f,
    -0.5f,  0.5f,  0.0f,        0.0f, 1.0f,
};

#define STRIDE 5

unsigned int elements[] = {
    0, 1, 2,
    0, 2, 3
};

const int WINDOW_WIDTH = 700, WINDOW_HEIGHT = 500;

const float FOV = 60.0f;
const float NEAR = 0.01f;
const float FAR = 1000.0f;


int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
#endif

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Minecraft", NULL, NULL);

    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();

    EngineProcessor::Init();


    Camera camera(glm::vec3(0, 0, 3), 0, 45, FOV, NEAR, FAR);


    ShaderProgram shaderProgram("default");


    VAO VAO;

    VBO VBO(vertices, sizeof(vertices));

    EBO EBO(elements, sizeof(elements));

    VAO.SetVertexAttribute(0, 3, STRIDE, 0);
    VAO.SetVertexAttribute(1, 2, STRIDE, 3);

    VAO::Unbind();

    // JUST TRYING TO BE FUNNY

    Texture2D dancingTexture("Dancing.png", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);
    Texture2D jumpingTexture("Jumping.png", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);


    shaderProgram.Use();

    dancingTexture.BindWithSlot(GL_TEXTURE0);
    jumpingTexture.BindWithSlot(GL_TEXTURE1);


    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);



    while (!glfwWindowShouldClose(window)) {
        EngineProcessor::TickPreProcess();

        glfwPollEvents();

        camera.UpdateProjectionMatrix();
        camera.Update();

        EngineProcessor::TickPostProcess();

        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.SetUniformMatrix4("view", camera.GetViewMatrix());
        shaderProgram.SetUniformMatrix4("projection", camera.GetProjectionMatrix());

        shaderProgram.SetUniformInteger("texture_0", 0);
        VAO.Bind();
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void *)(0));
        VAO::Unbind();

        shaderProgram.SetUniformInteger("texture_0", 1);
        VAO.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void *)(3 * sizeof(unsigned int)));
        VAO::Unbind();

        glfwSwapBuffers(window);
    }


    glfwTerminate();
    return 0;
}