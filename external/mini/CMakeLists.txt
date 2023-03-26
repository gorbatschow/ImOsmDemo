cmake_minimum_required(VERSION 3.16.0)

project(mini)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ./mini/src/mini/)
