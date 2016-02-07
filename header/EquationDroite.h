#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>

/**
Code la direction (VERS_LE_BAS, VERS_LE_HAUT, VERS_LA_GAUCHE,
VERS_LA_DROITE)
*/
enum Direction {
	VERS_LE_BAS = 0, VERS_LE_HAUT, VERS_LA_GAUCHE, VERS_LA_DROITE
};

enum Axe { ABSCISSE, ORDONNEE};

/**
token qui permet d'ajouter un bool valide sur un point (sf::Vector2f)
*/
class TokenPoint
{
public:
	bool estValide;
	sf::Vector2f point;

	TokenPoint(sf::Vector2f vector2f, bool valide=true)
	{
		estValide = valide;
		point = vector2f;
	}
};

/**
	Code une droite par son equation
	type = simbole qui sera a gauche du egal (x ou y)
*/
class EquationDroite
{
private:
	//cet attribut va determiné "le symbole" à gauche du égal
	char m_type;
	float m_pente;
	float m_ordonneeOrigine;
public:
	EquationDroite(float pente, float ordonneeOrigine, char type = 'y');
	virtual ~EquationDroite();

	char getType();
	float getPente();
	float getOrdonneeOrigine();

	TokenPoint trouverPoint(float abscisseOuOrdonnee, Axe axe);
	TokenPoint trouverIntersectionAvecBord(sf::Vector2f const& direction, float width, float height);

	static bool estDansLeCadreDeLaFenetre(float width, float height, sf::Vector2f const& point);
};