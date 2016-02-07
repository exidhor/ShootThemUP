#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Animation.h"
#include "Competence.h"


class Vaisseau;
class Game;

class Ralentissement : public Competence
{
private:
	float m_puissanceRalentissement;
	Game* m_game;
public:
	Ralentissement(float tempsDeRecharge, Animation* animation, Vaisseau* vaisseauOrigine,
		float puissanceRalentissement = 4);
	~Ralentissement();

	virtual void utiliserCompetence(Game* game);
	virtual void recharge(float tempsPasse);
};