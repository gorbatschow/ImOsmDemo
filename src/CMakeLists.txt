cmake_minimum_required(VERSION 3.16.0)

project(ImOsmDemoExe)

set(CXX_CMAKE_STANDARD 20)
set(CXX_CMAKE_STANDARD_REQUIRED ON)

set(IMPROJECTEXE_SRC
    main.cpp
    ImOsmDemoApp.cpp
)

add_executable(${PROJECT_NAME} ${IMPROJECTEXE_SRC})
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME} PUBLIC mini)
target_link_libraries(${PROJECT_NAME} PUBLIC imapp)
target_link_libraries(${PROJECT_NAME} PUBLIC imosm)
target_link_libraries(${PROJECT_NAME} PUBLIC imwrap)


