#include "Game.h"

/**
Crée une partie, l'associe a la fenetre, crée la Map, ainsi que le
vaisseau du Joueur
*/
Game::Game(sf::RenderWindow* window, TextureManager & textureManager, AnimationManager & animationManager)
: m_vaisseaux(),
m_tirs(),
m_vaisseauJoueur(animationManager.getAnimationVaisseauJoueur(), &animationManager.getAnimationProjectile(TypeProjectile::TIR), &animationManager.getAnimationBouclier(), &animationManager.getAnimationLaser()),
m_map(window->getSize().x, window->getSize().y, animationManager.getAnimationDecors(), textureManager.getFontArial()),
m_background(textureManager.getTextureBackground()), m_distanceParcouru(0), m_textureManager(&textureManager),
m_interface(*textureManager.getTextureInterface()),
m_effects(),
tableauDeBord(textureManager.getTextureAiguille(), textureManager.getTextureLed(),textureManager.getTextureBarreDeProgression(),
textureManager.getTextureIndicateur(), textureManager.chargerTexturesStateIndicateur())
{
	m_interface.setPosition(200, 600);

	//tableauDeBord.setInterfacePosition(sf::Vector2f(200, 600));

	m_effects.push_back(NULL);

	m_effectLaser = 0;

	m_tempsPasse = 1;

	m_window = window;
	m_vitesseScrolling = 3;
	m_tourLoop = 0;
	m_animationManager = &animationManager;
	m_coefRalentissement = 1;

	m_vaisseauJoueur.setPosition(500, 260);
}

/**
Supprime le tableau d'entité, ainsi que celui des Tirs
*/
Game::~Game()
{
	for (intI i = 0; i < m_vaisseaux.size(); ++i)
	{
		if (m_vaisseaux[i] != 0)
		{
			delete m_vaisseaux[i];
			m_vaisseaux[i] = 0;
		}
	}

	for (intI i = 0; i < m_tirs.size(); ++i)
	{
		if (m_tirs[i] != 0)
		{
			delete m_tirs[i];
			m_tirs[i] = 0;
		}
	}
}


/**
Représente un tour de boucle, ici ce trouve
toutes la gestion du jeu
@return true si pas de collision
*/
bool Game::gameLoop(sf::Clock & clock)
{
	affichage();

	sf::Event event;
	recuperationEntree(event);

	//valeur qui sera retrournée a la fin de la GameLoop
	bool etat = m_map.collisionBloc(m_vaisseauJoueur, m_tirs, m_distanceParcouru);

	actualisationInfoJoueur();

	//actualisation du temps
	m_tempsPasse = clock.getElapsedTime().asMicroseconds() / 20000.;
	clock.restart().asMicroseconds();
	m_tempsPasse /= m_coefRalentissement;

	//calcul de la trajectoire puis la vitesse sera calculé a part
	traitement(event, m_tempsPasse);

	gestionScrolling(m_tempsPasse);

	//deplacement des tirs
	gererTirs(m_tempsPasse);

	rechargeDesVaisseaux(m_tempsPasse);

	actualiserAnimation(m_tempsPasse);

	//comp 1
	float tempsMaxComp = m_vaisseauJoueur.getCompetence(2)->getTempsDeRechargeMax();
	float tempsActuelComp = m_vaisseauJoueur.getCompetence(2)->getTempsDeRechargeActuel();
	float rapportComp1 = 1;

	if (tempsActuelComp != tempsMaxComp)
		rapportComp1 = ((tempsMaxComp - tempsActuelComp) / tempsMaxComp);

	//comp 2
	tempsMaxComp = m_vaisseauJoueur.getCompetence(3)->getTempsDeRechargeMax();
	tempsActuelComp = m_vaisseauJoueur.getCompetence(3)->getTempsDeRechargeActuel();
	float rapportComp2 = tempsActuelComp / tempsMaxComp;

	//comp 3
	tempsMaxComp = m_vaisseauJoueur.getCompetence(1)->getTempsDeRechargeMax();
	tempsActuelComp = m_vaisseauJoueur.getCompetence(1)->getTempsDeRechargeActuel();
	float rapportComp3 = 1;
	if (m_vaisseauJoueur.getCompetence(1)->estActive())
	{
		rapportComp3 = tempsActuelComp / tempsMaxComp;
	}
	else if (tempsActuelComp != tempsMaxComp)
	{
		rapportComp3 = (tempsMaxComp - tempsActuelComp) / tempsMaxComp;
	}

	tableauDeBord.actualiserAnimationAvecCompetence(rapportComp1, rapportComp2, rapportComp3, m_vaisseauJoueur.getCompetence(1)->estActive());

	return etat;
}

