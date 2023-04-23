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

  std::shared_ptr<ImOsm::RichMapPlot> _mapPlot{
      std::make_shared<ImOsm::RichMapPlot>()};

  std::shared_ptr<ImOsm::RichMarkStorage> _markStorage{
      std::make_shared<ImOsm::RichMarkStorage>()};

  std::unique_ptr<ImOsm::RichMarkEditorWidget> _markEditorWidget{
      std::make_unique<ImOsm::RichMarkEditorWidget>(_mapPlot, _markStorage)};

  std::unique_ptr<ImOsm::RichDistanceCalcWidget> _distanceCalcWidget{
      std::make_unique<ImOsm::RichDistanceCalcWidget>(_markStorage)};

  std::unique_ptr<ImOsm::RichDestinationCalcWidget> _destinationCalcWidget{
      std::make_unique<ImOsm::RichDestinationCalcWidget>(_markStorage)};

  const std::string _iniFileNameMain{"imosm_demo.ini"};
  const std::string _iniFileNameMark{"imosm_mark.ini"};
};
