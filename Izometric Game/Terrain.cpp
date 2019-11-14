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
	cursor.setPointCount(4);
	sprite_iterator = 0;

	// define the points
	cursor.setPoint(0, sf::Vector2f(0, 40));
	cursor.setPoint(1, sf::Vector2f(76, 0));
	cursor.setPoint(2, sf::Vector2f(152, 40));
	cursor.setPoint(3, sf::Vector2f(76, 80));
	cursor.setFillColor(sf::Color::Transparent);
	cursor.setOutlineColor(sf::Color::Red);
	cursor.setOutlineThickness(5);
	
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

	for (int j = 0; j < 10; j++)
	{
		int j_now = j  % 2;
		for (int i = 0; i < 10; i++)
		{
				terrain_sprites[i % 3].setScale(scale_factor,scale_factor);
				if(i==0)
				terrain_sprites[i % 3].setPosition(j_now*(tile_X_now/2.f+4.f)+i*(tile_X_now),j*tile_Y_now/2.f);
				else 
				terrain_sprites[i % 3].setPosition(j_now*(tile_X_now / 2.f+4.f) + (i*(tile_X_now+8.f)), j*tile_Y_now / 2.f);


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

void Terrain::getSelectedTile(sf::Vector2i mouse_pos,sf::Vector2f cameraOffset)
{
	
	int x =  (mouse_pos.x+cameraOffset.x)/152;
	int y =  (mouse_pos.y+cameraOffset.y)/40;
	
	if (x >= 0 && y >= 0 && y < 10 && x < 10)
	{
		SelectedTile = y * 10 + x;
		cursor.setPosition(terrain_map[y * 10 + x].getPosition());

	}
		
		

}

bool Terrain::ChangeTile(bool is_changed)
{
	if (is_changed)
	{
		sf::Vector2f posbuff = terrain_map[SelectedTile].getPosition();
		terrain_map[SelectedTile] = terrain_sprites[sprite_iterator];
		terrain_map[SelectedTile].setPosition(posbuff);
		
		if (sprite_iterator > 1)
			sprite_iterator = 0;
		else
			sprite_iterator++;
		return true;
	}
	else return false;

}