#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <vector>


/**
Represente la suite d'image qui formera l'animation
Elle n'est pas partagée, et gere l'aternance des images
*/
class Animation
{
private:
	std::vector <sf::Texture*> m_textures;
	float m_tempsIntervalleRafraichissement;
	float m_tempsAttenteCurrent;
	int m_indiceCurrentTexture;
public:
	Animation(std::vector <sf::Texture*> textures, float tempsIntervalleRafraichissement);
	Animation(Animation const& animation);
	~Animation();

	float getTempsIntervalleRafraichissement();
	sf::Texture* getTexture();
	
	void actualiser(float tempsPasse);
	void addTexture(sf::Texture* texture);
};