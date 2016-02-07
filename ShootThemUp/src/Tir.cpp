#include "Tir.h"
#include "Game.h"
#include "Vaisseau.h"

Tir::Tir(float tempsDeRecharge, Animation* texture,
	float damage, float vitesse, Vaisseau* vaisseauOrigine)
	: Competence(tempsDeRecharge, texture, vaisseauOrigine)
{
	m_damage = damage;
	m_vitesse = vitesse;
}

Tir::~Tir()
{

}

void Tir::utiliserCompetence(Game* game)
{
	m_estRecharge = false;
	game->addProjectile(tirer());
}


Projectile* Tir::tirer()
{
	return new Projectile(m_vitesse, Direction::VERS_LE_HAUT, EquationDroite(0, 
		m_vaisseauOrigine->getPositionCentre().x, 'x'), m_damage,
		m_vaisseauOrigine->getPositionCentre(), *m_animation);
}