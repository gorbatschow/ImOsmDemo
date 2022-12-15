cmake_minimum_required(VERSION 3.16.0)

project(stb)

add_library(stb INTERFACE stb)
target_include_directories(stb INTERFACE stb)
