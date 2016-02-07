#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <string>
#include "Field.h"

class Box
{
private:
	sf::RectangleShape m_shapeValider;
	sf::RectangleShape m_shapeContour;
	Field m_textField;
	sf::Text m_textValider;
	bool m_estSelectionne;
	std::string m_retour;

public:
	Box(TypeField type, sf::Font* font, sf::Vector2f tailleTotal, sf::Vector2f position = sf::Vector2f(0, 0));
	~Box();

	void setEstSelectionne(bool state);

	bool estSelectionne();

	sf::RectangleShape* getShapeTotal();
	
	bool traitementEvent(sf::Event & event, sf::RenderWindow* window);

	void draw(sf::RenderWindow* window);
};