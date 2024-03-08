# RayTracer

## Dependencies
...

## Python
May be use for the interface

## C++
Core of the ray tracer.
###  Compilation
First, create the build directory
```
cmake -B ./build && cd build/
```

Then build the project by using the make commande.
```
make && ./ray_tracer > image.ppm
```
*The project is under developpement, the resulting image is wrote in a file using bash redirection*

## Resources
Ray tracing in one weekend : 
https://raytracing.github.io/books/RayTracingInOneWeekend.html#rays,asimplecamera,andbackground

Current chapter : 6.8 An Interval Class