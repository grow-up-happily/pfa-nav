from setuptools import find_packages
from setuptools import setup

setup(
    name='rmoss_interfaces',
    version='0.9.0',
    packages=find_packages(
        include=('rmoss_interfaces', 'rmoss_interfaces.*')),
)
