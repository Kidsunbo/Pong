#include "pad.h"

Pad::Pad()
{

}

Pad::Pad(sf::Vector2f vec,sf::Window& window):Pad(vec){
    this->window=&window;
}

void Pad::move(float d){

    if((d+this->shape.getPosition().y+50)>this->window->getSize().y){
        this->shape.move(0,this->window->getSize().y-this->shape.getPosition().y-50);
    }
    else if((d+this->shape.getPosition().y)<0){
        this->shape.move(0,0-this->shape.getPosition().y);
    }
    else{
        this->shape.move(0,d);
    }
}


sf::RectangleShape & Pad::get_shape(){
    return shape;
}

Pad::Pad(sf::Vector2f vec) {
    this->shape = sf::RectangleShape();
    this->shape.setPosition(vec);
    this->shape.setSize(sf::Vector2f(10,50));
    this->shape.setFillColor(sf::Color::Red);
}