/**
Supprime les tirs qui sortent de la fenetre, sinon deplace
les projectiles
*/
void Game::gererTirs(float tempsPasse)
{
	for (intI i = 0; i < m_tirs.size(); ++i)
	{
		if (!estDansLaFenetre(m_window, m_tirs[i]->getSprite()->getGlobalBounds(), 
			m_tirs[i]->getSprite()->getPosition()))
		{
			m_tirs.erase(m_tirs.begin() + i);
		}
		else
		{
			m_tirs[i]->move(tempsPasse);
		}
	}

}

/**
Gere les entrées n'appartenant pas au deplacement
*/
void Game::recuperationEntree(sf::Event & event)
{
	while (m_window->pollEvent(event))
	{
		// fermeture de la fenêtre lorsque l'utilisateur le souhaite
		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			m_window->close();

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X)
		{
			std::cout << "mode Indestructible" << m_vaisseauJoueur.estDestructible() << std::endl;
			m_vaisseauJoueur.setDestructible(!m_vaisseauJoueur.estDestructible());
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_vaisseauJoueur.getCompetence(0)->estRecharge())
	{
		m_vaisseauJoueur.getCompetence(0)->utiliserCompetence(this);
	}

	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_vaisseauJoueur.getCompetence(4)->estRecharge())
	{
		m_vaisseauJoueur.getCompetence(4)->utiliserCompetence(this);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_vaisseauJoueur.getCompetence(1)->estRecharge())
	{
		m_vaisseauJoueur.getCompetence(1)->utiliserCompetence(this);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && m_vaisseauJoueur.getCompetence(2)->estRecharge())
	{
		m_vaisseauJoueur.getCompetence(2)->utiliserCompetence(this);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_vaisseauJoueur.getCompetence(3)->estRecharge())
	{
		m_vaisseauJoueur.getCompetence(3)->utiliserCompetence(this);
	}
}

/**
traitement des entrées du joueur (->gameplay), notamment le clic de la souris
*/
void Game::traitement(sf::Event & event, float tempsPasse)
{
	if (true/*sf::Mouse::isButtonPressed(sf::Mouse::Left)*/)
	{
		sf::Vector2i positionMouse = sf::Mouse::getPosition(*(m_window));
		sf::Vector2f conversionMouse = sf::Vector2f((float)positionMouse.x,
													(float)positionMouse.y);

		sf::Vector2f deplacement = Deplacement::getPointArrive(
			m_vaisseauJoueur.getPositionCentre(),conversionMouse,
			m_vaisseauJoueur.getVitesse()*tempsPasse, m_window->getSize().x, m_window->getSize().y - 125);
		
		m_vaisseauJoueur.setPosition(deplacement);
	}
}

/**
affiche tout
*/
void Game::affichage()
{
	m_window->clear();

	m_background.draw(m_window);

	m_map.drawMap(m_window);

	for (intI i = 0; i < m_tirs.size(); ++i)
	{
		m_tirs[i]->draw(m_window);
	}


	if (m_vaisseauJoueur.getCompetence(4)->estActive())
	{
		m_effectLaser->draw(m_window);
	}

	
	for (intI i = 0; i < m_vaisseaux.size(); ++i)
	{
		m_vaisseaux[i]->draw(m_window);
	}

	m_vaisseauJoueur.draw(m_window);
	   

	if (m_vaisseauJoueur.getCompetence(1)->estActive() && m_vaisseauJoueur.getCompetence(1)->getAnimation() != NULL)
	{
		sf::Sprite spriteCompetence(*m_vaisseauJoueur.getCompetence(1)->getAnimation()->getTexture());
		spriteCompetence.setPosition(sf::Vector2f(m_vaisseauJoueur.getPosition()->x-23, m_vaisseauJoueur.getPosition()->y-18));
		m_window->draw(spriteCompetence);
	}


	m_window->draw(m_interface);
	tableauDeBord.draw(m_window);

	m_window->display();
}

