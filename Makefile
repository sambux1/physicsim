CC = g++
PYLIBPATH = $(shell python-config --exec-prefix)/lib
LIB = -L$(PYLIBPATH) $(shell python-config --libs)# -lboost_python
OPTS = $(shell python-config --include)
INCLUDE = -I src/ -I /usr/include/python3.10/

SRC = src/particle.cpp
WRAPPER = wrapper/particle_wrapper.cpp

physicsim:
	$(CC) $(LIB) -Wl,-rpath,$(PYLIBPATH) -shared -o physicsim.so -fPIC $(SRC) $(WRAPPER) $(INCLUDE) -lboost_python

clean:
	find . -name '*.gch' -delete

.PHONY: default clean