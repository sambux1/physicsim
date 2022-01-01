#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "polygon.hpp"
#include <vector>

namespace shapes {

class Rectangle : public Polygon {

public:
    // constructor takes 4 points and automatically assigns edges
    // edges from p1->p2, p2->p3, p3->p4, p4->p1
    Rectangle(Point p1, Point p2, Point p3, Point p4);

    std::vector<Point> get_points();
};

} // namespace shapes



// wrapper
#include <boost/python.hpp>
inline void Rectangle_wrapper() {
    namespace py = boost::python;

    // declare the Rectangle class
    py::class_<shapes::Rectangle, py::bases<shapes::Polygon> >("Rectangle", py::init<
                            shapes::Point, shapes::Point, shapes::Point, shapes::Point>())
        .def("get_points", &shapes::Rectangle::get_points)
    ;
}

#endif