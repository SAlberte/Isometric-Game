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
	int SelectedTile;
	std::vector <sf::Sprite> Obstacle_sprites;
	void setObstacleMap();
	std::vector <sf::Sprite> Obstacle_Map;
	void setFactor(bool isMore);
	void getSelectedObstacle(sf::Vector2f worldpos);
	sf::ConvexShape cursor;
	bool ChangeObstacle(bool is_changed);
	sf::Vector2i prev_mousePos;
	int sprite_iterator;
	void changeObstacleiterator(int isnext);
};