#include "Paddle.h"



Paddle::Paddle(int width,int height,sf::Color col,sf::Vector2f position,bool userc)
{
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setPosition(position);
	rectangle.setFillColor(col);

	pos = position;
	shape = rectangle;
	usercontrolled = userc;
}


Paddle::~Paddle()
{
}

void Paddle::move(int where){
	
	if (where == 1)
		//shape.move(sf::Vector2f(0,-speed));
		pos.y -= speed;
	else if (where==0)
		//shape.move(sf::Vector2f(0, speed));
		pos.y += speed;
	else {
		pos.y = where;
	}
	if (pos.y <= 0)
		pos.y = 0;
	if (pos.y + shape.getSize().y>= 600)
		pos.y = 600 - shape.getSize().y;
	shape.setPosition(pos);
	
}
void Paddle::draw(sf::RenderWindow& a){
	a.draw(shape);
}
void Paddle::update(sf::Keyboard& key,ball& b){
	if (usercontrolled){
		if (key.isKeyPressed(key.Up)){
			move(1);
		}
		else if (key.isKeyPressed(key.Down)){
			move(0);
		}
	}
	else{
		if (b.pos.y>shape.getPosition().y)
			move(0);
		else{
			move(1);
		}
	}
}
void Paddle::reset(){
	pos.y = 250;
	shape.setPosition(pos);
}