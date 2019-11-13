#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include "Camera.h"

Camera::Camera() 
{
	pos_x = 1200.f;
	pos_y = 800.f;
	camera_width = 600.f;
	camera_height = 400.f;
	zoom = 1.f;

	view.setCenter(sf::Vector2f(pos_x,pos_y));
	view.setSize(sf::Vector2f(camera_width,camera_height));

}

void Camera::setCamera(sf::RenderWindow & window)
{
	//change position and size
	view.setCenter(sf::Vector2f(pos_x, pos_y));
	view.setSize(sf::Vector2f(camera_width, camera_height));
	view.zoom(zoom);
	window.setView(view);
}

void Camera::setZoom(bool isZoom)
{
	if (isZoom)
		zoom += 0.05f;
	else zoom -= 0.05f;
}

void Camera::setCameraPos(sf::Vector2i xy)
{

	pos_x -= ((float)xy.x-(float)first_pos.x)/50.f;
	pos_y -= ((float)xy.y-(float)first_pos.y)/50.f;
}

void Camera::setfirst_pos(sf::Vector2i clickpos)
{
	first_pos = clickpos;
}