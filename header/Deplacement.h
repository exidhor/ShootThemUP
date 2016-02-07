#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "EquationDroite.h"

/**
Regroupe toutes les fonctions utiles au déplacement des Sprites
*/
class Deplacement
{
public:
	static EquationDroite calculEquationDroite(sf::Vector2f point1, sf::Vector2f point2);
	static float orienteVitesseAvecDirection(float vitesse, float direction);
	static float positif(float number);
	static sf::Vector2f getPointArrive(sf::Vector2f depart, sf::Vector2f arrivee,
		float vitesse, float width, float height);
	static sf::Vector2f ajoutDeplacementToPosition(sf::Vector2f depart, sf::Vector2f arrivee,
		sf::Vector2f deplacement, float vitesse);

};