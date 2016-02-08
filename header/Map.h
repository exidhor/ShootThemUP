#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <string>
#include <stdlib.h> // pour rand
#include <vector>
#include "Decors.h"
#include "Entity.h"
#include "Projectile.h"
#include "Animation.h"

#define NBRE_ELEMENTS_LARGEUR 6
#define NBRE_ELEMENTS_HAUTEUR 10
#define PROBA_ASTEROIDE 7
#define PROBA_SATELLITE 20

// type de i pour les boucle for qui parcourt des vectors
typedef unsigned int intI;

/**
Code les elements du décors que l'on peut trouver dans la
map ( VIDE, MUR)
*/
enum ElementDecors {
	ASTEROIDE = 0, SATELLITE
};


/**
Code la l'ensemble des Decors et sa gestion dans un tab 2D (la Map)
*/
class Map {
private :
	int m_largeurFenetre;
	int m_hauteurFenetre;
	float m_coinBasFenetreMap;
	std::vector <std::vector<Decors*> > m_decors;
	std::vector <Animation*> m_animationsDecors;
	sf::Text m_texteScore;
	sf::Text m_texteTourLoop;
	float m_score;
public:
	Map(int largeurFenetre, int hauteurFenetre, std::vector <Animation*> animationsDecors,
		sf::Font* font);
	~Map();

	void setTextScore(float score);
	void setTexteTourLoop(float loop);

	void genererMap();
	void creerInfoTexte(sf::Font* font);
	void drawMap(sf::RenderWindow* window);
	bool collisionBloc(Entity & entity, std::vector<Projectile*> & tirs, float & score);
	void ajoutLigne(float distanceSupplementaireParcouru = 0);
	void actualiserAnimation(float tempsPasse);

	bool gestionDegats(Decors* & decors, float dmg);


	//pour le scrolling
	void actualisationMapAvecScrolling(float distanceParcouru);

	float findCollisionLaser(Entity* entity, float dmg);
};