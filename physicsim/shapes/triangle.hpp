#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "polygon.hpp"
#include <vector>
using namespace std;

class Triangle : public Polygon {

public:
    // constructor takes 3 points and automatically assigns edges
    // edges from p1->p2, p2->p3, p3->p1
    Triangle(Point p1, Point p2, Point p3);

    vector<Point> get_points();
};

#endif