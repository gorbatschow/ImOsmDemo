cmake_minimum_required(VERSION 3.16.0)

project(ImOsmDemoExe)

set(CXX_CMAKE_STANDARD 17)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMPROJECTEXE_SOURCES
    main.cpp
    ImOsmDemoApp.cpp
)

add_executable(${PROJECT_NAME} ${IMPROJECTEXE_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME} PUBLIC ImApplication)
target_link_libraries(${PROJECT_NAME} PUBLIC ImOsmWidget)
