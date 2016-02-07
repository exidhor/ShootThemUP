#include "AnimationManager.h"

/**
creer les animations a partir des textures
*/
AnimationManager::AnimationManager(TextureManager* textureManager)
: m_animationDecors(), m_animationVaisseau(), m_animationVaisseauJoueur(0),
m_animationProjectiles(), m_animationBouclier()
{
	std::vector <sf::Texture*> texturesSatellite = textureManager->getTextureSatellite();
	m_animationDecors.push_back(new Animation(texturesSatellite, 10));

	std::vector <sf::Texture*> texturesAsteroide = textureManager->getTextureAsteroide();
	m_animationDecors.push_back(new Animation(texturesAsteroide, 20));

	std::vector <sf::Texture*> texturesVaisseauJoueur = textureManager->getTextureVaisseauJoueur();
	m_animationVaisseauJoueur = new Animation(texturesVaisseauJoueur, 3);

	std::vector <sf::Texture*> texturesBouclier = textureManager->getTextureBouclier();
	m_animationBouclier = new Animation(texturesBouclier, 7);

	std::vector <sf::Texture*> texturesLaser = textureManager->getTextureLaser();
	m_animationLaser = new Animation(texturesLaser, 7);

	std::vector <sf::Texture*> texturesTir;
	texturesTir.push_back(textureManager->getTextureTir());
	m_animationProjectiles.push_back(new Animation(texturesTir, 200));
}

/**
detruit les animations stockées
*/
AnimationManager::~AnimationManager()
{
	for (int i = 0; i < m_animationDecors.size(); i++)
	{
		delete m_animationDecors[i];
		m_animationDecors[i] = 0;
	}

	for (int i = 0; i < m_animationVaisseau.size(); i++)
	{
		delete m_animationVaisseau[i];
		m_animationVaisseau[i] = 0;
	}

	delete m_animationVaisseauJoueur;
	m_animationVaisseauJoueur = 0;
}


/**
retourne les animations pour les decors
*/
std::vector <Animation*> & AnimationManager::getAnimationDecors()
{
	return m_animationDecors;
}

Animation & AnimationManager::getAnimationVaisseau(TypeVaisseauEnnemi type)
{
	return *m_animationVaisseau[type];
}

Animation & AnimationManager::getAnimationProjectile(TypeProjectile type)
{
	return *m_animationProjectiles[type];
}

Animation & AnimationManager::getAnimationVaisseauJoueur()
{
	return *m_animationVaisseauJoueur;
}

Animation & AnimationManager::getAnimationBouclier()
{
	return *m_animationBouclier;
}

Animation & AnimationManager::getAnimationLaser()
{
	return *m_animationLaser;
}