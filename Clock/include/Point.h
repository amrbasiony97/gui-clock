#pragma once
#include <iostream>

class Point {
private:
  int x;
  int y;

public:
  Point();
  Point(int _x, int _y);
  Point(Point& p);
  void setX(int _x);
  void setY(int _y);
  int getX();
  int getY();
  void setPoint(int _x, int _y);
  void print();
};