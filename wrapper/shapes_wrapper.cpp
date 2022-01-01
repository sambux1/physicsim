#include <boost/python.hpp>
#include "converters.cpp"

#include "shapes/polygon.hpp"
#include "shapes/rectangle.cpp"
#include "shapes/triangle.cpp"


BOOST_PYTHON_MODULE(shapes) {

    // handle automatic type conversions
    register_conversions();

    // load all the declarations
    Polygon_wrapper();
    Rectangle_wrapper();
    Triangle_wrapper();
}