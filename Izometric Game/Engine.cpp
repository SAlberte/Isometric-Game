#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include "Engine.h"
#include "Terrain.h"

 Engine::Engine(sf::RenderWindow & window)
{
	window.create(sf::VideoMode(1200, 800), "isometric tileset");
	window.setFramerateLimit(60);
	run(window);
	is_button_pressed = false;
};

   void Engine::draw(sf::RenderWindow& window) const
{
	   for (int i=0;i<terrain.terrain_map.size();i++)
	      window.draw(terrain.terrain_map[i]);
		if (terrain.sprite_iterator > 19)
			{
		   window.draw(terrain.obstacles.cursorSprite);
			}
		else
	   window.draw(terrain.cursorSprite);
	  for (int i = 0; i < terrain.obstacles.Obstacle_Map.size(); i++)
		   window.draw(terrain.obstacles.Obstacle_Map[i]);
	   window.draw(terrain.cursor);
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
			   if (event.type == sf::Event::MouseWheelScrolled)
			   {
				   terrain.changeTileiterator(event.mouseWheelScroll.delta);
			   }

			   if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			   {
				   setCamera(window); 
			   }
			   else
			   {
				   if (is_button_pressed)
				   {
					   terrain.ChangeTile((int)camera.realfirst_pos_x == sf::Mouse::getPosition(window).x);

				   }
				   is_button_pressed = false;
			   }
			   
			   sf::Vector2i mousepos = sf::Mouse::getPosition(window);
			   sf::Vector2i pixelPos = sf::Mouse::getPosition(window);			   
			   sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
			   terrain.getSelectedTile(worldPos);


		   }
		   camera.setCamera(window);
		   window.clear(sf::Color::Blue);
		   draw(window);
		   window.display();
	   }

	   
   };

   void Engine::setCamera(sf::RenderWindow & window)
   {
	   if (!is_button_pressed)
		   camera.setfirst_pos(sf::Mouse::getPosition(window));
	   is_button_pressed = true;
		   camera.setCameraPos(sf::Mouse::getPosition(window));
   }