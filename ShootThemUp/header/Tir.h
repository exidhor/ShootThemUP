#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Animation.h"
#include "Competence.h"
#include "Projectile.h"

/**
Action qui cree un projectile, qui sera ajouté a la partie
*/
class Tir : public Competence
{
protected:
	float m_damage;
	float m_vitesse;

public:
	Tir(float tempsDeRecharge, Animation* texture,
		float damage, float vitesse, Vaisseau* vaisseauOrigine);
	~Tir();
	
	void utiliserCompetence(Game* game);
	virtual Projectile* tirer();
};