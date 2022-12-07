#include "../include/Circle.h"

Circle::Circle() :center(0, 0) {
  radius = 0;
  isFilled = false;
  color = BLACK;
}

Circle::Circle(int x, int y, int _radius, bool _isFilled, colors _color) :center(x, y) {
  radius = _radius;
  isFilled = _isFilled;
  color = _color;
}

void Circle::setCenter(int x, int y) {
  center.setPoint(x, y);
}

void Circle::setRadius(int _radius) {
  radius = _radius;
}

void Circle::setFillStyle(bool _isFilled, colors _color) {
  isFilled = _isFilled;
  color = _color;
}

Point Circle::getCenter() {
  return center;
}

int Circle::getRadius() {
  return radius;
}

void Circle::print() {
  std::cout << "Center = ";
  center.print();
  std::cout << "Radius = " << radius;
}

void Circle::draw() {
  if (isFilled) {
    setfillstyle(SOLID_FILL, color);
    fillellipse(center.getX(), center.getY(), radius, radius);
  }
  else
    circle(center.getX(), center.getY(), radius);
}