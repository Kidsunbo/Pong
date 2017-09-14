#ifndef PAD_H
#define PAD_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Pad
{


    const sf::Window* window= nullptr;
    sf::RectangleShape shape;
    Pad(sf::Vector2f vec);


public:
    Pad();
    Pad(sf::Vector2f vec, sf::Window &window);


    void move(float);




    sf::RectangleShape& get_shape();





};

#endif // PAD_H
