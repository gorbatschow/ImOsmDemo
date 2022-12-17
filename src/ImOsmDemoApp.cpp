#include "ImOsmDemoApp.h"

ImOsmDemoApp::ImOsmDemoApp() {}

ImOsmDemoApp::~ImOsmDemoApp() {}

void ImOsmDemoApp::paint() {
  ImGui::Begin("Map widget");
  ImGui::Text("MOUSE: lon %.2f, lat %.2f", _osmWidget.mouseLon(),
              _osmWidget.mouseLat());
  ImGui::Text("VIEW: lon %.2f-%.2f, lat %.2f-%.2f ", _osmWidget.minLon(),
              _osmWidget.maxLon(), _osmWidget.minLat(), _osmWidget.maxLat());

  _worldBtn.paint();
  if (_worldBtn.handle()) {
    _osmWidget.setBounds();
  }

  ImGui::SameLine();
  _berlinBtn.paint();
  if (_berlinBtn.handle()) {
    _osmWidget.setBounds(13.12, 13.66, 52.43, 52.59);
  }

  ImGui::SameLine();
  _parisBtn.paint();
  if (_parisBtn.handle()) {
    _osmWidget.setBounds(1.12, 3.58, 49.25, 48.57);
  }

  ImGui::SameLine();
  _madridBtn.paint();
  if (_madridBtn.handle()) {
    _osmWidget.setBounds(-4.26, -3.10, 40.61, 40.19);
  }

  _osmWidget.paint();

  ImGui::End();
}
