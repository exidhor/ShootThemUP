#include "Deplacement.h"
#include <cmath>

/**
Calcul et retourne le point d'arrivee en fonction de la vitesse
*/
sf::Vector2f Deplacement::getPointArrive(sf::Vector2f depart, sf::Vector2f arrivee, float vitesse,
	float width, float height)
{
	if (arrivee.x < 0 || arrivee.x > width || arrivee.y < 0 || arrivee.y > height)
	{
		EquationDroite equationDroite = calculEquationDroite(depart, arrivee);
		arrivee = equationDroite.trouverIntersectionAvecBord(arrivee, width, height).point;
	}

	//on cherche les composantes de la vitesse
	float xd = arrivee.x - depart.x;
	float yd = arrivee.y - depart.y;
	float hypotenus = sqrt(xd*xd + yd*yd);
	
	//cas ou l'on clique sur le personnage lui-meme
	if (hypotenus == 0)
	{
		return depart;
	}

	float vitesseX = positif(xd) / hypotenus * vitesse;
	float vitesseY = positif(yd) / hypotenus * vitesse;

	//orientation des vitesses
	vitesseX = orienteVitesseAvecDirection(vitesseX, xd);
	vitesseY = orienteVitesseAvecDirection(vitesseY, yd);

	return ajoutDeplacementToPosition(depart, arrivee, sf::Vector2f(vitesseX, vitesseY), vitesse);
}

/**
Ajoute le vecteur Deplacement a la position actuelle 
et verifie que ce vecteur ne depasse pas l'arrivee
*/
sf::Vector2f Deplacement::ajoutDeplacementToPosition(sf::Vector2f depart, sf::Vector2f arrivee,
	sf::Vector2f deplacement, float vitesse)
{
	float differenceArriveeX = arrivee.x - depart.x;
	float differenceArriveeY = arrivee.y - depart.y;

	if (sqrt(differenceArriveeX*differenceArriveeX + differenceArriveeY*differenceArriveeY) <= vitesse)
	{
		return arrivee;
	}
	return sf::Vector2f(depart.x + deplacement.x, depart.y + deplacement.y);
}

/**
 Calcul l'équation d'une droite en fonction de 2 points
*/
EquationDroite Deplacement::calculEquationDroite(sf::Vector2f point1, sf::Vector2f point2)
{
	//calcul des Deltas
	float differenceX = point2.x - point1.x;
	float differenceY = point2.y - point1.y;

	//gestion de la division par 0
	if (differenceX == 0)
	{
		return EquationDroite(0, point1.x, 'x');
	}
	if (differenceY == 0)
	{
		return EquationDroite(0, point1.y);
	}

	float pente = differenceY / differenceX;
	
	//on integre x dans l'equation pour le point1 afin d'obtenir l'ordonnée a l'origine
	float ordonneeOrigine = point1.y - pente * point1.x;

	return EquationDroite(pente, ordonneeOrigine);
}

/**
Cette fonction permet d'orienter (mettre le signe) le vecteur vitesse
en fonction du sens de celui de direction
*/
float Deplacement::orienteVitesseAvecDirection(float vitesse, float direction)
{
	if (direction > 0)
		return vitesse;
	else
		return -vitesse;
}

/**
Renvoie la valeur absolue du nombre passé en paramètre
*/
float Deplacement::positif(float number)
{
	if (number < 0)
		return -number;
	else
		return number;
}