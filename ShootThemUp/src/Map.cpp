#include "Map.h"

/**
La Map est codé par un tab 2d qui vont representer les decors
*/
Map::Map(int largeurFenetre, int hauteurFenetre, std::vector <Animation*> animations
	, sf::Font* font)
: m_decors(NBRE_ELEMENTS_HAUTEUR, std::vector <Decors*> ()), 
m_texteScore()
{
	m_hauteurFenetre = hauteurFenetre;
	m_largeurFenetre = largeurFenetre;
	m_coinBasFenetreMap = 0;
	m_animationsDecors = animations;

	creerInfoTexte(font);

	m_score = 0;

	ajoutLigne();
}

Map::~Map()
{
	/*
	for (int i = 0; m_decors.size(); i++)
	{
		for (int j = 0; m_decors[i].size(); j++)
		{
			if (m_decors[i][j] != NULL)
			{
				delete m_decors[i][j];
				m_decors[i][j] = NULL;
			}
		}
	}
	for (int i = 0; m_decors.size(); i++)
	{
		m_decors[i].clear();
	}*/
}

void Map::creerInfoTexte(sf::Font* font)
{
	m_texteScore.setFont(*font);
	m_texteTourLoop.setFont(*font);

	m_texteScore.setString("0");
	m_texteTourLoop.setString("0");

	// set the character size in pixel
	m_texteScore.setCharacterSize(24);
	m_texteTourLoop.setCharacterSize(24);

	m_texteScore.setColor(sf::Color::Red);
	m_texteTourLoop.setColor(sf::Color::Blue);

	m_texteScore.setStyle(sf::Text::Bold);
	m_texteTourLoop.setStyle(sf::Text::Bold);

	m_texteTourLoop.setPosition(690, 10);
}

/**
dessine les decors ainsi que les info Joueur
*/
void Map::drawMap(sf::RenderWindow* window)
{
	for (intI i = 0; i < m_decors.size(); i++)
	{
		for (intI j = 0; j <m_decors[i].size(); j++)
		{
			m_decors[i][j]->draw(window);
		}
	}

	//window->draw(m_texteTourLoop);
	window->draw(m_texteScore);
}

/**
envoie le tempsPasse pour actualiser les animations
*/
void Map::actualiserAnimation(float tempsPasse)
{
	for (intI i = 0; i < m_decors.size(); i++)
	{
		for (intI j = 0; j <m_decors[i].size(); j++)
		{
			m_decors[i][j]->getAnimation()->actualiser(tempsPasse);
		}
	}

}

/**
verifie les collisions avec les tirs et le vaisseau du Joueur
renvoie vrai si pas de collision entre decors et vaisseau Joueur
*/
bool Map::collisionBloc(Entity & entity, std::vector<Projectile*> & tirs, float & score)
{
	for (intI i = 0; i < m_decors.size(); i++)
	{
		for (intI j = 0; j <m_decors[i].size(); j++)
		{

			bool find = false;
			//collision avec les tirs
			for (intI k = 0; k < tirs.size() && !find; k++)
			{
				if (m_decors[i][j]->getSprite()->getGlobalBounds().intersects(tirs[k]->getSprite()->getGlobalBounds()))
				{
					m_decors[i][j]->prendreDegats(tirs[k]->getDamage());
					if (!m_decors[i][j]->estEnVie())
					{
						delete m_decors[i][j];
						m_decors[i][j] = 0;
						m_decors[i].erase(m_decors[i].begin() + (int)j);
						j--;
						m_score += 1000;
						find = true;
					}
					delete tirs[k];
					tirs[k] = 0;
				}
			}

			for (int i = tirs.size() - 1; i >= 0; i--)
			{
				if (tirs[i] == NULL)
					tirs.erase(tirs.begin() + i);
			}

			//collision avec le vaisseau
			if (!find && m_decors[i][j]->getSprite()->getGlobalBounds().intersects(entity.getSprite()->getGlobalBounds()))
			{
				if (entity.estDestructible())
					return false;
				else
				{
					delete m_decors[i][j];
					m_decors[i][j] = 0;
					m_decors[i].erase(m_decors[i].begin() + (int)j);
					score += 1000;
				}
			}
		}
	}

	return true;
}


