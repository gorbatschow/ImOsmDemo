#!/bin/bash

cd glfw/glfw && git checkout master && git pull && cd ../..
cd imgui/imgui && git checkout docking && git pull && cd ../..
cd implot/implot && git checkout master && git pull && cd ../..
#cd imwrap/imwrap && git checkout master && git pull && cd ../..
#cd mini/mini && git checkout master && git pull && cd ../..
cd stb/stb && git checkout master && git pull && cd ../..

cd imapp/imapp && git checkout master && git pull && cd ../..
cd imfonts/imfonts && git checkout master && git pull && cd ../..
cd imosm/imosm && git checkout master && git pull && cd ../..
