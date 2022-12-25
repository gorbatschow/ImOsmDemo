cmake_minimum_required(VERSION 3.16.0)

project(imgui)

set(IMGUI_HEADERS
    imgui/imgui.h
    imgui/imconfig.h
    imgui/imgui_internal.h
    imgui/imstb_rectpack.h
    imgui/imstb_textedit.h
    imgui/imstb_truetype.h
    imgui/backends/imgui_impl_glfw.h
    imgui/backends/imgui_impl_opengl3.h
)

set(IMGUI_SOURCES
    imgui/imgui.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_tables.cpp
    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.cpp
)

add_library(${PROJECT_NAME} ${IMGUI_SOURCES})
target_include_directories (${PROJECT_NAME} PUBLIC imgui)
target_link_libraries (${PROJECT_NAME} PUBLIC glfw)
