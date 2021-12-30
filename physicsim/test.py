from ctypes import cdll
lib = cdll.LoadLibrary('./build/lib.linux-x86_64-3.10/particle.cpython-310-x86_64-linux-gnu.so')

class Particle(object):
    def __init__(self):
        print('hey')
        self.obj = lib.Particle_new_dim(3)
        print('hey22')
        print(self.obj)
        self.dimension = lib.Particle_get_dimension(self.obj)
        print('hey33')

particle = Particle()
print(particle.dimension)