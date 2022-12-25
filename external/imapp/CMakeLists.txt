cmake_minimum_required(VERSION 3.16.0)

project(ImApplication VERSION 1.0.0)

set(CXX_CMAKE_STANDARD 17)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMAPPLICATION_SOURCES
    imapp/ImApplication.cpp
)

add_library(${PROJECT_NAME} ${IMAPPLICATION_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC imapp)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC imgui)
target_link_libraries(${PROJECT_NAME} PUBLIC implot)
target_link_libraries(${PROJECT_NAME} PUBLIC imfonts)
target_link_libraries(${PROJECT_NAME} PUBLIC stb)

include(FindOpenGL)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_LIBRARIES})

