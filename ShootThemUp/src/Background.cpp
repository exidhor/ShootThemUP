#include "Background.h"

/**
creer un background plus grand que la fenetre qui scrollera
*/
Background::Background(sf::Texture* texture)
: m_spriteBackground(*texture)
{
	coordY = 600;
	m_spriteBackground.setTextureRect(sf::IntRect(0, coordY, 1200, 725));
	m_spriteBackground.setPosition(0, 0);
}

Background::~Background()
{

}

/**
deplace le decors en fonction du temps passé (coord stocké dans coordY) et cadre l'image de maniere a 
afficher que le necessaire
*/
void Background::actualiserScrolling(float tempsPasse)
{
	float vitesse = tempsPasse / 2;

	coordY -= vitesse;

	m_spriteBackground.setTextureRect(sf::IntRect(0, coordY, 1200, 725));
}

void Background::draw(sf::RenderWindow* window)
{
	window->draw(m_spriteBackground);
}