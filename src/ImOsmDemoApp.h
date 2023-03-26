#pragma once
#include <imapp.h>
#include <imosm.h>
#include <imwrap.h>

class ImOsmDemoApp : public ImApp::MainWindow {
public:
  ImOsmDemoApp();
  ~ImOsmDemoApp();

protected:
  void beforeLoop() override;
  void paint() override;

private:
  ImWrap::Button _worldBtn{"World"};
  ImWrap::Button _berlinBtn{"Berlin"};
  ImWrap::Button _parisBtn{"Paris"};
  ImWrap::Button _madridBtn{"Madrid"};
  bool _firstPaint{true};

  ImOsm::MapPlot _mapPlot;
};
