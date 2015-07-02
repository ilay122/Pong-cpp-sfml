#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"

int main()
{
	int score1 = 0;
	int score2 = 0;
	bool pause = false;

	sf::Font snow;
	snow.loadFromFile("C:/Users/user/Documents/Snowstorm.ttf");
	sf::Text paused;
	sf::Color red(255,0,0,255);
	paused.setFont(snow);
	paused.setString("PAUSED");
	paused.setPosition(sf::Vector2f(400-paused.getGlobalBounds().width/2,300));
	paused.setColor(red);
	
	

	sf::Text notp;
	notp.setFont(snow);
	notp.setPosition(sf::Vector2f(380, 0));
	notp.setColor(sf::Color::White);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
	window.setFramerateLimit(60);
	Paddle firstp(20,100,sf::Color::White,sf::Vector2f(20,250),true);
	Paddle secondp(20,100, sf::Color::White, sf::Vector2f(800-20*2, 250),false);
	ball gameBall(sf::Vector2f(400,300),10);
	gameBall.shape.setPosition(sf::Vector2f(gameBall.shape.getPosition().y - gameBall.shape.getRadius() * 2, 300));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			
        }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
			pause = !pause;
		}
		if (!pause){
			
			firstp.update(sf::Keyboard(), gameBall);
			int x = gameBall.update(firstp, secondp);
			secondp.update(sf::Keyboard(), gameBall);
			if (x != 0){
				firstp.reset();
				secondp.reset();
				gameBall.reset();

				if (x == 1){
					score1++;
				}
				else if (x == 2){
					score2++;
				}
			}
		}
		
		notp.setString(std::to_string(score1) + ":" + std::to_string(score2));
		

        window.clear();
		if (pause)
			window.draw(paused);

		firstp.draw(window);
		gameBall.draw(window);
		secondp.draw(window);
		window.draw(notp);
        window.display();
    }

    return 0;
}