/**
deplace les blocs en fonction du TempsPasse, supprime les bloc qui sortent 
de la fenetre et creer de nouveaux blocs
*/
void Map::actualisationMapAvecScrolling(float distanceParcouru = 0)
{
	m_score += distanceParcouru;

	m_coinBasFenetreMap += distanceParcouru;

	for (intI i = 0; i < m_decors.size(); i++)
	{
		for (intI j = 0; j <m_decors[i].size(); j++)
		{
			m_decors[i][j]->deplacementScrolling(distanceParcouru);
		}
	}

	if (m_coinBasFenetreMap > m_hauteurFenetre / NBRE_ELEMENTS_HAUTEUR)
	{
		//actualisation de la valeur de la distance
		m_coinBasFenetreMap = m_hauteurFenetre / NBRE_ELEMENTS_HAUTEUR - m_coinBasFenetreMap;

		//suppression de la derniere ligne
		m_decors[0].clear();
		m_decors.erase(m_decors.begin());

		ajoutLigne(m_coinBasFenetreMap);
	}
}

void Map::setTextScore(float score)
{
	m_texteScore.setString(std::to_string((int)m_score));
}


void Map::setTexteTourLoop(float loop)
{
	m_texteTourLoop.setString(std::to_string(loop));
}

/**
creer une ligne de decors et l'ajoute a la map
*/
void Map::ajoutLigne(float distanceSupplementaireParcouru)
{
	std::vector <Decors*> nouvelleLigne;

	for (intI i = 0; i < NBRE_ELEMENTS_LARGEUR; i++)
	{
		int randomInt = rand() % PROBA_ASTEROIDE;
		if (randomInt == 1)
		{ 
			nouvelleLigne.push_back(new Decors(50, true, *m_animationsDecors[ElementDecors::ASTEROIDE],
				sf::Vector2f(i * m_largeurFenetre / NBRE_ELEMENTS_LARGEUR + m_largeurFenetre / (2 * NBRE_ELEMENTS_LARGEUR),
				-m_hauteurFenetre / NBRE_ELEMENTS_HAUTEUR + distanceSupplementaireParcouru + m_hauteurFenetre / (2 * NBRE_ELEMENTS_HAUTEUR))));
		}
		else
		{
			randomInt = rand() % PROBA_SATELLITE;
			if (randomInt == 1)
			{
				nouvelleLigne.push_back(new Decors(1, false, *m_animationsDecors[ElementDecors::SATELLITE],
					sf::Vector2f(i * m_largeurFenetre / NBRE_ELEMENTS_LARGEUR + m_largeurFenetre / (2 * NBRE_ELEMENTS_LARGEUR),
					-m_hauteurFenetre / NBRE_ELEMENTS_HAUTEUR + distanceSupplementaireParcouru + m_hauteurFenetre / (2 * NBRE_ELEMENTS_HAUTEUR))));
			}
		}
	}

	//ajout a la map
	m_decors.push_back(nouvelleLigne);
}

/**
retourne -1 si rien de trouve
*/
float Map::findCollisionLaser(Entity* entity, float dmg)
{
	//std::cout << "MAP : width : " << entity->getSprite()->getGlobalBounds().width << " height : " << entity->getSprite()->getGlobalBounds().height << " dmg : " << dmg << std::endl;
	bool find = false;
	sf::FloatRect boundTouche;
	bool touche = false;
	bool toucheDestruction = false;
	float resultat = -1;

	for (int i = 0; i < m_decors.size(); i++)
	{
		for (int j = 0; j < m_decors[i].size(); j++)
		{
			if (touche && boundTouche.left + boundTouche.width >= m_decors[i][j]->getSprite()->getGlobalBounds().left - 2)
			{
				find = true;
			}
			else if (touche)
			{
				return resultat;
			}


			if (entity->getSprite()->getGlobalBounds().intersects(m_decors[i][j]->getSprite()->getGlobalBounds()))
			{
				resultat = m_decors[i][j]->getSprite()->getGlobalBounds().top + m_decors[i][j]->getSprite()->getGlobalBounds().height;

				boundTouche = m_decors[i][j]->getSprite()->getGlobalBounds();
				m_decors[i][j]->prendreDegats(dmg);
				touche = true;

				if (!m_decors[i][j]->estEnVie())
				{
					delete m_decors[i][j];
					m_decors[i].erase(m_decors[i].begin() + (int)j);
					j--;
					m_score += 1000;

					if (find)
					{
						return resultat;
					}
				}						

			}
			if (touche)
			{
				return resultat;
			}

		}
	}

	return resultat;
}

bool Map::gestionDegats(Decors* & decors, float dmg)
{
	decors->prendreDegats(dmg);
	if (!decors->estEnVie())
	{
		delete decors;
		decors = 0;
		return true;
	}
	return false;
}