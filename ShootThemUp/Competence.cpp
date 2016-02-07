#include "Competence.h"

Competence::Competence(float tempsDeRecharge, Animation* animation, Vaisseau* vaisseauOrigine)
: m_tempsDeRecharge(tempsDeRecharge), m_vaisseauOrigine(vaisseauOrigine), m_animation(animation),
m_estActive(false)
{
	m_estRecharge = true;
	m_etatDeRecharge = m_tempsDeRecharge;
}

Competence::~Competence()
{

}

bool Competence::estRecharge()
{
	return m_estRecharge;
}

void Competence::utiliserCompetence(Game* game)
{
	m_estRecharge = false;
}

void Competence::recharge(float tempsPasse)
{
	if (!m_estRecharge)
	{
		m_etatDeRecharge -= tempsPasse;

		if (m_etatDeRecharge <= 0)
		{
			m_etatDeRecharge = m_tempsDeRecharge;
			m_estRecharge = true;
		}
	}
}

bool Competence::estActive()
{
	return m_estActive;
}

Animation* Competence::getAnimation()
{
	return m_animation;
}

float Competence::getTempsDeRechargeActuel()
{
	return m_etatDeRecharge;
}

float Competence::getTempsDeRechargeMax()
{
	return m_tempsDeRecharge;
}