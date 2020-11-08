#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed)
	:animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceright = true;

	body.setSize(sf::Vector2f(100.f, 150.f));
	body.setPosition(206.f, 206.f);
	body.setTexture(texture);
}

Player::~Player()
{

}

void Player::update(float dt)
{
	sf::Vector2f movement(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= speed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += speed * dt;
	}

	if (movement.x == 0.f) // idle
	{
		row = 0;
	}
	else
	{
		row = 1;

		if (movement.x > 0.f)
			faceright = true;
		else
			faceright = false;
	}

	animation.update(row, dt, faceright);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
