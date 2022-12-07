#pragma once
#include "../graphics.h"
#include "Point.h"

class ClockPointer {
private:
  Point center;
  Point tip;
  int thickness;
  colors color;

public:
  ClockPointer();
  ClockPointer(int x1, int y1, int x2, int y2, int _thickness, colors _color);
  void setCenter(int x, int y);
  void setTip(int x, int y);
  void setThickness(int _thickness);
  void setColor(colors _color);
  Point getCenter();
  Point getTip();
  int getThickness();
  colors getColor();
  void print();
  void draw();
};