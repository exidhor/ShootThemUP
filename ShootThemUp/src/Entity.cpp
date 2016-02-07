#include "Entity.h"

/**
Cree un objet avec sa texture
*/
Entity::Entity(Animation const& animation, float vie, bool estDestructible)
: m_sprite(), m_animation(animation), m_vie(vie), m_estDestructible(estDestructible)
{
	m_sprite.setTexture(*m_animation.getTexture());
	m_sprite.setPosition(100, 100);
}

/**
Cree un objet avec sa texture
*/
Entity::Entity(Animation const& animation, float vie, bool estDestructible, sf::Vector2f position)
: Entity(animation, vie, estDestructible)
{
	m_sprite.setPosition(position.x - (m_sprite.getGlobalBounds().width/2),
		position.y - (m_sprite.getGlobalBounds().height/2));
}

Entity::~Entity()
{
	//useless
}

sf::Sprite* Entity::getSprite()
{
	return &m_sprite;
}

/**
Place le centre de l'objet sur la position passée en parametre
*/
void Entity::setPosition(sf::Vector2f newPositionCentre)
{
	m_sprite.setPosition(sf::Vector2f(newPositionCentre.x - (m_sprite.getGlobalBounds().width / 2), 
										newPositionCentre.y - (m_sprite.getGlobalBounds().height / 2)));
}

void Entity::setPosition(float x, float y)
{
	m_sprite.setPosition(sf::Vector2f(x, y));
}

sf::Vector2i* Entity::getPosition() const
{
	return new sf::Vector2i((int)m_sprite.getPosition().x, (int)m_sprite.getPosition().y);
}

sf::Vector2f Entity::getPositionCentre() const
{
	return sf::Vector2f(m_sprite.getPosition().x + (m_sprite.getGlobalBounds().width / 2),
						m_sprite.getPosition().y + (m_sprite.getGlobalBounds().height / 2));
}

Animation* Entity::getAnimation()
{
	return &m_animation;
}

/**
dessine l'objet sur la fenetre, en prenant en compte l'animation
*/
void Entity::draw(sf::RenderWindow* window)
{
	m_sprite.setTexture(*m_animation.getTexture());
	window->draw(m_sprite);
}

float Entity::getVie()
{
	return m_vie;
}

/**
subit les degats recu en parametres
*/
void Entity::prendreDegats(float degats)
{
	if (m_estDestructible)
	{
		m_vie -= degats;
		if (m_vie < 0)
		{
			m_vie = 0;
		}
	}
}

bool Entity::estDestructible()
{
	return m_estDestructible;
}

bool Entity::estEnVie()
{
	return m_vie > 0;
}

void Entity::setDestructible(bool state)
{
	m_estDestructible = state;
}