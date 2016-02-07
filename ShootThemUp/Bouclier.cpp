#include "Bouclier.h"
#include "Vaisseau.h"
#include "Game.h"


Bouclier::Bouclier(float tempsDeRecharge, Animation* animation, Vaisseau* vaisseauOrigine)
: Competence(tempsDeRecharge, animation, vaisseauOrigine)
{
	m_estEnBouclier = false;
	m_tempsDeBouclierMax = 100;
	m_tempsDeBouclierCurrent = 100;
}


Bouclier::~Bouclier()
{

}

void Bouclier::utiliserCompetence(Game* game)
{
	std::cout << "Bouclier Up !" << std::endl;
	m_estRecharge = false;
	m_estEnBouclier = true;
	m_estActive = true;
	m_vaisseauOrigine->setDestructible(false);
}

void Bouclier::recharge(float tempsPasse)
{
	if (m_estEnBouclier)
	{
		m_tempsDeBouclierCurrent -= tempsPasse;

		if (m_tempsDeBouclierCurrent <= 0)
		{
			std::cout << "Bouclier down" << std::endl;
			m_estEnBouclier = false;
			m_estActive = false;
			m_vaisseauOrigine->setDestructible(true);
			m_tempsDeBouclierCurrent = m_tempsDeBouclierMax;
		}
	}
	else if (!m_estRecharge)
	{
		m_etatDeRecharge -= tempsPasse;
		
		if (m_etatDeRecharge <= 0)
		{
			std::cout << "Bouclier rechargé" << std::endl;
			m_estRecharge = true;
			m_etatDeRecharge = m_tempsDeRecharge;
		}
	}
}

float Bouclier::getTempsDeRechargeActuel()
{
	if (m_estActive)
		return m_tempsDeBouclierCurrent;
	else
		return m_etatDeRecharge;
}

float Bouclier::getTempsDeRechargeMax()
{
	if (m_estActive)
		return m_tempsDeBouclierMax;
	else
		return m_tempsDeRecharge;
}