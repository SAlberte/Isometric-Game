#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <algorithm>

class Terrain
{
private:
	void loadTerrainTexture();
	float scale_factor;
	float tile_X;
	float tile_Y;
	


	
public:
	Terrain();
	//void getTile();
	sf::Texture terrain_tex;
	sf::Sprite terrain_spr;
	int SelectedTile;
	std::vector <sf::Sprite> terrain_sprites;
	void setMap();
	std::vector <sf::Sprite> terrain_map;
	void setFactor(bool isMore);
	void getSelectedTile(sf::Vector2i mousePos,sf::Vector2f cameraOffset);
	sf::ConvexShape cursor;
	bool ChangeTile(bool is_changed);
	sf::Vector2i prev_mousePos;
	int sprite_iterator;
};
