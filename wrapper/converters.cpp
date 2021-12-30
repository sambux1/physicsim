/*
A file for converting data types between C++ and Python
*/

#include <boost/python.hpp>
#include <vector>
using namespace boost::python;

// converts a vector<float> to a python list
struct vector_to_pylist {
    static PyObject* convert(std::vector<float> const& v) {
        // creates a boost::python::list which can be returned to python
        list output;

        // iterate over the vector and append elements to the list
        for (float f : v) {
            output.append(f);
        }

        return incref(output.ptr());
    }
};