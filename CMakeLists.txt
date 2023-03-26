cmake_minimum_required(VERSION 3.16.0)

project(ImOsmDemo VERSION 1.0.0)

# STB
add_subdirectory(external/stb)

# IMGUI
add_subdirectory(external/mini)

# GLFW
add_subdirectory(external/glfw)

# IMGUI
add_subdirectory(external/imgui)

# IMPLOT
add_subdirectory(external/implot)

# IMFONTS
add_subdirectory(external/imfonts)

# IMAPP
add_subdirectory(external/imapp)

# IMWRAP
add_subdirectory(external/imwrap)

# IMOSM
add_subdirectory(external/imosm)

# EXECUTABLE
add_subdirectory(src)



