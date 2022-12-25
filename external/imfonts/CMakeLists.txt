cmake_minimum_required(VERSION 3.16.0)

project(imfonts)

set(IMFONTS_SOURCES
    # Roboto
    imfonts/RobotoRegular.cpp
    imfonts/RobotoBold.cpp
    imfonts/RobotoItalic.cpp
    # Roboto Mono
    imfonts/RobotoMonoRegular.cpp
    imfonts/RobotoMonoBold.cpp
    imfonts/RobotoMonoItalic.cpp
)

add_library(${PROJECT_NAME} ${IMFONTS_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC imfonts)
