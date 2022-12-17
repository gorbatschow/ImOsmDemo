#pragma once
#include <ImApplication.h>
#include <ImOsmWidget.h>
#include <ImWrapper.h>

class ImOsmDemoApp : public ImApplication {
public:
  ImOsmDemoApp();
  ~ImOsmDemoApp();

protected:
  void beforeLoop() override;
  void paint() override;

private:
  ImOsmWidget _osmWidget;
  ImWrap::Button _worldBtn{"World"};
  ImWrap::Button _berlinBtn{"Berlin"};
  ImWrap::Button _parisBtn{"Paris"};
  ImWrap::Button _madridBtn{"Madrid"};
  bool _firstPaint{true};
};
