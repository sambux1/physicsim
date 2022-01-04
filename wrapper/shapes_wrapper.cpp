#include <boost/python.hpp>

#include "shapes/polygon.hpp"
#include "shapes/rectangle.cpp"
#include "shapes/triangle.cpp"


BOOST_PYTHON_MODULE(shapes) {
    Polygon_wrapper();
    Rectangle_wrapper();
    Triangle_wrapper();
}