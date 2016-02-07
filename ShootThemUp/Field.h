#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <windows.system.h>
#include <string>

enum TypeField
{
	NUMERIC, TEXT
};

class Field
{
private:
	sf::RectangleShape m_shapeField;

	sf::Text m_text;
	TypeField m_type;
public:
	Field(TypeField type, sf::Vector2f position, sf::Font* font, sf::Vector2f boundsContour);
	~Field();

	sf::RectangleShape* getRectangleShape();
	sf::Text* getText();

	void entreeClavier(char caractere);
	bool estUneEntreeValide(char caractere);
};