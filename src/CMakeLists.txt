cmake_minimum_required(VERSION 3.16.0)

project(ImProjectExe)

set(CXX_CMAKE_STANDARD 17)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMPROJECTEXE_SOURCES
    main.cpp
)

add_executable(ImProjectExe ${IMPROJECTEXE_SOURCES})
target_include_directories(ImProjectExe PUBLIC .)
target_link_libraries(ImProjectExe PUBLIC ImApplication)
