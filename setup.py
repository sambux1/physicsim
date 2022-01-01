from setuptools import setup

setup(name='physicsim',
      description='A physical simulation library.',
      version='0.1',
      author='Sam Buxbaum',
      license='GPLv3',
      packages=['physicsim'],
      package_data={'physicsim': ['core.so', 'shapes.so']})