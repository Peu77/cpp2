//
// Created by Emil Ebert on 24.03.25.
//

#include "Point.h"
#include "colors.h"
#include <iostream>
#include <math.h>

Point::Point(): x(0), y(0) {
}

Point::Point(const Fixed &x, const Fixed &y): x(x), y(y) {
}

Point::Point(Point &p): x(p.x), y(p.y) {
}

Point::~Point() {
}

Point &Point::operator=(const Point &p) {
    this->x = p.x;
    this->y = p.y;
    return *this;
}

Fixed &Point::getX() {
    return this->x;
}

Fixed &Point::getY() {
    return this->y;
}

Fixed sign(Point &p1, Point &p2, Point &p3) {
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}


bool bsp(Point &a, Point &b, Point &c, Point &point) {
    Fixed d1, d2, d3;
    bool hasNeg, hasPos;

    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);

    hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(hasNeg && hasPos);
}

void drawTriangle(Point &a, Point &b, Point &c, const char *color) {
    const int MAX_SIZE = 30;

    int minX = std::min({a.getX().toInt(), b.getX().toInt(), c.getX().toInt()});
    int maxX = std::max({a.getX().toInt(), b.getX().toInt(), c.getX().toInt()});
    int minY = std::min({a.getY().toInt(), b.getY().toInt(), c.getY().toInt()});
    int maxY = std::max({a.getY().toInt(), b.getY().toInt(), c.getY().toInt()});

    minX = std::max(0, minX - 1);
    minY = std::max(0, minY - 1);
    maxX += 1;
    maxY += 1;

    int width = maxX - minX + 1;
    int height = maxY - minY + 1;

    if (width > MAX_SIZE || height > MAX_SIZE) {
        std::cout << "Triangle too large to display (max: " << MAX_SIZE << "x" << MAX_SIZE << ")" << std::endl;
        return;
    }

    bool grid[MAX_SIZE][MAX_SIZE] = {{false}};

    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            Point p(x, y);
            if (bsp(a, b, c, p)) {
                grid[y - minY][x - minX] = true;
            }
        }
    }


    std::cout << "Triangle visualization:" << std::endl;
    for (int y = height; y > 0; y--) {
        for (int x = width; x > 0; x--) {
            if (grid[y][x]) {
                std::cout << color << "█" << RESET;
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << "\nPoints:" << std::endl;
    std::cout << "A: (" << a.getX().toInt() << ", " << a.getY().toInt() << ")" << std::endl;
    std::cout << "B: (" << b.getX().toInt() << ", " << b.getY().toInt() << ")" << std::endl;
    std::cout << "C: (" << c.getX().toInt() << ", " << c.getY().toInt() << ")" << std::endl;
}
