#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

/**
charge les textures dans des tableaux et les garde en mémoire
*/
class TextureManager
{
private:
	std::vector <sf::Texture*> m_texturesVaisseauJoueur;
	std::vector <sf::Texture*> m_texturesSatellite;
	std::vector <sf::Texture*> m_texturesAsteroide;
	std::vector <sf::Texture*> m_texturesBouclier;
	std::vector <sf::Texture*> m_laser;

	//pour l'interface
	sf::Texture* m_interface;
	sf::Texture* m_aiguille;
	sf::Texture* m_indicateur;
	sf::Texture* m_barreDeProgression;
	std::vector <sf::Texture*> m_leds;
	std::vector <sf::Texture*> m_stateIndicateur;

	sf::Texture* m_background;
	sf::Texture* m_tir;
	sf::Font* m_fontArial;
public:
	TextureManager();
	~TextureManager();

	std::vector <sf::Texture*> getTextureVaisseauJoueur(); 
	std::vector <sf::Texture*> getTextureAsteroide();
	std::vector <sf::Texture*> getTextureSatellite();
	std::vector <sf::Texture*> getTextureBouclier();
	std::vector <sf::Texture*> getTextureLaser();
	std::vector <sf::Texture*> getTextureLed();
	std::vector <sf::Texture*> getTextureStateIndicateur();

	sf::Texture* getTextureInterface();
	sf::Texture* getTextureBackground();
	sf::Texture* getTextureTir();
	sf::Font* getFontArial();
	sf::Texture* getTextureAiguille();
	sf::Texture* getTextureIndicateur();
	sf::Texture* getTextureBarreDeProgression();

	std::vector <sf::Texture*> chargerTexturesVaisseauJoueur();
	std::vector <sf::Texture*> chargerTexturesAsteroide();
	std::vector <sf::Texture*> chargerTexturesSatellite();
	std::vector <sf::Texture*> chargerTexturesBouclier();
	std::vector <sf::Texture*> chargerTexturesLed();
	std::vector <sf::Texture*> chargerTexturesStateIndicateur();
};