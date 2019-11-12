#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <iostream>


class Camera  
{
public:
	 Camera();
	 float pos_x;
	 float pos_y;
	 float camera_width;
	 float camera_height;
	 float zoom;
	 sf::View view;
	 void setCamera(sf::RenderWindow & window);
	 void setZoom(bool isZoom);
	 void setCameraPos(sf::Vector2i xy);
};

