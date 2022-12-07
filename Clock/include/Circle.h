#pragma once
#include "../graphics.h"
#include "Point.h"

class Circle {
private:
  Point center;
  int radius;
  bool isFilled;
  colors color;

public:
  Circle();
  Circle(int x, int y, int _radius, bool _isFilled, colors _color);
  void setCenter(int x, int y);
  void setRadius(int _radius);
  void setFillStyle(bool _isFilled, colors _color);
  Point getCenter();
  int getRadius();
  void print();
  void draw();
};