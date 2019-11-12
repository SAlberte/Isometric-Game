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
	loadTerrainTexture();
	setMap();
	
}

void Terrain::loadTerrainTexture()
{
	terrain_tex.loadFromFile("images/terrain.png");
	terrain_spr.setTexture(terrain_tex);
	for (int i = 0; i < 3; i++)
	{

		terrain_spr.setTextureRect(sf::IntRect(3, i * 85 + 3, 153, 81));
		terrain_sprites.push_back(terrain_spr);
	}
}

void Terrain::setMap()
{
	for (int j = 0; j < 21; j++)
	{
		int j_now = (j + 1) % 2;
		for (int i = 0; i < 10; i++)
		{
			
				terrain_sprites[i % 3].setPosition((j_now%2)*(-76.f) + i * 160.f+(j%2)*4.f, (j-1.f)*40.f);
				terrain_map.push_back(terrain_sprites[i % 3]);

			
			
		}

	}
}