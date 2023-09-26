#include <iostream>
#include <SFML/Graphics.hpp>
#include <eigen3/Eigen/Dense>

using Eigen::Vector3d;
using Eigen::Matrix3d;

int main()
{

    // testing Eigen include
    Vector3d vect = Vector3d::Random();
    std::cout << vect << std::endl;

    Matrix3d matrix = Matrix3d::Random();
    std::cout << matrix << std::endl;

    std::cout << matrix * vect << std::endl;




    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}