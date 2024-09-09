#include "ShaderProgram.h"

#include "VBO.h"
#include "EBO.h"
#include "VAO.h"

#include "Texture2D.h"

#include "Camera.h"

#include "EngineProcessor.h"


float vertices[] = {
    -0.5f, -0.5f,  0.5f,        1.0f, 0.0f, 0.0f,          0.0f,  0.0f,  1.0f,
     0.5f, -0.5f,  0.5f,        1.0f, 0.0f, 0.0f,          0.0f,  0.0f,  1.0f,
     0.5f,  0.5f,  0.5f,        1.0f, 0.0f, 0.0f,          0.0f,  0.0f,  1.0f,
    -0.5f,  0.5f,  0.5f,        1.0f, 0.0f, 0.0f,          0.0f,  0.0f,  1.0f,


    -0.5f, -0.5f, -0.5f,        1.0f, 0.0f, 0.0f,         -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,        1.0f, 0.0f, 0.0f,         -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,        1.0f, 0.0f, 0.0f,         -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,        1.0f, 0.0f, 0.0f,         -1.0f,  0.0f,  0.0f,


     0.5f, -0.5f, -0.5f,        1.0f, 0.0f, 0.0f,          0.0f,  0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,        1.0f, 0.0f, 0.0f,          0.0f,  0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,        1.0f, 0.0f, 0.0f,          0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,        1.0f, 0.0f, 0.0f,          0.0f,  0.0f, -1.0f,


     0.5f, -0.5f,  0.5f,        1.0f, 0.0f, 0.0f,          1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,        1.0f, 0.0f, 0.0f,          1.0f,  0.0f,  0.0f,
     0.5f,  0.5f, -0.5f,        1.0f, 0.0f, 0.0f,          1.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f,        1.0f, 0.0f, 0.0f,          1.0f,  0.0f,  0.0f,


    -0.5f,  0.5f,  0.5f,        1.0f, 0.0f, 0.0f,          0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,        1.0f, 0.0f, 0.0f,          0.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,        1.0f, 0.0f, 0.0f,          0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,        1.0f, 0.0f, 0.0f,          0.0f,  1.0f,  0.0f,


     0.5f,  -0.5f,  0.5f,       1.0f, 0.0f, 0.0f,          0.0f, -1.0f,  0.0f,
    -0.5f,  -0.5f,  0.5f,       1.0f, 0.0f, 0.0f,          0.0f, -1.0f,  0.0f,
    -0.5f,  -0.5f, -0.5f,       1.0f, 0.0f, 0.0f,          0.0f, -1.0f,  0.0f,
     0.5f,  -0.5f, -0.5f,       1.0f, 0.0f, 0.0f,          0.0f, -1.0f,  0.0f
};

#define STRIDE 9

unsigned int elements[] = {
    0, 1, 2,
    0, 2, 3,


    4, 5, 6,
    4, 6, 7,


    8, 9, 10,
    8, 10, 11,


    12, 13, 14,
    12, 14, 15,


    16, 17, 18,
    16, 18, 19,


    20, 21, 22,
    20, 22, 23
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
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    EngineProcessor::Init();


    Camera camera(glm::vec3(0.0f, 0.0f, 3.0f), 0.0f, 0.0f, FOV, NEAR, FAR);


    ShaderProgram shaderProgram("default");
    if (!shaderProgram.GetSuccess()) {
        std::cout << ShaderProgramBuilder::errorLog << std::endl;
        return -1;
    }


    VAO VAO;

    VBO VBO(vertices, sizeof(vertices));

    EBO EBO(elements, sizeof(elements));

    VAO.SetVertexAttribute(0, 3, STRIDE, 0);
    VAO.SetVertexAttribute(1, 3, STRIDE, 3);
    VAO.SetVertexAttribute(2, 3, STRIDE, 6);

    VAO::Unbind();

    // JUST TRYING TO BE FUNNY

    Texture2D dancingTexture("Dancing.png", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);
    Texture2D jumpingTexture("Jumping.png", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);


    shaderProgram.Use();

    dancingTexture.BindWithSlot(GL_TEXTURE0);
    jumpingTexture.BindWithSlot(GL_TEXTURE1);
    
    shaderProgram.SetUniform("texture_0", 0);
    shaderProgram.SetUniform("lightDirection", glm::normalize(glm::vec3(-1.0f)));


    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);



    while (!glfwWindowShouldClose(window)) {
        EngineProcessor::TickPreProcess();

        glfwPollEvents();

        camera.UpdateProjectionMatrix();
        camera.Update();

        EngineProcessor::TickPostProcess();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 model;
        model = glm::rotate(model, Time::time, glm::vec3(0.0f, 1.0f, 0.0f));
        

        shaderProgram.SetUniform("model", model);
        shaderProgram.SetUniform("view", camera.GetViewMatrix());
        shaderProgram.SetUniform("projection", camera.GetProjectionMatrix());

        VAO.Bind();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void *)(0));
        VAO::Unbind();

        glfwSwapBuffers(window);
    }


    glfwTerminate();
    return 0;
}