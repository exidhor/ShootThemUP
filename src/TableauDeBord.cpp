#include "TableauDeBord.h"

TableauDeBord::TableauDeBord(sf::Texture* animationAiguille, std::vector <sf::Texture*> animationTableauLed,
	sf::Texture* animationBarreDeProgression, sf::Texture* animationIndicateurFull, std::vector <sf::Texture*> textureIndicateurComp3,
	sf::Vector2f positionInterface)
	:m_aiguille(), 
	m_led(),
	m_barreDeProgression(),
	m_indicateurFull(),
	m_animationIndicateurComp3()
{
	m_positionInterface = positionInterface;

	//initialisation des animations
	m_animationAiguille = animationAiguille;
	m_animationTableauLed = animationTableauLed;
	m_animationBarreDeProgression = animationBarreDeProgression;
	m_animationIndicateurFull = animationIndicateurFull;
	m_animationIndicateurComp3 = textureIndicateurComp3;

	//initialisation des Sprites
	m_aiguille.setTexture(*animationAiguille);
	m_led.setTexture(*animationTableauLed[0]);
	m_barreDeProgression.setTexture(*animationBarreDeProgression);
	m_indicateurFull.setTexture(*animationIndicateurFull);
	m_indicateurComp3.setTexture(*m_animationIndicateurComp3[0]);

	//placemement des Sprites
	m_positionInterface = sf::Vector2f(200, 0);

	m_aiguille.setPosition(m_positionInterface.x + 660 + 38, m_positionInterface.y + 654 + 7);
	m_aiguille.setOrigin(38, 7);
	m_aiguille.setRotation(247);

	m_indicateurComp3.setPosition(m_positionInterface.x + 685, m_positionInterface.y + 644);

	m_led.setPosition(m_positionInterface.x + 11, m_positionInterface.y + 638);
	m_barreDeProgression.setPosition(m_positionInterface.x + 245, m_positionInterface.y + 657);
	m_indicateurFull.setPosition(m_positionInterface.x + 310, m_positionInterface.y + 663);

	m_nbreLedAllumees = 5;

	chargerTableauLed();

	m_xBarreDeProgression = 279;

	indicateurFullActive = true;
}

TableauDeBord::~TableauDeBord()
{

}

void TableauDeBord::actualiserAnimationAvecTemps(float tempsPasse)
{
	//TO DO
}

void TableauDeBord::actualiserAnimationAvecCompetence(float rapportTempsComp1, float rapportTempsComp2, float rapportTempsComp3, bool comp3estActive)
{
	//leds
	m_nbreLedAllumees = rapportTempsComp1 * 49;

	//Barre de progression
	m_xBarreDeProgression = rapportTempsComp2 * 279;

	m_barreDeProgression.setTextureRect(sf::IntRect(0, 0, m_xBarreDeProgression ,m_barreDeProgression.getTexture()->getSize().y));

	//indicateurFull
	if (m_xBarreDeProgression == 279)
	{
		indicateurFullActive = true;
	}
	else
	{
		indicateurFullActive = false;
	}

	//aiguille
	rapportTempsComp3 *= 314;
	rapportTempsComp3 -= 67;
	m_aiguille.setRotation(rapportTempsComp3);

	if (comp3estActive)
	{
		m_indicateurComp3.setTexture(*m_animationIndicateurComp3[2]);
	}
	else
	{
		if (rapportTempsComp3 == 247)
		{
			m_indicateurComp3.setTexture(*m_animationIndicateurComp3[1]);
		}
		else
		{
			m_indicateurComp3.setTexture(*m_animationIndicateurComp3[0]);
		}
	}
}

void TableauDeBord::draw(sf::RenderWindow* window)
{
	//affichage des leds
	int compteurLedAllumees = 0;
	//led de depart
	sf::Vector2f position(m_positionInterface.x + 12, m_positionInterface.y + 638);

	for (int i = 0; i < m_tableauLed.size() && compteurLedAllumees < m_nbreLedAllumees; i++)
	{
		position.y = m_positionInterface.y + 638;

		for (int j = 0; j < m_tableauLed[i].size() && compteurLedAllumees < m_nbreLedAllumees; j++)
		{
			m_led.setPosition(position);
			m_led.setTexture(*getTextureLed(m_tableauLed[i][j]));
			window->draw(m_led);

			compteurLedAllumees++;
			position.y += 10;
		}
		position.x += 24;
	}

	//affichage du reste
	window->draw(m_indicateurComp3);
	window->draw(m_aiguille);

	window->draw(m_barreDeProgression);

	if (indicateurFullActive)
	{
		window->draw(m_indicateurFull);
	}
}

CouleurLed TableauDeBord::getCouleurLed()
{
	int randomInt = rand() % (TAILLE_ENUM_COULEURLED - 1);
	randomInt++;
	return static_cast <CouleurLed>(randomInt);
}

void TableauDeBord::chargerTableauLed()
{
	for (int i = 0; i < TAILLE_TABLEAU_LED_LARGEUR; i++)
	{
		m_tableauLed.push_back(std::vector <CouleurLed>());

		for (int j = 0; j < TAILLE_TABLEAU_LED_HAUTEUR; j++)
		{
			m_tableauLed[i].push_back(getCouleurLed());
		}
	}
}

sf::Texture* TableauDeBord::getTextureLed(CouleurLed couleurLed)
{
	return m_animationTableauLed[couleurLed];
}

void TableauDeBord::setInterfacePosition(sf::Vector2f position)
{
	m_positionInterface = position;
}