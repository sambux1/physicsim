#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "polygon.hpp"
#include <vector>
using namespace std;

class Rectangle : public Polygon {

public:
    // constructor takes 4 points and automatically assigns edges
    // edges from p1->p2, p2->p3, p3->p4, p4->p1
    Rectangle(Point p1, Point p2, Point p3, Point p4);

    vector<Point> get_points();
};

#endif