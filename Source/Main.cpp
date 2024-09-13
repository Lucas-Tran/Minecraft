#include "ShaderProgram.h"

#include "Texture2D.h"

#include "Camera.h"

#include "EngineProcessor.h"

#include "Light.h"

#include "DynamicMesh.h"

const Vertex vertices[] = {
    {glm::vec3(-0.5f, -0.5f,  0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3( 0.0f,  0.0f,  1.0f)},
    {glm::vec3( 0.5f, -0.5f,  0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3( 0.0f,  0.0f,  1.0f)},
    {glm::vec3( 0.5f,  0.5f,  0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3( 0.0f,  0.0f,  1.0f)},
    {glm::vec3(-0.5f,  0.5f,  0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3( 0.0f,  0.0f,  1.0f)},


    {glm::vec3(-0.5f, -0.5f, -0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3(-1.0f,  0.0f,  0.0f)},
    {glm::vec3(-0.5f, -0.5f,  0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3(-1.0f,  0.0f,  0.0f)},
    {glm::vec3(-0.5f,  0.5f,  0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3(-1.0f,  0.0f,  0.0f)},
    {glm::vec3(-0.5f,  0.5f, -0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3(-1.0f,  0.0f,  0.0f)},


    {glm::vec3( 0.5f, -0.5f, -0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3( 0.0f,  0.0f, -1.0f)},
    {glm::vec3(-0.5f, -0.5f, -0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3( 0.0f,  0.0f, -1.0f)},
    {glm::vec3(-0.5f,  0.5f, -0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3( 0.0f,  0.0f, -1.0f)},
    {glm::vec3( 0.5f,  0.5f, -0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3( 0.0f,  0.0f, -1.0f)},


    {glm::vec3( 0.5f, -0.5f,  0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3( 1.0f,  0.0f,  0.0f)},
    {glm::vec3( 0.5f, -0.5f, -0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3( 1.0f,  0.0f,  0.0f)},
    {glm::vec3( 0.5f,  0.5f, -0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3( 1.0f,  0.0f,  0.0f)},
    {glm::vec3( 0.5f,  0.5f,  0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3( 1.0f,  0.0f,  0.0f)},


    {glm::vec3(-0.5f,  0.5f,  0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3( 0.0f,  1.0f,  0.0f)},
    {glm::vec3( 0.5f,  0.5f,  0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3( 0.0f,  1.0f,  0.0f)},
    {glm::vec3( 0.5f,  0.5f, -0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3( 0.0f,  1.0f,  0.0f)},
    {glm::vec3(-0.5f,  0.5f, -0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3( 0.0f,  1.0f,  0.0f)},


    {glm::vec3( 0.5f,  -0.5f,  0.5f),       glm::vec2(0.0f, 0.0f),         glm::vec3( 0.0f, -1.0f,  0.0f)},
    {glm::vec3(-0.5f,  -0.5f,  0.5f),       glm::vec2(1.0f, 0.0f),         glm::vec3( 0.0f, -1.0f,  0.0f)},
    {glm::vec3(-0.5f,  -0.5f, -0.5f),       glm::vec2(1.0f, 1.0f),         glm::vec3( 0.0f, -1.0f,  0.0f)},
    {glm::vec3( 0.5f,  -0.5f, -0.5f),       glm::vec2(0.0f, 1.0f),         glm::vec3( 0.0f, -1.0f,  0.0f)}
};

#define STRIDE 8

const unsigned int elements[] = {
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

const glm::vec3 cubePositions[] = {
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(-2.0f, 2.0f, -3.0f),
    glm::vec3(4.0f, 1.0f, -9.0f),
    glm::vec3(8.0f, 3.0f, 4.0f),
    glm::vec3(4.0f, 2.0f, 0.0f)
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
    //glEnable(GL_CULL_FACE);

    EngineProcessor::Init();


    Camera camera(glm::vec3(0.0f, 0.0f, 3.0f), 0.0f, 0.0f, FOV, NEAR, FAR);


    ShaderProgram shaderProgram("default");
    if (!shaderProgram.GetSuccess()) {
        std::cout << ShaderProgramBuilder::errorLog << std::endl;
        return -1;
    }

    DynamicMesh mesh;
    for (unsigned int i = 0; i < 24; i++) {
        mesh.vertices.push_back(vertices[i]);
    }
    for (unsigned int i = 0; i < 36; i++) {
        mesh.elements.push_back(elements[i]);
    }
    mesh.UpdateBuffers();


    shaderProgram.Use();

    Light::DirectionalLight directionalLight;

    directionalLight.direction = glm::normalize(glm::vec3(-1.0f));

    directionalLight.color = glm::normalize(glm::vec3(1.0f));

    directionalLight.ambientIntensity = 0.3f;
    directionalLight.diffuseIntensity = 1.4f;
    directionalLight.specularIntensity = 2.0f;

    Light::UniformLight(shaderProgram, directionalLight);

    Light::PointLight pointLight;

    pointLight.position = glm::vec3(10.0f, 5.0f, 4.0f);

    pointLight.color = glm::vec3(1.0f);

    pointLight.ambientIntensity = 0.1f;
    pointLight.diffuseIntensity = 0.6f;
    pointLight.specularIntensity = 1.2f;

    pointLight.quadratic = 0.1f;
    pointLight.linear = 0.2f;
    pointLight.constant = 0.3f;

    Light::UniformLight(shaderProgram, 0U, pointLight);

    Light::SpotLight spotLight;

    spotLight.position = glm::vec3(-1.0f, 0, 0);
    spotLight.direction = glm::vec3(1.0f, 0, 0);

    spotLight.innerCutOffDegrees = 10.0f;
    spotLight.outerCutOffDegrees = 15.0f;

    spotLight.color = glm::vec3(1.0f);

    spotLight.ambientIntensity = 0.1f;
    spotLight.diffuseIntensity = 0.4f;
    spotLight.specularIntensity = 1.0f;

    spotLight.quadratic = 0.01f;
    spotLight.linear = 0.03f;
    spotLight.constant = 0.05f;

    Light::UniformLight(shaderProgram, 0U, spotLight);

    Texture2D texture("Dancing.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    texture.BindWithSlot(GL_TEXTURE0);

    shaderProgram.SetUniform("texture_0", 0);


    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);


    while (!glfwWindowShouldClose(window)) {
        EngineProcessor::TickPreProcess();

        glfwPollEvents();

        camera.UpdateProjectionMatrix();
        camera.Update();

        shaderProgram.SetUniform("viewPosition", camera.GetPosition());

        EngineProcessor::TickPostProcess();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        

        shaderProgram.SetUniform("view", camera.GetViewMatrix());
        shaderProgram.SetUniform("projection", camera.GetProjectionMatrix());

        for (unsigned int i = 0; i < 5; i++) {
            glm::mat4 model;
            model = glm::translate(model, cubePositions[i]);
            shaderProgram.SetUniform("model", model);
            mesh.Draw();
        }

        glfwSwapBuffers(window);
    }


    glfwTerminate();
    return 0;
}