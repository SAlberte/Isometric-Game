#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Terrain.h"

Terrain::Terrain()
{
	terrain_tex.loadFromFile("images/terrain.png");
	terrain_spr.setTexture(terrain_tex);
	for (int i = 0; i < 3; i++)
	{
		
		terrain_spr.setTextureRect(sf::IntRect(3, i * 84 + 3, 152, 82));
		terrain_spr.setPosition(sf::Vector2f(i*74.5f, i*39.5f));
		terrain_sprites.push_back(terrain_spr);
		

	}
	
}
