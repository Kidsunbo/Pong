#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "pad.h"
#include "Ball.h"


using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width/2,sf::VideoMode::getDesktopMode().height/2),"Pong",sf::Style::Close|sf::Style::Resize);
	window.setVerticalSyncEnabled(true);

    Pad left(sf::Vector2f(0,window.getSize().y/2-25),window);

    Pad right(sf::Vector2f(window.getSize().x-10,window.getSize().y/2-25),window);

    Ball ball(&left.get_shape(),&right.get_shape(),&window);

    sf::Text text;
    sf::Font font;
    font.loadFromFile("/Users/sunbo/Desktop/Pong/zhaozi_20170912005410.ttf");
    text.setPosition((window.getSize().x/2),window.getSize().y/2);
    text.setStyle(sf::Text::Bold);
    text.setFont(font);
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(100);

try {
    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    right.move(event.mouseWheelScroll.delta);
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                left.move(-10);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                left.move(10);
            }

        }
        window.clear(sf::Color(12, 123, 12));
        window.draw(left.get_shape());
        window.draw(right.get_shape());
        window.draw(ball);
        ball.next();
        window.display();

    }
}
    catch (WinException& e){
        text.setString(e.what());
        while (window.isOpen()) {

            sf::Event event;

            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                }

            }
            window.clear(sf::Color(12, 123, 12));
            window.draw(left.get_shape());
            window.draw(right.get_shape());
            window.draw(ball);
            window.draw(text);
            window.display();

        }
    }
catch (LoseException& e){
    text.setString(e.what());
    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }
        window.clear(sf::Color(12, 123, 12));
        window.draw(left.get_shape());
        window.draw(right.get_shape());
        window.draw(ball);
        window.draw(text);
        window.display();

    }
}


    return 0;
}
