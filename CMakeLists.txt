cmake_minimum_required(VERSION 3.5)
project(SnakeGameTest)

include(HeartEngine/tools/Main.cmake)

add_executable(${PROJECT_NAME} src/main.cpp)

SET(USE_EDITOR ON CACHE BOOL "" FORCE)
set(RAYINPUT_INCLUDE_VECTOR2 ON CACHE BOOL "" FORCE)
set(RAYINPUT_INCLUDE_VECTOR3 ON CACHE BOOL "" FORCE)
set(RAYINPUT_INCLUDE_MATRIX ON CACHE BOOL "" FORCE)
set(RAYINPUT_INCLUDE_QUATERNION ON CACHE BOOL "" FORCE)

set(RAYINPUT_INCLUDE_KEYBOARD ON CACHE BOOL "" FORCE)
set(RAYINPUT_INCLUDE_MOUSE ON CACHE BOOL "" FORCE)
set(RAYINPUT_INCLUDE_GAMEPAD ON CACHE BOOL "" FORCE)
set(RAYINPUT_INCLUDE_TOUCH ON CACHE BOOL "" FORCE)

LoadModule(${PROJECT_NAME} HeartEngine core/include HeartEngine)

LoadModule(${PROJECT_NAME} HeartEngine/modules/raylib/raylib_core include heart_raylib_core)
LoadModule(${PROJECT_NAME} HeartEngine/modules/raylib/raymath include heart_raymath)
LoadModule(${PROJECT_NAME} HeartEngine/modules/raylib/raylib_input include heart_raylib_input)
LoadModule(${PROJECT_NAME} HeartEngine/modules/raylib/raylib_camera include heart_raylib_camera)

LoadModule(${PROJECT_NAME} HeartEngine/modules/raylib/raylib_textures include heart_raylib_textures)
LoadModule(${PROJECT_NAME} HeartEngine/modules/raylib/raylib_gui include heart_raylib_gui)
LoadModule(${PROJECT_NAME} HeartEngine/modules/raylib/raylib_shapes include heart_raylib_shapes)

LoadModule(${PROJECT_NAME} HeartEngine/modules/physac include heart_physac)