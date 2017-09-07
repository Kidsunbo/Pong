//
// Created by 孙博 on 2017/9/6.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <SFML/Graphics>
#include <SFML/Graphics/CircleShape.hpp>

class ball: public sf::CircleShape {


public:
    double get_distance(sf::Shape& s);


};


#endif //PONG_BALL_H
