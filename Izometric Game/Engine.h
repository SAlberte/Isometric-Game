#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include "Terrain.h"

class Engine 
{
public:
	 Engine(sf::RenderWindow & window);
	 Terrain terrain;
	
	void run(sf::RenderWindow & window);
private:
	 void draw(sf::RenderWindow & window) const;

};