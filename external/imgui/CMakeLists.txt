cmake_minimum_required(VERSION 3.16.0)

project(imgui)

set(IMGUI_SRC
    imgui/imgui.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_tables.cpp
    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.cpp
    imgui/misc/cpp/imgui_stdlib.cpp
)

add_library(${PROJECT_NAME} ${IMGUI_SRC})
target_include_directories (${PROJECT_NAME} PUBLIC imgui)
target_link_libraries (${PROJECT_NAME} PUBLIC glfw)
