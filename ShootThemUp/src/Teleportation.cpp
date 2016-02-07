#include "Teleportation.h"
#include "Vaisseau.h"
#include "Game.h"

Teleportation::Teleportation(float tempsDeRecharge, Animation* animation, Vaisseau* vaisseauOrigine)
: Competence(tempsDeRecharge, animation, vaisseauOrigine)
{

}

Teleportation::~Teleportation()
{

}

void Teleportation::utiliserCompetence(Game* game)
{
	m_vaisseauOrigine->setPosition(game->getPositionMouse());
	m_estRecharge = false;
}
