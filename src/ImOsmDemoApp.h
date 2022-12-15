#pragma once
#include <ImApplication.h>
#include <ImOsmWidget.h>

class ImOsmDemoApp : public ImApplication {
public:
  ImOsmDemoApp();
  ~ImOsmDemoApp();

protected:
  void paint() override;

private:
  ImOsmWidget _osmWidget;
};
