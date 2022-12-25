cmake_minimum_required(VERSION 3.16.0)

project(implot)

set(IMPLOT_SOURCES
    implot/implot.cpp
    implot/implot_items.cpp
    implot/implot_demo.cpp
)

add_library(${PROJECT_NAME} ${IMPLOT_SOURCES})
target_include_directories (${PROJECT_NAME} PUBLIC implot)
target_link_libraries(${PROJECT_NAME} PUBLIC imgui)


