#ifndef RTWEEKEND_CONTANTES_H
#define RTWEEKEND_CONTANTES_H

#include <cmath>
#include <limits>
#include <memory>

// using
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// constantes
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// utility functions
inline double degreesToRadians(double degrees){
    return degrees * pi / 180.0;
}

// Common headers
#include "vec3.h"
#include "ray.h"

#endif