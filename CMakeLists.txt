cmake_minimum_required(VERSION 3.0)

project(Minecraft VERSION 1.0)

file(GLOB_RECURSE SOURCES Source/*.cpp Source/*.c)

include_directories(Dependencies/include)
link_directories(Dependencies/lib)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE Headers)

target_link_libraries(${PROJECT_NAME} glfw3 "-framework Cocoa" "-framework OpenGL" "-framework IOKit")

file(COPY Resources DESTINATION .)