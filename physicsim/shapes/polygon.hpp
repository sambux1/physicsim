#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>

namespace shapes {

typedef struct Point {
    int x;
    int y;

    Point() {}
    Point(int x, int y) : x(x), y(y) {}
} Point;

typedef struct Edge {
    Point* a;
    Point* b;

    Edge() {}
    Edge(Point* a, Point* b) : a(a), b(b) {}
} Edge;

class Polygon {

public:
    std::vector<Point> points;
    std::vector<Edge> edges;

};

} // namespace shapes



// wrapper
#include <pybind11/pybind11.h>
void Polygon_wrapper(pybind11::module_ m) {
    namespace py = pybind11;

    // declare the Point Class
    py::class_<shapes::Point>(m, "Point")
        .def(py::init<>())
        .def(py::init<int, int>())
        .def_readwrite("x", &shapes::Point::x)
        .def_readwrite("y", &shapes::Point::y)
    ;

    // declare the Edge class
    py::class_<shapes::Edge>(m, "Edge")
        .def(py::init<>())
        .def(py::init<shapes::Point*, shapes::Point*>())
        .def_readwrite("a", &shapes::Edge::a)
        .def_readwrite("b", &shapes::Edge::b)
    ;

    // declare the Polygon base class
    py::class_<shapes::Polygon>(m, "Polygon")
        .def_readonly("points", &shapes::Polygon::points)
        .def_readonly("edges", &shapes::Polygon::edges)
    ;
}

#endif