#include "ImOsmDemoApp.h"
#include <imgui_internal.h>

ImOsmDemoApp::ImOsmDemoApp()
    : ImApp::MainWindow("ImOsm Demo Application") {
  mINI::INIStructure ini;
  mINI::INIFile iniFile(_iniFileNameMark);
  iniFile.read(ini);
  _markStorage->loadState(ini);
}

ImOsmDemoApp::~ImOsmDemoApp() {
  mINI::INIStructure ini;
  mINI::INIFile iniFile(_iniFileNameMark);
  _markStorage->saveState(ini);
  iniFile.write(ini);
}

void ImOsmDemoApp::beforeLoop() {}

void ImOsmDemoApp::firstPaint() {
  const ImGuiID centralNode{ImGui::DockBuilderGetCentralNode(dockSpaceID())->ID};
  ImGui::DockBuilderDockWindow("MapWidget", centralNode);
}

void ImOsmDemoApp::paint() {
  ImGui::Begin("MapWidget");

  ImGui::Text("FPS: %.0f", ImGui::GetIO().Framerate);
  ImGui::Text("MOUSE: lat %.2f, lon %.2f",
              _mapPlot->mouseLon(),
              _mapPlot->mouseLat());
  ImGui::Text("VIEW: lat %.2f:%.2f, lon %.2f:%.2f ",
              _mapPlot->minLat(),
              _mapPlot->maxLat(),
              _mapPlot->minLon(),
              _mapPlot->maxLon());

  // ImGui::Text("Tiles: %d", _mapPlot.loader().tilesNum());

  _worldBtn.paint();
  if (_worldBtn.handle()) {
    _mapPlot->setBoundsGeo(ImOsm::MinLat,
                           ImOsm::MaxLat,
                           ImOsm::MinLon,
                           ImOsm::MaxLon);
  }

  ImGui::SameLine();
  _berlinBtn.paint();
  if (_berlinBtn.handle()) {
    _mapPlot->setBoundsGeo(52.43, 52.59, 13.12, 13.66);
  }

  ImGui::SameLine();
  _parisBtn.paint();
  if (_parisBtn.handle()) {
    _mapPlot->setBoundsGeo(49.25, 48.57, 1.12, 3.58);
  }

  ImGui::SameLine();
  _madridBtn.paint();
  if (_madridBtn.handle()) {
    _mapPlot->setBoundsGeo(40.61, 40.19, -4.26, -3.10);
  }

  _mapPlot->paint();

  ImGui::End();

  ImGui::Begin("MarkWidget");
  _markWidget->paint();
  ImGui::End();
}
