//
// Created by Emil Ebert on 24.03.25.
//

#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {
  private:
    Fixed x;
    Fixed y;

    public:
      Point();
      Point(const Fixed& x, const Fixed& y);
      Point(Point& p);
      ~Point();

      Point &operator=(const Point& p);

      Fixed& getX();
      Fixed& getY();
};

bool bsp(Point& a, Point& b, Point& c, Point& point);

void drawTriangle(Point& a, Point& b, Point& c, const char* color);


#endif //POINT_H
