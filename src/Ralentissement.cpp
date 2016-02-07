#include "Ralentissement.h"
#include "Vaisseau.h"
#include "Game.h"


Ralentissement::Ralentissement(float tempsDeRecharge, Animation* animation, Vaisseau* vaisseauOrigine,
	float puissanceRalentissement)
	: Competence(tempsDeRecharge, animation, vaisseauOrigine)
{
	m_puissanceRalentissement = puissanceRalentissement;
	m_game = NULL;
}

Ralentissement::~Ralentissement()
{

}

void Ralentissement::utiliserCompetence(Game* game)
{
	m_game = game;
	if (!m_estActive)
	{
		m_estActive = true;
		game->setVitesseJeu(m_puissanceRalentissement);
	}
}

void Ralentissement::recharge(float tempsPasse)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_estActive = false;
		if (m_game != NULL)
		{
			m_game->setVitesseJeu(1);
		}
	}
	
	// utilisation donc consomation
	if (m_estActive)
	{
		//std::cout << "conso" << std::endl;
		m_etatDeRecharge -= tempsPasse * 2;
		if (m_etatDeRecharge <= 0)
		{
			//std::cout << "rupture" << std::endl;
			m_estActive = false;
			m_estRecharge = false;
		}
	}

	//recharge
	else if (m_etatDeRecharge < m_tempsDeRecharge)
	{
		m_estRecharge = true;
		//std::cout << "recharge" << std::endl;
		m_etatDeRecharge += tempsPasse;
		if (m_etatDeRecharge > m_tempsDeRecharge)
		{
			//std::cout << "Max" << std::endl;
			m_etatDeRecharge = m_tempsDeRecharge;
		}
	}
}