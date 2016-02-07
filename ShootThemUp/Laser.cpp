#include "Laser.h"
#include "Vaisseau.h"
#include "Game.h"


Laser::Laser(float tempsDeRecharge, Animation* texture,
	float damagePerTime, float ralentissementVaisseau, Vaisseau* vaisseauOrigine)
	: Competence(tempsDeRecharge, texture, vaisseauOrigine)
{
	m_damagePerTime = damagePerTime;
	m_ralentissementVaisseau = ralentissementVaisseau;
}
Laser::~Laser()
{

}

void Laser::utiliserCompetence(Game* game)
{
	if (!m_estActive)
	{
		m_game = game;
		m_estActive = true;
		m_estRecharge = false;

		int sizeLaser = actualiserTextureRect(game->getTempsPasse());
		sf::Vector2f position = getLaserPosition(sizeLaser);
		position.y += sizeLaser / 2;
		Entity* entity = new Entity(*m_animation, 1, false, position);
		entity->getSprite()->setTextureRect(
			sf::IntRect(position.x, position.y, m_animation->getTexture()->getSize().x,
			sizeLaser));

		game->addEffect(entity, TypeEffect::LASER);

		m_vaisseauOrigine->setVitesse(m_vaisseauOrigine->getVitesse() / m_ralentissementVaisseau);
	}
}


void Laser::recharge(float tempsPasse)
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_estActive)
	{
		m_estActive = false;
		m_estRecharge = true;
		if (m_game != NULL)
		{
			m_game->deleteEffect(TypeEffect::LASER);
			m_vaisseauOrigine->setVitesse(m_vaisseauOrigine->getVitesse()*m_ralentissementVaisseau);
		}
	}

	// utilisation donc degats, grossit le laser
	if (m_estActive)
	{
		//le laser grossit
		sf::Sprite & effect = *m_game->getEffect(TypeEffect::LASER)->getSprite();

		int sizeLaser = actualiserTextureRect(m_game->getTempsPasse());
		sizeLaser += effect.getGlobalBounds().height;
		//si le laser depasse la taille de la fenetre, on le reajuste
		if (sizeLaser >= m_game->getWindow()->getSize().y)
		{
			sizeLaser = m_game->getWindow()->getSize().y;
		}

		sf::Vector2f position = getLaserPosition(sizeLaser);
		
		effect.setTextureRect(sf::IntRect(position.x, position.y,
			m_animation->getTexture()->getSize().x, sizeLaser));

		effect.setPosition(position.x, position.y);

		//collision et degats
		float y = m_game->findCollisionLaser(m_game->getEffect(TypeEffect::LASER), m_damagePerTime);
		//float y = -1;

		// ajustement de la taille²
		if (y >= 0)
		{
			float veritableSize = m_vaisseauOrigine->getPosition()->y - y;
			sf::Vector2f position = getLaserPosition(veritableSize);
			effect.setTextureRect(sf::IntRect(position.x, position.y,
				m_animation->getTexture()->getSize().x, veritableSize));
			effect.setPosition(position.x, position.y);
		}
	}
}

int Laser::actualiserTextureRect(float tempsPasse)
{
	return tempsPasse * VITESSE_LASER;
}

sf::Vector2f Laser::getLaserPosition(int size)
{
	float y = m_vaisseauOrigine->getSprite()->getGlobalBounds().top - size;

	float x = m_vaisseauOrigine->getSprite()->getGlobalBounds().left
		+ ((m_vaisseauOrigine->getSprite()->getGlobalBounds().width 
		- m_animation->getTexture()->getSize().x) / 2);

	return sf::Vector2f(x, y);
}