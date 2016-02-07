#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Animation.h"

/**
Représente un objet immobile, qui aura une collision  
*/
class Entity
{
protected:
	sf::Sprite m_sprite;
	float m_vie;
	Animation m_animation;
	bool m_estDestructible; 

public :
	Entity(Animation const& animation, float vie, bool estDestructible);
	Entity(Animation const& animation, float vie, bool estDestructible, sf::Vector2f position);
	virtual ~Entity();

	sf::Sprite* getSprite();
	sf::Vector2i* getPosition() const;
	sf::Vector2f getPositionCentre() const;
	float getVie();
	Animation* getAnimation();
	bool estEnVie();
	bool estDestructible();
	void setDestructible(bool state);
	void setPosition(float x, float y);

	void setPosition(sf::Vector2f newPosition);
	void prendreDegats(float degats);
	void draw(sf::RenderWindow* window);
};