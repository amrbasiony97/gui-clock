#pragma once
#include "../graphics.h"
#include "Point.h"

class Line {
private:
  Point p1;
  Point p2;

public:
  Line();
  Line(int x1, int y1, int x2, int y2);
  void setP1(int x, int y);
  void setP2(int x, int y);
  Point getP1();
  Point getP2();
  void print();
  void draw();
};
