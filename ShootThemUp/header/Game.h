#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include "Entity.h"
#include "Map.h"
#include "Deplacement.h"
#include "TextureManager.h"
#include "Vaisseau.h"
#include "VaisseauJoueur.h"
#include "Projectile.h"
#include "AnimationManager.h"
#include "Background.h"
#include "Competence.h"
#include "Tir.h"
#include "TableauDeBord.h"

// type de i pour les boucle for qui parcourt des vectors
typedef unsigned int intI;

//inversement proportionel (divisé par)
#define ACCELERATION_SCROLLING 500
#define RALENTISSEMENT_BACKGROUND 3


enum TypeEffect { LASER = 0 };


/**
Represente une partie
*/
class Game
{
private :
	Map m_map;
	sf::RenderWindow* m_window;
	std::vector <Vaisseau*> m_vaisseaux;
	VaisseauJoueur m_vaisseauJoueur;
	std::vector <Projectile*> m_tirs;
	float m_tourLoop;
	TextureManager* m_textureManager;
	AnimationManager* m_animationManager;

	std::vector <Entity*> m_effects;

	Background m_background;
	sf::Sprite m_interface;
	float m_distanceParcouru;
	float m_vitesseScrolling;
	float m_stockageScrolling;
	float m_coefRalentissement;
	float m_tempsPasse;
	Entity* m_effectLaser;

	TableauDeBord tableauDeBord;

public :
	Game(sf::RenderWindow* window, TextureManager & textureManager, AnimationManager & animationManager);
	~Game();

	sf::RenderWindow* getWindow();

	//utiliser par les competences
	void addProjectile(Projectile* projectile);

	bool gameLoop(sf::Clock & clock);
	void recuperationEntree(sf::Event & event);
	void affichage();
	void traitement(sf::Event & event, float tempsPasse);
	void gererTirs(float tempsPasse);
	bool estDansLaFenetre(sf::RenderWindow* window, sf::FloatRect bounds, sf::Vector2f position);
	void actualisationInfoJoueur();
	void rechargeDesVaisseaux(float tempsPasse);
	void actionDependanteDuTemps(float tempsPasse);
	void actualiserAnimation(float tempsPasse);
	void setVitesseJeu(float coefDiminution);

	sf::Vector2f getPositionMouse();
	float getTempsPasse();

	void addEffect(Entity* entity, TypeEffect effect);
	Entity* getEffect(TypeEffect typeEffect);
	void deleteEffect(TypeEffect typeEffect);

	float findCollisionLaser(Entity* entity, float dmg);

	//Pour le scrolling
	void gestionScrolling(float tempsPasse);
	float calculDistanceParcouru(float tempsPasse);
};