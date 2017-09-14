#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <thread>
#include <atomic>
#include "pad.h"
#include "Ball.h"
#include <Windows.h>


using namespace std;

int WinMain(HINSTANCE hinstance,
	HINSTANCE hprevinstance,
	LPSTR lpcmdline,
	int ncmdshow)
{

    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width/2,sf::VideoMode::getDesktopMode().height/2),"Pong",sf::Style::Close|sf::Style::Resize);
	window.setVerticalSyncEnabled(true);

    Pad left(sf::Vector2f(0,window.getSize().y/2-25),window);

    Pad right(sf::Vector2f(window.getSize().x-10,window.getSize().y/2-25),window);

    Ball ball(&left.get_shape(),&right.get_shape(),&window);

	atomic<bool> keepRunning = true;


    sf::Text text;
    sf::Font font;
    font.loadFromFile("./font/zhaozi_20170912005410.ttf");
    text.setPosition((window.getSize().x/2-100),window.getSize().y/2);
    text.setStyle(sf::Text::Bold);
    text.setFont(font);
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(100);
	std::thread t([&]() {
		while (keepRunning)
		{
			ball.next();
			this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		ball.next();
		this_thread::sleep_for(std::chrono::milliseconds(10));
	});
	t.detach();

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				right.move(-10);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				right.move(10);
			}


        }
        window.clear(sf::Color(12, 123, 12));
        window.draw(left.get_shape());
        window.draw(right.get_shape());
        window.draw(ball);
        ball.judge();
        window.display();

    }
}
    catch (WinException& e){
		keepRunning = false;
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
	keepRunning = false;
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
