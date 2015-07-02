#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h";
#include <time.h> 

const float speedb = 10.0f;

struct Paddle;
class ball
{
public:
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::CircleShape shape;

	ball(sf::Vector2f,int);
	~ball();
	void reset();
	int update(Paddle&,Paddle&);
	void draw(sf::RenderWindow&);
};