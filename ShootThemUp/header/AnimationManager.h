#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include "Animation.h"
#include "TextureManager.h"

/**
USELESS
*/
enum TypeVaisseauEnnemi {
	DEFAUT = 0
};


/**
USELESS
*/
enum TypeProjectile {
	TIR = 0
};

/**
Regroupe et crée toutes les animations, et les distribuera pour tout
le programme
*/
class AnimationManager
{
private:
	std::vector <Animation*> m_animationDecors;
	std::vector <Animation*> m_animationVaisseau;
	Animation* m_animationBouclier;
	Animation* m_animationLaser;
	Animation* m_animationVaisseauJoueur;
	std::vector <Animation*> m_animationProjectiles;
public:
	AnimationManager(TextureManager* textureManager);
	~AnimationManager();

	std::vector <Animation*> & getAnimationDecors();
	Animation & getAnimationVaisseau(TypeVaisseauEnnemi type);
	Animation & getAnimationProjectile(TypeProjectile type);
	Animation & getAnimationVaisseauJoueur();
	Animation & getAnimationBouclier();
	Animation & getAnimationLaser();
};