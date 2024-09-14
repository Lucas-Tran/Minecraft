#include "ShaderProgram.h"

#include "Texture2D.h"

#include "Camera.h"

#include "EngineProcessor.h"

#include "Light.h"

#include "Chunk.h"

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

    Window::window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Minecraft", NULL, NULL);

    if (Window::window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(Window::window);

    gladLoadGL();

    EngineProcessor::Init();
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);


    Camera camera(glm::vec3(0.0f, 0.0f, 20.0f), 0.0f, 0.0f, FOV, NEAR, FAR);


    ShaderProgram shaderProgram("default");
    if (!shaderProgram.GetSuccess()) {
        std::cout << ShaderProgramBuilder::errorLog << std::endl;
        return -1;
    }

    Chunk chunk;


    shaderProgram.Use();

    Light::DirectionalLight directionalLight;

    directionalLight.direction = glm::normalize(glm::vec3(-1.0f));

    directionalLight.color = glm::normalize(glm::vec3(1.0f));

    directionalLight.ambientIntensity = 0.3f;
    directionalLight.diffuseIntensity = 1.4f;
    directionalLight.specularIntensity = 2.0f;

    Light::UniformLight(shaderProgram, directionalLight);

    Texture2D texture("Dancing.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    texture.BindWithSlot(GL_TEXTURE0);

    shaderProgram.SetUniform("texture_0", 0);


    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);


    while (!glfwWindowShouldClose(Window::window)) {
        glfwPollEvents();
        EngineProcessor::TickPreProcess();

        Window::SetWindowCaption("Minecraft - FPS: " + std::to_string(Time::FPS));

        camera.UpdateProjectionMatrix();
        camera.Update();

        shaderProgram.SetUniform("viewPosition", camera.GetPosition());


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        

        shaderProgram.SetUniform("view", camera.GetViewMatrix());
        shaderProgram.SetUniform("projection", camera.GetProjectionMatrix());
        
        glm::mat4 model;
        shaderProgram.SetUniform("model", model);
        chunk.Draw();

        glfwSwapBuffers(Window::window);
    }


    glfwTerminate();
    return 0;
}