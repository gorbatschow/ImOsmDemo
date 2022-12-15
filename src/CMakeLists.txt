cmake_minimum_required(VERSION 3.16.0)

project(ImOsmDemoExe)

set(CXX_CMAKE_STANDARD 17)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMPROJECTEXE_SOURCES
    main.cpp
    ImOsmDemoApp.cpp
)

add_executable(ImOsmDemoExe ${IMPROJECTEXE_SOURCES})
target_include_directories(ImOsmDemoExe PUBLIC .)
target_link_libraries(ImOsmDemoExe PUBLIC ImApplication)
target_link_libraries(ImOsmDemoExe PUBLIC ImOsmWidget)
