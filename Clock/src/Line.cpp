#include "../include/Line.h"

Line::Line() :p1(0, 0), p2(0, 0) {}

Line::Line(int x1, int y1, int x2, int y2) :p1(x1, y1), p2(x2, y2) {}

void Line::setP1(int x, int y) {
  p1.setPoint(x, y);
}

void Line::setP2(int x, int y) {
  p2.setPoint(x, y);
}

Point Line::getP1() {
  return p1;
}

Point Line::getP2() {
  return p2;
}

void Line::print() {
  std::cout << "Point 1 = ";
  p1.print();
  std::cout << "Point 2 = ";
  p2.print();
}

void Line::draw() {
  line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}