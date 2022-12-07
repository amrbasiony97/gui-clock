#include "../include/ClockPointer.h"

ClockPointer::ClockPointer() :center(0, 0), tip(0, 0) {
  thickness = 0;
  color = WHITE;
}

ClockPointer::ClockPointer(int x1, int y1, int x2, int y2, int _thickness, colors _color) :center(x1, y1), tip(x2, y2) {
  thickness = _thickness;
  color = _color;
}

void ClockPointer::setCenter(int x, int y) {
  center.setPoint(x, y);
}

void ClockPointer::setTip(int x, int y) {
  tip.setPoint(x, y);
}

void ClockPointer::setThickness(int _thickness) {
  thickness = _thickness;
}

void ClockPointer::setColor(colors _color) {
  color = _color;
}

Point ClockPointer::getCenter() {
  return center;
}

Point ClockPointer::getTip() {
  return tip;
}

int ClockPointer::getThickness() {
  return thickness;
}

colors ClockPointer::getColor() {
  return color;
}

void ClockPointer::print() {
  std::cout << "Center = ";
  center.print();
  std::cout << "Tip = ";
  tip.print();
  std::cout << "Thickness = " << thickness << std::endl;
}

void ClockPointer::draw() {
  setlinestyle(0, 0, thickness);
  setcolor(color);
  line(center.getX(), center.getY(), tip.getX(), tip.getY());
  setlinestyle(0, 0, 0);
  setcolor(WHITE);
}