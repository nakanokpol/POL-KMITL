#pragma once
#include<SFML\Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	//void update(int row, float dt); // dt = time between previous frame and the current frame
	void update(int row, float dt, bool faceright);


	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount; // unsigned int;
	sf::Vector2u currentImage;

	float totalTime; // total time does the animation take
	float switchTime; // time before change the frame
};

