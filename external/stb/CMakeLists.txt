cmake_minimum_required(VERSION 3.16.0)

project(stb)

add_library(${PROJECT_NAME} INTERFACE stb)
target_include_directories(${PROJECT_NAME} INTERFACE stb)
