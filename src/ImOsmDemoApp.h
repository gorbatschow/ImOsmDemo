#pragma once
#include <imapp.h>
#include <imosm.h>
#include <imosm_rich.h>
#include <imwrap.h>

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

  std::shared_ptr<ImOsm::Rich::RichMapPlot> _mapPlot{
      std::make_shared<ImOsm::Rich::RichMapPlot>()};

  std::shared_ptr<ImOsm::Rich::MarkStorage> _markStorage{
      std::make_shared<ImOsm::Rich::MarkStorage>()};

  std::unique_ptr<ImOsm::Rich::MarkEditorWidget> _markEditorWidget{
      std::make_unique<ImOsm::Rich::MarkEditorWidget>(_mapPlot, _markStorage)};

  std::unique_ptr<ImOsm::Rich::DistanceCalcWidget> _distanceCalcWidget{
      std::make_unique<ImOsm::Rich::DistanceCalcWidget>(_markStorage)};

  std::unique_ptr<ImOsm::Rich::DestinationCalcWidget> _destinationCalcWidget{
      std::make_unique<ImOsm::Rich::DestinationCalcWidget>(_markStorage)};

  const std::string _iniFileNameMain{"imosm_demo.ini"};
  const std::string _iniFileNameMark{"imosm_mark.ini"};
};
