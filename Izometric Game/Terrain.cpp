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
	
	tile_X = 152;
	tile_Y = 80;
	scale_factor = 1.f;
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
	float tile_X_now = tile_X * scale_factor;
	float tile_Y_now = tile_Y * scale_factor;

	for (int j = 0; j < 100; j++)
	{
		int j_now = (j + 1) % 2;
		for (int i = 0; i < 10; i++)
		{
				terrain_sprites[i % 3].setScale(scale_factor,scale_factor);
				terrain_sprites[i % 3].setPosition((j_now%2)*(-tile_X_now/2.f) + (i * 160.f+(j%2)*4.f)*scale_factor, (j-1.f)*tile_Y_now/2.f);
				terrain_map.push_back(terrain_sprites[i % 3]);

			
			
		}

	}
}

void Terrain::setFactor(bool isMore)
{
	
	if (isMore)
		scale_factor += 0.2f;
	else 
		scale_factor -= 0.2f;
	setMap();
}