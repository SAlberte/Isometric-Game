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
	
	
public:
	Terrain();
	//void getTile();
	sf::Texture terrain_tex;
	sf::Sprite terrain_spr;
	std::vector <sf::Sprite> terrain_sprites;
	
};
