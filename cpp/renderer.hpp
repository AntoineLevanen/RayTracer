#ifndef RENDERER
#define RENDERER

#include <iostream>
#include <SFML/Graphics.hpp>
#include <eigen3/Eigen/Dense>

using Eigen::Vector3d;
using Eigen::Matrix3d;

class Renderer
{
    private:
    const unsigned height;
    const unsigned width;
    Vector3d camera_position;
    Matrix3d camera_orientation;
public:
    Renderer(unsigned h, unsigned w);
    sf::Texture renderImage();
};

#endif