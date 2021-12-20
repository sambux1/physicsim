from setuptools import setup, Extension

setup(
    #...
    ext_modules=[Extension('particle', ['particle.cpp'],),],
)