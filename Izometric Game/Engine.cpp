#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include "Engine.h"
#include "Terrain.h"

 Engine::Engine(sf::RenderWindow & window)
{
	window.create(sf::VideoMode(1200, 800), "CUBE");
	window.setFramerateLimit(60);
	run(window);
};

   void Engine::draw(sf::RenderWindow& window) const
{
	   for (int i=0;i<terrain.terrain_map.size();i++)
	      window.draw(terrain.terrain_map[i]);
};

   void Engine::run(sf::RenderWindow & window)
   {

	   while (window.isOpen())
	   {
		   
		   sf::Event event;
		   while (window.pollEvent(event))
		   {
			   if (event.type == sf::Event::Closed)
				   window.close();
			   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
			   {
				   camera.setZoom(false);
			   }
			   else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
			   {
				   camera.setZoom(true);
			   }
			   if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			   {
				   camera.setCameraPos(sf::Mouse::getPosition(window));
			   }
				   


		   }
		   camera.setCamera(window);
		   window.clear(sf::Color::Blue);
		   draw(window);
		   window.display();
	   }

	   
   };

  