from setuptools import setup, Extension

src_files = ['physicsim/particle.cpp', 'physicsim/shapes/polygon.hpp',
             'physicsim/shapes/rectangle.cpp', 'physicsim/shapes/triangle.cpp']
wrapper_files = ['wrapper/particle_wrapper.cpp']

setup(name='physicsim', version='0.1', author='Sam Buxbaum',
    ext_modules=[Extension('physicsim',
                            sources=['physicsim/particle.cpp', 'wrapper/particle_wrapper.cpp'],
                            include_dirs=['/usr/include/python3.10/', 'physicsim'],
                            extra_compile_args=['-fPIC'],
                            libraries=['boost_python']
                )],
)