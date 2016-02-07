#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Animation.h"
#include "Entity.h"

//utile pour la forward declaration
class Game;
class Vaisseau;

/**
Correspond a une action qu'un vaisseau peut faire, gere son cooldown
et son execution
*/
class Competence
{
protected:
	float m_tempsDeRecharge;
	float m_etatDeRecharge;
	bool m_estRecharge;
	bool m_estActive;
	Animation* m_animation;
	Vaisseau* m_vaisseauOrigine;

public:
	Competence(float tempsDeRecharge, Animation* animation, Vaisseau* vaisseauOrigine);
	virtual ~Competence();

	bool estRecharge();
	bool estActive();
	Animation* getAnimation();

	virtual float getTempsDeRechargeActuel();
	virtual float getTempsDeRechargeMax();

	virtual void utiliserCompetence(Game* game);
	virtual void recharge(float tempsPasse);
};