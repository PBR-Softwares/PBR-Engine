# PBR-Engine
<!--[![Build Status](https://travis-ci.org/eroween/DefaultProject.svg?branch=master)](https://travis-ci.org/eroween/DefaultProject)-->
<!--[![Build status](https://ci.appveyor.com/api/projects/status/github/eroween/DefaultProject?svg=true)](https://ci.appveyor.com/project/eroween/DefaultProject)-->
<!--[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](http://www.gnu.org/licenses/gpl-3.0)-->

This project is a physically based engine, the only purpose of this engine is to be used by differents rendering technique. The engine alone don't display anything, it's only the 3D scene with some basic feature.

# Compilation

## Release

```shell
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=release ..
make
```

## Debug

The debug compilation add extra flags enabling debugging environment to trace
the program.

```shell
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=debug ..
make
```

