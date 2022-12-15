cmake_minimum_required(VERSION 3.16.0)

project(ImApplication VERSION 1.0.0)

set(CXX_CMAKE_STANDARD 17)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMAPPLICATION_SOURCES
    imapp/ImApplication.cpp
)

add_library(ImApplication ${IMAPPLICATION_SOURCES})
target_include_directories(ImApplication PUBLIC imapp)
target_link_libraries(ImApplication PUBLIC glfw)
target_link_libraries(ImApplication PUBLIC imgui)
target_link_libraries(ImApplication PUBLIC implot)
target_link_libraries(ImApplication PUBLIC imfonts)
target_link_libraries(ImApplication PUBLIC stb)

include(FindOpenGL)
target_link_libraries(ImApplication PUBLIC ${OPENGL_LIBRARIES})

