cmake_minimum_required(VERSION 3.16.0)

project(ImOsmWidget)

set(CXX_CMAKE_STANDARD 17)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMOSMWIDGET_SOURCES
    imosmwidget/ImOsmWidget.cpp
    imosmwidget/OsmTileLoader.cpp
    imosmwidget/OsmTileTexture.cpp
)

add_library(${PROJECT_NAME} ${IMOSMWIDGET_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC imosmwidget)
target_link_libraries(${PROJECT_NAME} PUBLIC imgui)
target_link_libraries(${PROJECT_NAME} PUBLIC implot)
target_link_libraries(${PROJECT_NAME} PUBLIC stb)
target_link_libraries(${PROJECT_NAME} PUBLIC curl)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
