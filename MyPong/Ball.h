//
// Created by 孙博 on 2017/9/11.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <SFML/Graphics.hpp>
#include "LoopException.h"


class Ball:public sf::CircleShape{

private:
    sf::Shape* left= nullptr;
    sf::Shape* right = nullptr;
    sf::RenderWindow* window= nullptr;

    bool toward_left = true;
    bool toward_up=true;

public:

    Ball(sf::Shape* left,sf::Shape* right,sf::RenderWindow* window):left(left),right(right),window(window){
        this->setFillColor(sf::Color::Black);
        this->setRadius(10);
        this->setPosition(window->getSize().x/2,window->getSize().y/2);
    }

    void next(){
        auto temp_position = this->getPosition();
        this->setPosition(this->getPosition().x+(toward_left?-1:1),this->getPosition().y+(toward_up?-1:1));
        if(temp_position.y<0){
            this->toward_up = false;
        }
        else if(temp_position.y>window->getSize().y-20){
            this->toward_up= true;
        }
    }

	void judge() {
		auto temp_position = this->getPosition();

		if (temp_position.x<10) {
			if (temp_position.y - left->getPosition().y<50 && temp_position.y - left->getPosition().y>-20) {
				this->toward_left = false;
			}
			else {
				throw WinException("You Win!");
			}
		}
		else if (temp_position.x>window->getSize().x - 30) {
			if (temp_position.y - right->getPosition().y<50 && temp_position.y - right->getPosition().y>-20) {
				this->toward_left = true;
			}
			else {
				throw LoseException("You Lose!");
			}
		}
	}

};




#endif //PONG_BALL_H
