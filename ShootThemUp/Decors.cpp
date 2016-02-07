#include "Decors.h"

/**
creer un element de decors
*/
Decors::Decors(float vie, bool estDestructible, Animation const& animation, sf::Vector2f position)
: Entity(animation, vie, estDestructible, position)
{

}

Decors::~Decors()
{

}

/**
deplace le decors du scrolling passé en param
*/
void Decors::deplacementScrolling(float coordX)
{
	m_sprite.setPosition(m_sprite.getGlobalBounds().left,
		m_sprite.getGlobalBounds().top + coordX);
}