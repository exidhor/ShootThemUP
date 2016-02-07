#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "MobilEntity.h"
#include "Competence.h"
#include "Projectile.h"
#include "Animation.h"


/**
Code un vaisseau, lanceur de Projectiles
*/
class Vaisseau : public MobilEntity
{
protected:
	Animation* m_animationTir;
	std::vector <Competence*> m_competences;
	//bool m_estRecharge;
	//float m_tempsDeRecharge;
	//float m_etatTempsDeRecharge;
	sf::Vector2f* m_direction;
public:
	Vaisseau(Animation const& animation, float vitesse, Animation* textureTir, float vie = 200);
	Vaisseau::Vaisseau(Animation const& animation, float vitesse, Animation* tir,
		sf::Vector2f const& position, float vie = 200);
	virtual ~Vaisseau();

	void addCompetence(Competence* competence);
	std::vector <Competence*> getCompetence();
	//bool estRecharge();
	void setDirection(sf::Vector2f* direction);
	void setVitesse(float vitesse);

	Competence* getCompetence(int numero);
	//virtual Projectile* tirer();
	virtual void recharge(float TempsPasse);
};