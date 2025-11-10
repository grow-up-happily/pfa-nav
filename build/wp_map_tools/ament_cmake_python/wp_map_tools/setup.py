from setuptools import find_packages
from setuptools import setup

setup(
    name='wp_map_tools',
    version='1.0.0',
    packages=find_packages(
        include=('wp_map_tools', 'wp_map_tools.*')),
)
