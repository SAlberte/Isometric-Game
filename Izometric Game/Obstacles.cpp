#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Obstacles.h"


Obstacles::Obstacles()
{
	loadObstaclesTexture();
	float Obstacle_x = 256;
	float Obstacle_y = 512;

}

void Obstacles::loadObstaclesTexture()
{
	Obstacle_tex.loadFromFile("images/obstacles.png");
	Obstacle_spr.setTexture(Obstacle_tex);
	cursorSprite.setTexture(Obstacle_tex);
	for (int j = 0; j < 1; j++)
		for (int i = 0; i < 5; i++)
		{

			Obstacle_spr.setTextureRect(sf::IntRect(256.f*i, j * 512, 256, 512));
			Obstacle_sprites.push_back(Obstacle_spr);
		}
	
}

void Obstacles::AddObstacle(int iterator,sf::Vector2f Position)
{
	//checkforExistingObstacle(Position);
	Obstacle_sprites[iterator-20].setPosition(sf::Vector2f(Position.x,Position.y-384.f));
	Obstacle_Map.push_back(Obstacle_sprites[iterator-20]);

}

bool Obstacles::checkforExistingObstacle(sf::Vector2f Position)
{
	Position.y -= 384;
	for (int i = 0; i < Obstacle_Map.size(); i++)
	{
		if ((sf::Vector2f)Obstacle_Map[i].getPosition() == (sf::Vector2f)Position)
			Obstacle_Map.erase(Obstacle_Map.begin()+i-1);
			return 1;
	}
	return 0;
}

void Obstacles::setCursorSprite(int iterator,sf::Vector2f(Position))
{
	cursorSprite.setTextureRect(Obstacle_sprites[iterator-20].getTextureRect());
	cursorSprite.setPosition(sf::Vector2f(Position.x,Position.y-384));
}