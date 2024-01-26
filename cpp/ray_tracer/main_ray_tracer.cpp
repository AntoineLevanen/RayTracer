#include "color.h"
#include "vec3.h"

#include <iostream>

int main(){

    // image informations
    unsigned image_width = 256;
    unsigned image_height = 256;

    // render

    std::cout << "P3\n" << image_width << ' ' << image_height  << "\n255\n";

    for(int j = 0; j < image_height; ++j){
        std::clog << "\rScanlines remainning: " << (image_height - j) << ' ' << std::flush;
        for(int i = 0; i < image_width; ++i){
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0 );
        }
    }
    std::clog << "\rDone.               \n";
}

/*
in /RayTracer/cpp
make ray_tracer && ./build/ray_tracer > ray_tracer/image.ppm
*/

/*

4. Rays, a Simple Camera, and Background

*/