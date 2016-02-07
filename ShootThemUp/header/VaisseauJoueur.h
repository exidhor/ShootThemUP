#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Vaisseau.h"
#include "Tir.h"
#include "Bouclier.h"
#include "Teleportation.h"
#include "Ralentissement.h"
#include "Laser.h"

/**
Code le vaisseau que le joueur controllera
*/
class VaisseauJoueur : public Vaisseau
{
private:
	bool m_estRecharge;
	//competences
public:
	VaisseauJoueur(Animation const& texture, Animation* textureTir, Animation* animationBouclier,
		Animation* animationLaser);
	~VaisseauJoueur();

	//tirs
	//competences
};