/**
permet d'informer toutes les animations du temps passé
*/
void Game::actualiserAnimation(float tempsPasse)
{

	m_map.actualiserAnimation(tempsPasse);

	for (intI i = 0; i < m_tirs.size(); ++i)
	{
		m_tirs[i]->getAnimation()->actualiser(tempsPasse);
	}

	for (intI i = 0; i < m_vaisseaux.size(); ++i)
	{
		m_vaisseaux[i]->getAnimation()->actualiser(tempsPasse);
	}

	for (int i = 0; i < m_vaisseauJoueur.getCompetence().size(); i++)
	{
		if (m_vaisseauJoueur.getCompetence(i)->estActive())
		{
			if (m_vaisseauJoueur.getCompetence(i)->getAnimation() != NULL)
			m_vaisseauJoueur.getCompetence(i)->getAnimation()->actualiser(tempsPasse);
		}
	}

	m_vaisseauJoueur.getAnimation()->actualiser(tempsPasse);
}

/**
retourne vrai si le rectangle possede une partie au moins dans la fenetre
*/
bool Game::estDansLaFenetre(sf::RenderWindow* window, sf::FloatRect bounds, sf::Vector2f position)
{
	return bounds.top >= -(bounds.height * 2) && bounds.top <= window->getSize().y &&
		bounds.left <= window->getSize().x && bounds.left >= 0;
}

sf::RenderWindow* Game::getWindow()
{
	return m_window;
}

/**
gere les differents scrolling en envoyant les deplacements a effectué
*/
void Game::gestionScrolling(float tempsPasse)
{
	float distanceParcouruDernierement = calculDistanceParcouru(tempsPasse);
	m_distanceParcouru += distanceParcouruDernierement;

	m_map.actualisationMapAvecScrolling(distanceParcouruDernierement);

	m_background.actualiserScrolling(distanceParcouruDernierement/RALENTISSEMENT_BACKGROUND);
}

/**
retourne la distance qu'il faut parcourir
*/
float Game::calculDistanceParcouru(float tempsPasse)
{
	m_vitesseScrolling += tempsPasse / ACCELERATION_SCROLLING;
	return m_vitesseScrolling * tempsPasse;
}

/**
actualise les informations qui sont pour le joueur :
score et recharge
*/
void Game::actualisationInfoJoueur()
{
	m_map.setTextScore(m_distanceParcouru);
	m_map.setTexteTourLoop(m_tourLoop);
}

/**
execute la recharge pour toutes les competences de tous les vaisseaux
*/
void Game::rechargeDesVaisseaux(float tempsPasse)
{
	for (intI i = 0; i < m_vaisseaux.size(); i++)
	{
		m_vaisseaux[i]->recharge(tempsPasse);
	}

	//recharge du vaisseauJoueur
	m_vaisseauJoueur.recharge(tempsPasse);
}


/**
ajoute un projectile a la map (utile pour les competences)
*/
void Game::addProjectile(Projectile* projectile)
{
	m_tirs.push_back(projectile);
}

sf::Vector2f Game::getPositionMouse()
{
	return sf::Vector2f(sf::Mouse::getPosition(*(m_window)));
}

void Game::setVitesseJeu(float coefDiminution)
{
	m_coefRalentissement = coefDiminution;
}

void Game::addEffect(Entity* entity, TypeEffect effect)
{
	m_effectLaser = entity;
	//std::cout << "Appel" << std::endl;
}

Entity* Game::getEffect(TypeEffect typeEffect)
{
	return m_effectLaser;
}

float Game::getTempsPasse()
{
	return m_tempsPasse;
}

void Game::deleteEffect(TypeEffect typeEffect)
{
	//std::cout << "Destruction" << std::endl;
	delete m_effectLaser;
	m_effectLaser = 0;
}

float Game::findCollisionLaser(Entity* entity, float dmg)
{
	//std::cout << "width : " << m_effectLaser->getSprite()->getGlobalBounds().width << " height : " << m_effectLaser->getSprite()->getGlobalBounds().height << " dmg : " << dmg * m_tempsPasse * 100 << std::endl;
	return m_map.findCollisionLaser(m_effectLaser, dmg * m_tempsPasse);
}