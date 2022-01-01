# BUILD SCRIPT

# universal compiler options
OPTS="-I physicsim/ -I /usr/include/python3.10/ -lboost_python"

# --------------------
# core module
# --------------------
CORE="wrapper/core_wrapper.cpp"
g++ -shared -o core.so -fPIC $CORE $OPTS

# --------------------
# shapes module
# --------------------
SHAPES="wrapper/shapes_wrapper.cpp"
g++ -shared -o shapes.so -fPIC $SHAPES $OPTS


# move all output files into the build directory
mkdir -p build/physicsim/
mv *.so build/physicsim/
cp __init__.py build/physicsim/
cp setup.py build/

# install the package
pip install build/

# run the testing suite

