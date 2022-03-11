#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "shapes/polygon.hpp"
#include "shapes/rectangle.cpp"
#include "shapes/triangle.cpp"


PYBIND11_MODULE(shapes, m) {
    Polygon_wrapper(m);
    Rectangle_wrapper(m);
    Triangle_wrapper(m);
}