#include "rectangle.hpp"
#include <vector>
#include <iostream>
using namespace std;

namespace shapes {

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4) {
    this->points.push_back(p1);
    this->points.push_back(p2);
    this->points.push_back(p3);
    this->points.push_back(p4);

    this->edges.push_back(Edge(&p1, &p2));
    this->edges.push_back(Edge(&p2, &p3));
    this->edges.push_back(Edge(&p3, &p4));
    this->edges.push_back(Edge(&p4, &p1));
}

vector<Point> Rectangle::get_points() {
    return this->points;
}

} // namespace shapes
