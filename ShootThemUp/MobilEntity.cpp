#include "MobilEntity.h"

MobilEntity::MobilEntity(Animation const& animation, float vie, bool estDestructible, float vitesse)
: Entity(animation, vie, estDestructible), m_vitesse(vitesse)
{

}

MobilEntity::MobilEntity(Animation const& animation, float vie, bool estDestructible, float vitesse,
	sf::Vector2f position)
	: Entity(animation, vie, estDestructible, position), m_vitesse(vitesse)
{

}

MobilEntity::~MobilEntity()
{

}

float MobilEntity::getVitesse()
{
	return m_vitesse;
}

void MobilEntity::move(sf::Vector2f deplacement)
{
	setPosition(sf::Vector2f(getPosition()->x + deplacement.x, getPosition()->y + deplacement.y));
}