#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "polygon.hpp"
#include <vector>

namespace shapes {

class Triangle : public Polygon {

public:
    // constructor takes 3 points and automatically assigns edges
    // edges from p1->p2, p2->p3, p3->p1
    Triangle(Point p1, Point p2, Point p3);

    std::vector<Point> get_points();
};

} // namespace shapes



// wrapper
#include <pybind11/pybind11.h>
void Triangle_wrapper(pybind11::module_ m) {
    namespace py = pybind11;
    
    // declare the Triangle class
    py::class_<shapes::Triangle, shapes::Polygon>(m, "Triangle")
        .def(py::init<shapes::Point, shapes::Point, shapes::Point>())
        .def("get_points", &shapes::Triangle::get_points)
    ;
}

#endif