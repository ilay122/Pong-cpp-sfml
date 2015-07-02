#pragma once
#include <SFML/Graphics.hpp>
#include "ball.h"

const float speed = 8.0f;
struct ball;
class Paddle
{
public:
	sf::Vector2f pos;
	sf::RectangleShape shape;
	bool usercontrolled;

	void move(int);
	void draw(sf::RenderWindow&);
	void update(sf::Keyboard&,ball&);
	void reset();
	Paddle(int ,int,sf::Color,sf::Vector2f,bool);
	~Paddle();
private:
	
protected:

};

