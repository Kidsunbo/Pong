#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "pad.h"


using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width/2,sf::VideoMode::getDesktopMode().height/2),"Pong",sf::Style::Close|sf::Style::Resize);
	window.setVerticalSyncEnabled(true);

    Pad left(sf::Vector2f(0,window.getSize().y/2-25),window);

    Pad right(sf::Vector2f(window.getSize().x-10,window.getSize().y/2-25),window);


    while(window.isOpen()){

        sf::Event event;

        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.type == sf::Event::MouseWheelScrolled){
                if(event.mouseWheelScroll.wheel==sf::Mouse::VerticalWheel){
                    right.move(event.mouseWheelScroll.delta);
                }
            }

        }

        window.clear(sf::Color(123,123,123));
        window.draw(left.get_shape());
        window.draw(right.get_shape());


        window.display();


    }


    return 0;
}
