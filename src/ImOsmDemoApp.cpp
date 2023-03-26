#include "ImOsmDemoApp.h"
#include <imgui_internal.h>

ImOsmDemoApp::ImOsmDemoApp() : ImApp::MainWindow("ImOsm Demo Application") {}

ImOsmDemoApp::~ImOsmDemoApp() {}

void ImOsmDemoApp::beforeLoop() {}

void ImOsmDemoApp::paint() {

  if (_firstPaint) {
    ImGuiID centralNode = ImGui::DockBuilderGetCentralNode(dockSpaceID())->ID;
    ImGui::DockBuilderDockWindow("MapWidget", centralNode);
    _firstPaint = false;
  }

  ImGui::Begin("MapWidget");

  ImGui::Text("FPS: %.0f", ImGui::GetIO().Framerate);
  ImGui::Text("MOUSE: lon %.2f, lat %.2f", _mapPlot.mouseLon(),
              _mapPlot.mouseLat());
  ImGui::Text("VIEW: lon %.2f-%.2f, lat %.2f-%.2f ", _mapPlot.minLon(),
              _mapPlot.maxLon(), _mapPlot.minLat(), _mapPlot.maxLat());

  // ImGui::Text("Tiles: %d", _mapPlot.loader().tilesNum());

  _worldBtn.paint();
  if (_worldBtn.handle()) {
    _mapPlot.setBoundsGeo(ImOsm::MinLon, ImOsm::MaxLon, ImOsm::MinLat,
                          ImOsm::MaxLat);
  }

  ImGui::SameLine();
  _berlinBtn.paint();
  if (_berlinBtn.handle()) {
    _mapPlot.setBoundsGeo(13.12, 13.66, 52.43, 52.59);
  }

  ImGui::SameLine();
  _parisBtn.paint();
  if (_parisBtn.handle()) {
    _mapPlot.setBoundsGeo(1.12, 3.58, 49.25, 48.57);
  }

  ImGui::SameLine();
  _madridBtn.paint();
  if (_madridBtn.handle()) {
    _mapPlot.setBoundsGeo(-4.26, -3.10, 40.61, 40.19);
  }

  _mapPlot.paint();

  ImGui::End();
}
