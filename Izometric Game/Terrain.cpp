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
	
	tile_X = 256;
	tile_Y = 148;
	scale_factor = 1.f;
	loadTerrainTexture();
	setMap();
	cursor.setPointCount(6);
	sprite_iterator = 0;

	// define the points
	cursor.setPoint(0, sf::Vector2f(0, 89));
	cursor.setPoint(1, sf::Vector2f(0, 69));
	cursor.setPoint(2, sf::Vector2f(128, 0));
	cursor.setPoint(3, sf::Vector2f(256, 69));
	cursor.setPoint(4, sf::Vector2f(256, 89));
	cursor.setPoint(5, sf::Vector2f(128, 148));
	cursor.setFillColor(sf::Color::Transparent);
	cursor.setOutlineColor(sf::Color::Red);
	cursor.setOutlineThickness(5);
	
}

void Terrain::loadTerrainTexture()
{
	terrain_tex.loadFromFile("images/newterrain.png");
	terrain_spr.setTexture(terrain_tex);
	for(int j=0;j<2;j++)
	for (int i = 0; i < 4; i++)
	{

		terrain_spr.setTextureRect(sf::IntRect(256.f*j, i*148, 256, 148));
		terrain_sprites.push_back(terrain_spr);
	}
}

void Terrain::setMap()
{
	float tile_X_now = tile_X * scale_factor;
	float tile_Y_now = tile_Y * scale_factor;

	for (int j = 0; j < 100; j++)
	{
		int j_now = j  % 2;
		for (int i = 0; i < 10; i++)
		{
				terrain_sprites[i % 3].setScale(scale_factor,scale_factor);
				if(j==0)
				terrain_sprites[i % 3].setPosition(j_now*(tile_X_now/2.f)+i*(tile_X_now),j*tile_Y_now/2.f);
				else 
				terrain_sprites[i % 3].setPosition(j_now*(tile_X_now / 2.f) + (i*(tile_X_now)), j*tile_Y_now /2.f-j*10.5f);


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

void Terrain::getSelectedTile(sf::Vector2f worldpos)
{
	
	int x =  worldpos.x/256;
	int y =  worldpos.y/64;
	
	if (x >= 0 && y >= 0 && y < 100 && x < 100)
	{
		SelectedTile = y * 10 + x;
		cursor.setPosition(terrain_map[y * 10 + x].getPosition());

	}
		
		

}

bool Terrain::ChangeTile(bool is_changed)
{
	if (is_changed)
	{
		terrain_map[SelectedTile].setTextureRect(terrain_sprites[sprite_iterator].getTextureRect());		
		if (sprite_iterator > 6)
			sprite_iterator = 0;
		else
			sprite_iterator++;
		return true;
	}
	else return false;

}