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
  std::unique_ptr<ImOsm::RichMarkWidget> _markWidget{
      std::make_unique<ImOsm::RichMarkWidget>(_mapPlot, _markStorage)};
};
