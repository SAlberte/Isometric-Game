#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <algorithm>


class Obstacles 
{
private:
	void loadObstaclesTexture();
	float tile_X;
	float tile_Y;




public:
 	Obstacles();
	sf::Texture Obstacle_tex;
	sf::Sprite Obstacle_spr;
	sf::Sprite cursorSprite;
	std::vector <sf::Sprite> Obstacle_sprites;
	void AddObstacle(int iterator,sf::Vector2f Position);
	std::vector <sf::Sprite> Obstacle_Map;
	bool checkforExistingObstacle(sf::Vector2f Position);
	void setCursorSprite(int iterator,sf::Vector2f Position);
};