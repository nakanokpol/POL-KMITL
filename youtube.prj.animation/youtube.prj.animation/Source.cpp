#include <SFML/Graphics.hpp>
#include <iostream>
//#include "Animation.h"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "animation-prj", sf::Style::Close | sf:: Style::Resize);
	//sf::RectangleShape player(sf::Vector2f(100.f, 150.f));

	//player.setPosition(206.f, 206.f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("CHAR/TEST105.png");
	//player.setTexture(&playerTexture);


	//Animation animation(&playerTexture, sf::Vector2u(3,9), 0.2f);//
	Player player(&playerTexture, sf::Vector2u(3, 9), 0.2f, 100.f);//

	float dt = 0.f;//
	sf::Clock clock;//

	/*sf::Vector2u textureSize = playerTexture.getSize();
	textureSize.x /= 9;
	textureSize.y /= 4;*/

	//player.setTextureRect(sf::IntRect(textureSize.x * 3, textureSize.y * 1, textureSize.x, textureSize.y));

	while (window.isOpen())
	{
		dt = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
				
		}

		//animation.update(0, dt, false);//

		//player.setTextureRect(animation.uvRect);//

		player.update(dt);



		window.clear(sf::Color(200,200,200));
		//window.draw(player);
		player.Draw(window);
		window.display();
	}
	return 0;
}