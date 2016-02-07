#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <vector>


/**
represente une image en arriere plan qui scrollera a une vitesse decalée
*/
class Background
{
private:
	sf::Sprite m_spriteBackground;
	float coordY;
public:
	Background(sf::Texture* texture);
	~Background();

	void actualiserScrolling(float tempsPasse);
	void draw(sf::RenderWindow* window);
};