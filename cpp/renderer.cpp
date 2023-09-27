#include <iostream>
#include <SFML/Graphics.hpp>
#include <eigen3/Eigen/Dense>

using Eigen::Vector3d;
using Eigen::Matrix3d;

#include "renderer.hpp"



Renderer::Renderer(unsigned w, unsigned h): width(w), height(h){
    camera_position = Vector3d(0, 0, 0);
    camera_orientation = Matrix3d::Identity(3, 3);
}

sf::Texture Renderer::renderImage(){
    const unsigned num_pixel = unsigned(this->width * this->height);
    sf::Uint8 pixels[4 * num_pixel]; // four color channel, R G B A
    // {
    //     0, 0, 0, 255,// black
    //     255, 0, 0, 255, // red
    //     0, 255, 0, 255,// green
    //     0, 0, 255, 255, // blue
    //     255, 255, 255, 255,// white
    //     125, 125, 125, 255// grey

    // };
    int k = 0;
    for(int i = 0; i < this->width ; i++){
        if(i % 4 == 0){
            for(int j = 0; j < this->height; j++){
                if(j % 4 == 0){
                    unsigned value = unsigned(k * 255 / this->width);
                    
                    pixels[i + j] = value;
                    pixels[i + j + 1] = value;
                    pixels[i + j + 2] = value;
                    pixels[i + j + 3] = 255;
                    
                    // std::cout << "i : " << i << "    k"<<'%'<<"height : "<< (k % this->width)  << "   pixel value : " <<unsigned((k % this->width) * 255 / this->height)<< std::endl;
                    k++;

                    if(k > this->width) k = 0;
                }
            }
        }
    }

    sf::Image image;
    image.create(this->width, this->height, pixels);

    sf::Texture texture;
    texture.loadFromImage(image);
    /*
    sprite store a pointer to a texture, by returning the sprite, 
    the texture is destroyed at function return statement.
    see https://www.sfml-dev.org/tutorials/2.4/graphics-sprite.php
    */
    return texture;
}