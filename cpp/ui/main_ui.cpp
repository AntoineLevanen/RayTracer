#include <iostream>
#include <SFML/Graphics.hpp>
#include <eigen3/Eigen/Dense>

using Eigen::Vector3d;
using Eigen::Matrix3d;

#include "renderer.hpp"

int main()
{
    // window and image dimention
    const unsigned width = 300;
    const unsigned height = 200;

    // render engine
    Renderer my_renderer(width, height);
    sf::Texture my_texture = my_renderer.renderImage();
    sf::Sprite my_sprite;
    my_sprite.setTexture(my_texture);

    // creating SFML window
    sf::RenderWindow window(sf::VideoMode(width, height), "Ray Tracer");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(my_sprite);
        window.display();
    }

    return 0;
}