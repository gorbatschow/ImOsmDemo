# ImOsmWidgetDemo

This is an application for demonstrate possibilities of [ImOsmWidget](https://github.com/gorbatschow/ImOsmWidget).
It is based on [ImProject](https://github.com/gorbatschow/ImProject) template.

ImOsmWidget is included as submodule in directory *external/imosmwidget/*.

In short I use ImGui with GLFW backend, ImPlot, CURL and STB libraries to display interactive map using tiles provided by OpenStreetMap.

![image](doc/demo.gif)

## Ubuntu dependencies

For ImGui with GLFW backend the following packages must be installed
```
libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev freeglut3-dev
```
For ImOsmWidget libcurl needed
```
libcurl4-gnutls-dev
```

