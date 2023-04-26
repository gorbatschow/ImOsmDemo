#pragma once
#include <imapp.h>
#include <imosm.h>
#include <imosm_rich.h>
#include <imwrap.h>

namespace ImOsm {
namespace Rich {
class RichMapPlot;
class MarkStorage;
class MarkEditorWidget;
class DistanceCalcWidget;
class DestinationCalcWidget;
} // namespace Rich
} // namespace ImOsm

class ImOsmDemoApp : public ImApp::MainWindow {
public:
  ImOsmDemoApp();
  ~ImOsmDemoApp();

protected:
  void beforeLoop() override;
  void firstPaint() override;
  void paint() override;

private:
  ImWrap::Button _worldBtn{"World"};
  ImWrap::Button _berlinBtn{"Berlin"};
  ImWrap::Button _parisBtn{"Paris"};
  ImWrap::Button _madridBtn{"Madrid"};

  std::shared_ptr<ImOsm::Rich::RichMapPlot> _mapPlot;
  std::shared_ptr<ImOsm::Rich::MarkStorage> _markStorage;
  std::unique_ptr<ImOsm::Rich::MarkEditorWidget> _markEditorWidget;
  std::unique_ptr<ImOsm::Rich::DistanceCalcWidget> _distanceCalcWidget;
  std::unique_ptr<ImOsm::Rich::DestinationCalcWidget> _destinationCalcWidget;
  std::unique_ptr<ImOsm::TileSourceWidget> _tileSourceWidget;
  std::unique_ptr<ImOsm::TileGrabberWidget> _tileGrabberWidget;

  const std::string _iniFileNameMain{"imosm_demo.ini"};
  const std::string _iniFileNameMark{"imosm_mark.ini"};
};
