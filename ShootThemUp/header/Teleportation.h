#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Entity.h"
#include "Animation.h"
#include "Competence.h"


class Game;
class Vaisseau;

class Teleportation : public Competence
{
private:
public:
	Teleportation(float tempsDeRecharge, Animation* animation, Vaisseau* vaisseauOrigine);
	~Teleportation();

	virtual void utiliserCompetence(Game* game);
};