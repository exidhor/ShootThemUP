#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Entity.h"
#include "Animation.h"
#include "Competence.h"

#define VITESSE_LASER 50

class Vaisseau;
class Game;

class Laser : public Competence
{
private:
	int actualiserTextureRect(float tempsPasse);
	sf::Vector2f getLaserPosition(int size);

protected:
	float m_damagePerTime;
	float m_ralentissementVaisseau;
	Game* m_game;

public:
	Laser(float tempsDeRecharge, Animation* texture,
		float damagePerTime, float ralentissementVaisseau, Vaisseau* vaisseauOrigine);
	~Laser();

	void utiliserCompetence(Game* game);

	virtual void recharge(float tempsPasse);
};