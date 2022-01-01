/*
A file for converting data types between C++ and Python
*/

#include <boost/python.hpp>
#include <vector>
using namespace boost::python;

#include "shapes/polygon.hpp"

// converts a vector to a Python list
template<typename T>
struct vector_to_pylist {

    // constructor
    // registers the conversion using the generic type T
    vector_to_pylist() {
        to_python_converter<std::vector<T>, vector_to_pylist>();
    }

    static PyObject* convert(std::vector<T> const& v) {
        // creates a boost::python::list which can be returned to python
        list output;

        // iterate over the vector and append elements to the list
        for (auto value : v) {
            output.append(value);
        }

        return incref(output.ptr());
    }
};

// converts a Python list to a vector<float>
struct pylist_to_vector {
    // before we can convert, we need to make sure a conversion is possible
    static void* convertible(PyObject* object) {
        // check if the object is a Python list
        if (!PyList_Check(object)) {
            return nullptr;
        }

        int size = PySequence_Size(object);
        for (int i = 0; i < size; i++) {
            // check that each element is a float
            if (!PyFloat_Check(PyList_GetItem(object, i))) {
                return nullptr;
            }
        }

        // if it gets here, the list is valid and convertible
        return object;
    }

    // build the output vector
    static void construct(PyObject* object, converter::rvalue_from_python_stage1_data* data) {
        typedef converter::rvalue_from_python_storage<std::vector<float>> storage_type;
        void* storage = reinterpret_cast<storage_type*>(data)->storage.bytes;

        data->convertible = new (storage) std::vector<float>();
        
        std::vector<float>* v = (std::vector<float>*)(storage);

        int size = PySequence_Size(object);
        for (int i = 0; i < size; i++) {
            v->push_back(extract<float>(PyList_GetItem(object, i)));
        }
    }
};


// a function to register each of the conversions
// called by each module
// each of the conversions is defined in its constructor
void register_conversions() {

    // converts vector to Python list
    // need to create one instance per type
    vector_to_pylist<float> v_float;
    vector_to_pylist<shapes::Point> v_point;

    // converts from Python list to vector<float>
    converter::registry::push_back(&pylist_to_vector::convertible
        , &pylist_to_vector::construct
        , type_id<std::vector<float>>()
    );

}