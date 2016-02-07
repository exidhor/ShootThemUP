#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include <stdlib.h>
#include "Animation.h"

#define TAILLE_TABLEAU_LED_LARGEUR 7
#define TAILLE_TABLEAU_LED_HAUTEUR 7
#define TAILLE_ENUM_COULEURLED 7

enum CouleurLed
{
	BLANCHE = 0, BLEU, BLEU_FONCE, ROUGE, VERTE, JAUNE, ROSE 
};

class TableauDeBord
{
private:
	sf::Texture* m_animationAiguille;
	std::vector <sf::Texture*> m_animationTableauLed;
	sf::Texture* m_animationBarreDeProgression;
	sf::Texture* m_animationIndicateurFull;
	std::vector <sf::Texture*> m_animationIndicateurComp3;

	sf::Vector2f m_positionInterface;

	sf::Sprite m_aiguille;
	sf::Sprite m_led;
	sf::Sprite m_barreDeProgression;
	sf::Sprite m_indicateurFull;
	sf::Sprite m_indicateurComp3;

	int m_nbreLedAllumees;
	float m_xBarreDeProgression;

	bool indicateurFullActive;
	std::vector <std::vector <CouleurLed> > m_tableauLed;

public:
	TableauDeBord(sf::Texture* animationAiguille, std::vector <sf::Texture*> animationTableauLed,
		sf::Texture* animationBarreDeProgression, sf::Texture* animationIndicateurFull, std::vector <sf::Texture*> textureIndicateurComp3,
		sf::Vector2f position = sf::Vector2f(0, 0));
	~TableauDeBord();

	void actualiserAnimationAvecTemps(float tempsPasse);
	void actualiserAnimationAvecCompetence(float tempsDeRechargeComp1, float rapportTempsComp2, float rapportTempsComp3, bool comp3estActive);
	void draw(sf::RenderWindow* window);

	void chargerTableauLed();
	CouleurLed getCouleurLed();

	void setInterfacePosition(sf::Vector2f position);

	sf::Texture* getTextureLed(CouleurLed couleurLed);
};