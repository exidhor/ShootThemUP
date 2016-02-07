#include "Projectile.h"

/**
Creer un Tir
*/
Projectile::Projectile(float vitesse, Direction direction, EquationDroite equationDroite, float damage,
	sf::Vector2f position, Animation const& animationTir)
: MobilEntity(animationTir, 1, false, vitesse, position), m_direction(direction), m_equationDroite(equationDroite), m_damage(damage)
{
	int width = 9;
	int height = 6;
}

Projectile::~Projectile()
{
	
}

Direction Projectile::getDirection() const
{
	return m_direction;
}

EquationDroite Projectile::getEquationDroite() const
{
	return m_equationDroite;
}

float Projectile::getDamage() const
{
	return m_damage;
}

void Projectile::move(float tempsPasse)
{
	float realVitesse = m_vitesse * tempsPasse;
	switch (m_direction)
	{
	case Direction::VERS_LA_GAUCHE :
		m_sprite.move(-realVitesse, 0);
		break;

	case Direction::VERS_LA_DROITE:
		m_sprite.move(realVitesse, 0);
		break;

	case Direction::VERS_LE_HAUT:
		m_sprite.move(0, -realVitesse);
		break;

	case Direction::VERS_LE_BAS:
		m_sprite.move(0, realVitesse);
		break;
	}
}