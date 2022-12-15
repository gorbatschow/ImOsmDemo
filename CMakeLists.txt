cmake_minimum_required(VERSION 3.16.0)

project(ImOsmDemo VERSION 1.0.0)

# GLFW
add_subdirectory(external/glfw)

# IMGUI
add_subdirectory(external/imgui)

# IMPLOT
add_subdirectory(external/implot)

# IMFONTS
add_subdirectory(external/imfonts)

# STB
add_subdirectory(external/stb)

# IMAPP
add_subdirectory(external/imapp)

# IMOSMWIDGET
add_subdirectory(external/imosmwidget)

# EXECUTABLE
add_subdirectory(src)



