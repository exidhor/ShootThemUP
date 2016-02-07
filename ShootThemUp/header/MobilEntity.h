#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Entity.h"
#include "Animation.h"

/**
Represente un objet mobile
*/
class MobilEntity : public Entity
{
protected:
	float m_vitesse;

public:
	MobilEntity(Animation const& animation, float vie, bool estDestructible, float vitesse);	
	MobilEntity(Animation const& animation, float vie, bool estDestructible, float vitesse,
		sf::Vector2f position);
	~MobilEntity();

	float getVitesse();

	void move(sf::Vector2f deplacement);
};