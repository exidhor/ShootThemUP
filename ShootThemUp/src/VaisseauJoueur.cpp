#include "VaisseauJoueur.h"

VaisseauJoueur::VaisseauJoueur(Animation const& animation, Animation* animationTir, Animation* animationBouclier,
	Animation* animationLaser)
: Vaisseau(animation, 10, animationTir), m_estRecharge(true)
{
	addCompetence(new Tir(2, animationTir, 3.8, 40, this));
	addCompetence(new Bouclier(600, animationBouclier, this));
	addCompetence(new Teleportation(600, NULL, this));
	addCompetence(new Ralentissement(300, NULL, this));
	addCompetence(new Laser(300, animationLaser, 1.8, 2, this));
}

VaisseauJoueur::~VaisseauJoueur()
{
	//useless
}
