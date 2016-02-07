#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "EquationDroite.h"
#include "MobilEntity.h"
#include "Animation.h"

/**
Code un projectile, donc pas de collision possible
entre projectile et 1 de vie
*/
class Projectile: public MobilEntity
{
private:
	Direction m_direction;
	EquationDroite m_equationDroite;
	float m_damage;

public:
	Projectile(float vitesse, Direction direction, EquationDroite equationDroite, float damage,
		sf::Vector2f position, Animation const& textureTir);
	virtual ~Projectile();

	Direction getDirection() const;
	EquationDroite getEquationDroite() const;
	float getDamage() const;

	void move(float tempsPasse);
};