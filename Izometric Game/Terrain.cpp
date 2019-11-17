#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Terrain.h"
#include "Obstacles.h"

Terrain::Terrain()
{
	
	tile_X = 256;
	tile_Y = 148;
	scale_factor = 1.f;
	loadTerrainTexture();
	setMap();
	
	cursor.setPointCount(6);
	// define the points
	cursor.setPoint(0, sf::Vector2f(0, 84));
	cursor.setPoint(1, sf::Vector2f(0, 64));
	cursor.setPoint(2, sf::Vector2f(128, 0));
	cursor.setPoint(3, sf::Vector2f(256, 64));
	cursor.setPoint(4, sf::Vector2f(256, 84));
	cursor.setPoint(5, sf::Vector2f(128, 148));
	cursor.setFillColor(sf::Color::Transparent);
	cursor.setOutlineColor(sf::Color::Red);
	cursor.setOutlineThickness(5);
	sprite_iterator = 0;
	
}

void Terrain::loadTerrainTexture()
{
	terrain_tex.loadFromFile("images/newterrain.png");
	terrain_spr.setTexture(terrain_tex);
	cursorSprite.setTexture(terrain_tex);
	for(int j=0;j<5;j++)
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
				terrain_sprites[3].setScale(scale_factor,scale_factor);
				if(j==0)
				terrain_sprites[3].setPosition(j_now*(tile_X_now/2.f)+i*(tile_X_now),j*tile_Y_now/2.f);
				else 
				terrain_sprites[3].setPosition(j_now*(tile_X_now / 2.f) + (i*(tile_X_now)), j*tile_Y_now /2.f-j*10.5f);


				terrain_map.push_back(terrain_sprites[3]);

			
			
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
	
	if (x >= 0 && y >= 0 && y < 100 && x < 99)
	{
		SelectedTile = y * 10 + x;
		cursor.setPosition(terrain_map[y * 10 + x].getPosition());
		
		if (sprite_iterator < 20)
		{
			cursorSprite.setTextureRect(terrain_sprites[sprite_iterator].getTextureRect());
			cursorSprite.setPosition(cursor.getPosition());
		}
			
		
		if(sprite_iterator>19)
			obstacles.setCursorSprite(sprite_iterator, terrain_map[SelectedTile].getPosition());
		
		

	}
		
		

}

bool Terrain::ChangeTile(bool is_changed)
{
	if (is_changed)
	{
		if (sprite_iterator < 20)
			terrain_map[SelectedTile].setTextureRect(terrain_sprites[sprite_iterator].getTextureRect());
		else
			obstacles.AddObstacle(sprite_iterator,terrain_map[SelectedTile].getPosition());
		return true;
	}
	else return false;

}

void Terrain::changeTileiterator(int isnext)
{
	if (isnext > 0)
	{
		if (sprite_iterator > 23)
			sprite_iterator = 0;
		else sprite_iterator++;
	}
	else
	{
		if (sprite_iterator < 1)
			sprite_iterator = 24;
		else sprite_iterator--;
	}
}