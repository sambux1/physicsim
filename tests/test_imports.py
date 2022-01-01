# test that all modules are imported correctly
# test that all classes are included in modules

import unittest

class TestImports(unittest.TestCase):

    def test_package_exists(self):
        import physicsim
    
    def test_modules_exist(self):
        import physicsim
        modules = ['core', 'shapes']
        for module in modules:
            self.assertTrue(module in dir(physicsim))
    
    def test_core_module(self):
        from physicsim import core
        classes = ['Particle']
        for c in classes:
            self.assertTrue(c in dir(core))
    
    def test_shapes_module(self):
        from physicsim import shapes
        classes = ['Point', 'Edge', 'Polygon', 'Triangle', 'Rectangle']
        for c in classes:
            self.assertTrue(c in dir(shapes))
