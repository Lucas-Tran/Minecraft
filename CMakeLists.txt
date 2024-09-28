cmake_minimum_required(VERSION 3.10)

project(Minecraft VERSION 1.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 17)

file(GLOB_RECURSE SOURCES Source/*.cpp Source/*.c)

include_directories(Engine/Include Engine/Dependencies/Include)
link_directories(Engine/Library Engine/Dependencies/Libraries)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} glfw3 
Engine "-framework Cocoa" "-framework OpenGL" "-framework IOKit")

file(COPY Resources DESTINATION .)

include(CTest)
enable_testing()