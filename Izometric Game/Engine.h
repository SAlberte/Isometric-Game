#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include "Camera.h"
#include "Terrain.h"



class Engine 
{
public:
	 Engine(sf::RenderWindow & window);
	 Terrain terrain;
	 Camera camera;
	
	void run(sf::RenderWindow & window);
private:
	 void draw(sf::RenderWindow & window) const;
	 void setCamera(sf::RenderWindow & window);
	 bool is_button_pressed;
};