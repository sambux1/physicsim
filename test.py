from ctypes import cdll
lib = cdll.LoadLibrary('./build/lib.linux-x86_64-3.10/particle.cpython-310-x86_64-linux-gnu.so')

class Particle(object):
    def __init__(self):
        print('hey')
        self.obj = lib.Particle(3)
        print('hey2')

particle = Particle()
