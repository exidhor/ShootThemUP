#include "Vaisseau.h"

Vaisseau::Vaisseau(Animation const& animation, float vitesse, Animation* tir, float vie)
: MobilEntity(animation, vie, true, vitesse), m_direction(0), m_competences()
{
	m_animationTir = tir;
}

Vaisseau::Vaisseau(Animation const& animation, float vitesse, Animation* tir,
	sf::Vector2f const& position, float vie)
	: MobilEntity(animation, vie, true, vitesse, position), m_direction(0), m_competences()
{
	m_animationTir = tir;
}

Vaisseau::~Vaisseau()
{
	delete m_direction;
	m_direction = 0;

	for (int i = 0; i < m_competences.size(); i++)
	{
		if (m_competences[i] != 0)
		{
			delete m_competences[i];
			m_competences[i] = 0;
		}
	}
}

void Vaisseau::setDirection(sf::Vector2f* direction)
{
	m_direction = direction;
}

/**
recharge tous les competences du vaisseau
*/
void Vaisseau::recharge(float tempsPasse)
{
	for (int i = 0; i < m_competences.size(); i++)
	{
		m_competences[i]->recharge(tempsPasse);
	}
}

Competence* Vaisseau::getCompetence(int numero)
{
	if (numero < m_competences.size() && &m_competences[numero] != NULL)
	{
		return m_competences[numero];
	}

	return 0;
}

std::vector <Competence*> Vaisseau::getCompetence()
{
	return m_competences;
}


void Vaisseau::addCompetence(Competence* competence)
{
	m_competences.push_back(competence);
}

void Vaisseau::setVitesse(float vitesse)
{
	m_vitesse = vitesse;
}
