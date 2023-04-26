#include "ImOsmDemoApp.h"
#include <imgui_internal.h>

using namespace ImOsm;
using namespace ImOsm::Rich;

ImOsmDemoApp::ImOsmDemoApp()
    : ImApp::MainWindow("ImOsm Demo Application"),
      _mapPlot{std::make_shared<RichMapPlot>()},
      _markStorage{std::make_shared<MarkStorage>()},
      _markEditorWidget{
          std::make_unique<MarkEditorWidget>(_mapPlot, _markStorage)},
      _distanceCalcWidget{std::make_unique<DistanceCalcWidget>(_markStorage)},
      _destinationCalcWidget{
          std::make_unique<DestinationCalcWidget>(_markStorage)},
      _tileSourceWidget{std::make_unique<TileSourceWidget>(_mapPlot)},
      _tileGrabberWidget{std::make_unique<TileGrabberWidget>(_mapPlot)} {

  {
    mINI::INIStructure ini;
    mINI::INIFile iniFile(_iniFileNameMark);
    iniFile.read(ini);
    _markStorage->loadState(ini);
  }
  {
    mINI::INIStructure ini;
    mINI::INIFile iniFile(_iniFileNameMain);
    iniFile.read(ini);
    _mapPlot->loadState(ini);
    _tileSourceWidget->loadState(ini);
    _tileGrabberWidget->loadState(ini);
  }
}

ImOsmDemoApp::~ImOsmDemoApp() {
  {
    mINI::INIStructure ini;
    mINI::INIFile iniFile(_iniFileNameMark);
    _markStorage->saveState(ini);
    iniFile.write(ini);
  }
  {
    mINI::INIStructure ini;
    mINI::INIFile iniFile(_iniFileNameMain);
    _mapPlot->saveState(ini);
    _tileSourceWidget->saveState(ini);
    _tileGrabberWidget->saveState(ini);
    iniFile.write(ini);
  }
}

void ImOsmDemoApp::beforeLoop() {}

void ImOsmDemoApp::firstPaint() {
  const ImGuiID centralNode{
      ImGui::DockBuilderGetCentralNode(dockSpaceID())->ID};
  ImGui::DockBuilderDockWindow("MapWidget", centralNode);
}

void ImOsmDemoApp::paint() {
  ImGui::Begin("MapWidget");

  ImGui::Text("FPS: %.0f", ImGui::GetIO().Framerate);
  ImGui::Text("MOUSE: lat %.2f, lon %.2f", _mapPlot->mouseLon(),
              _mapPlot->mouseLat());
  ImGui::Text("VIEW: lat %.2f:%.2f, lon %.2f:%.2f ", _mapPlot->minLat(),
              _mapPlot->maxLat(), _mapPlot->minLon(), _mapPlot->maxLon());

  // ImGui::Text("Tiles: %d", _mapPlot.loader().tilesNum());

  _worldBtn.paint();
  if (_worldBtn.handle()) {
    _mapPlot->setBoundsGeo(ImOsm::MinLat, ImOsm::MaxLat, ImOsm::MinLon,
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

  ImGui::Begin("MarkEditor");
  _distanceCalcWidget->paint();
  ImGui::Separator();
  _destinationCalcWidget->paint();
  ImGui::Separator();
  _markEditorWidget->paint();
  ImGui::End();

  ImGui::Begin("TileSource");
  _tileSourceWidget->paint();
  ImGui::Separator();
  _tileGrabberWidget->paint();
  ImGui::End();
}
