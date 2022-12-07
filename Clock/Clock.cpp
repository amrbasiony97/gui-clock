#include <iostream>
#include "graphics.h"
#include "clock.h"
#pragma comment(lib,"graphics.lib")
using namespace std;

int main() {
  initwindow(800, 600);
  
  // Clock Center Point
  Point center(getmaxx() / 2, getmaxy() / 2);
  
  // Clock Center Circle
  Circle* clockCenter = new Circle(center.getX(), center.getY(), 8, true, WHITE);

  // Clock Frame
  Circle* outerFrame = new Circle(center.getX(), center.getY(), 250, true, YELLOW);
  Circle* innerFrame = new Circle(center.getX(), center.getY(), 230, true, BLACK);

  // Clock Edges
  Line* edgeLines = new Line[LINES_COUNT];
  Circle* edgeCircles = new Circle[CIRCLES_COUNT];
  int* circlesCount = new int(0);
  int* linesCount = new int(0);
  double angle = 0;

  for (int i = 0; i < 60; i++) {
    if (i % 5) {
      edgeLines[*linesCount].setP1(center.getX() + (int)(sin(angle) * 200), center.getY() + (int)(cos(angle) * 200));
      edgeLines[*linesCount].setP2(center.getX() + (int)(sin(angle) * 210), center.getY() + (int)(cos(angle) * 210));
      (*linesCount)++;
    }
    else {
      edgeCircles[*circlesCount].setCenter(center.getX() + (int)(sin(angle) * 205), center.getY() + (int)(cos(angle) * 205));
      edgeCircles[*circlesCount].setRadius(5);
      edgeCircles[*circlesCount].setFillStyle(true, WHITE);
      (*circlesCount)++;
    }
    angle += (M_PI / 30);
  }
  delete linesCount;
  delete circlesCount;
  int hour;
  double minute, second;
  double hourAngle, minAngle, secAngle;

  // Clock Pointers
  ClockPointer* secPtr = new ClockPointer(
    center.getX(), center.getY(), 0, 0, 1, YELLOW);

  ClockPointer* minPtr = new ClockPointer(
    center.getX(), center.getY(), 0, 0, 5, CYAN);

  ClockPointer* hourPtr = new ClockPointer(
    center.getX(), center.getY(), 0, 0, 9, WHITE);


  Time* current_time = new Time();
  
  while (true) {
    cleardevice();

    current_time->update_now();
    
    hour = current_time->getHour();
    minute = current_time->getMinute();
    second = current_time->getSecond();
    
    hourAngle = ((hour % 12) + (minute / 60) + (second / 3600)) * M_PI / 6;
    minAngle = (minute + (second / 60)) * M_PI / 30;
    secAngle = (second + current_time->getMillisecond() / 1000) * M_PI / 30;

    hourPtr->setTip(center.getX() + (int)(sin(hourAngle) * 120),
      center.getY() - (int)(cos(hourAngle) * 120));
    minPtr->setTip(center.getX() + (int)(sin(minAngle) * 150),
      center.getY() - (int)(cos(minAngle) * 150));
    secPtr->setTip(center.getX() + (int)(sin(secAngle) * 180),
      center.getY() - (int)(cos(secAngle) * 180));

    outerFrame->draw();
    innerFrame->draw();
    clockCenter->draw();

    for (int i = 0; i < CIRCLES_COUNT; i++)
      edgeCircles[i].draw();

    for (int i = 0; i < LINES_COUNT; i++)
      edgeLines[i].draw();

    hourPtr->draw();
    minPtr->draw();
    secPtr->draw();

    Sleep(1000 / 60);
    swapbuffers();
  }

  delete current_time;
  delete hourPtr;
  delete minPtr;
  delete secPtr;
  delete[] edgeCircles;
  delete[] edgeLines;
  delete clockCenter;
  delete innerFrame;
  delete outerFrame;

  return 0;
}
