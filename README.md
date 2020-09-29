# TNCG15-Raytracer
A Monte-Carlo raytracer implemented for the course TNCG15 at Linköping University.

## Build instructions
The default is to build for Release. To be explicit follow instructions below.
From root of repo run
```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```
To build for Debug with debugging information present just substitute Release with Debug.

This should create the /bin path

To then run
```shell
cd ../bin/release
./tncg15-raytracer
```
Similarly here you substitute /release for /debug for the approriate build type.
