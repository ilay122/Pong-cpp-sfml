#include "ball.h"


ball::ball(sf::Vector2f position,int radius)
{
	sf::CircleShape igul(radius);
	igul.setPosition(position);

	shape = igul;
	pos = position;
	vel = sf::Vector2f(-speedb, speedb);
}


ball::~ball()
{
	
}

int ball::update(Paddle& p1,Paddle& p2){
	int bla = 0;
	pos.x += vel.x;
	pos.y += vel.y;

	if (shape.getGlobalBounds().intersects(p1.shape.getGlobalBounds())){
		pos.x = p1.pos.x + shape.getRadius() * 2 + 1;
		vel.x *= -1;
	}
	else if (shape.getGlobalBounds().intersects(p2.shape.getGlobalBounds())){
		pos.x = p2.pos.x - shape.getRadius()*2 -1;
		vel.x *= -1;
	}


	if (pos.y <= 0){
		pos.y = 0;
		vel.y *= -1;
	}
	if (pos.y + shape.getRadius() * 2 >= 600){
		pos.y = 600 - shape.getRadius() * 2;
		vel.y *= -1;
	}
	if (pos.x <= 0){
		pos.x = 0;
		vel.x *= -1;
		bla = 2;
	}
	if (pos.x + shape.getRadius() * 2 >= 800){
		pos.x = 800 - shape.getRadius() * 2;
		vel.x *= -1;
		bla = 1;

	}
	shape.setPosition(pos);
	return bla;
}

void ball::draw(sf::RenderWindow& w){
	w.draw(shape);
}
void ball::reset(){
	srand(time(NULL));
	int x = rand() % 100;
	
	int y = rand() % 100;

	vel.x = x >= 50 ? speedb : -speedb;
	vel.y = y >= 50 ? speedb : -speedb;

	

	pos.x = 400;
	pos.y = 300;
	shape.setPosition(pos);
}