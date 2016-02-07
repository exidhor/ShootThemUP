#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Animation.h"
#include "Entity.h"

/**
Element du decors immobile qui sera affecté par le scrolling
*/
class Decors : public Entity
{
protected:

public:
	Decors(float m_vie, bool estDestructible, Animation const& animation, sf::Vector2f position);
	~Decors();

	void deplacementScrolling(float coordX);
};