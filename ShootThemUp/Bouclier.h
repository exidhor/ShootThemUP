#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Entity.h"
#include "Animation.h"
#include "Competence.h"

class Vaisseau;
class Game;

class Bouclier : public Competence
{
private:
	float m_tempsDeBouclierMax;
	float m_tempsDeBouclierCurrent;
	float m_estEnBouclier;
public:
	Bouclier(float tempsDeRecharge, Animation* animation, Vaisseau* vaisseauOrigine);
	~Bouclier();

	virtual void utiliserCompetence(Game* game);
	virtual void recharge(float tempsPasse);
	float getTempsDeRechargeActuel();
	float getTempsDeRechargeMax();
};