#include "TextureManager.h"

TextureManager::TextureManager()
{
	m_texturesVaisseauJoueur = chargerTexturesVaisseauJoueur();
	m_texturesSatellite = chargerTexturesSatellite();
	m_texturesAsteroide = chargerTexturesAsteroide();
	m_texturesBouclier = chargerTexturesBouclier();
	m_leds = chargerTexturesLed();
	m_stateIndicateur = chargerTexturesStateIndicateur();

	m_interface = new sf::Texture();
	if (!m_interface->loadFromFile("interface_rogne.png"))
	{

	}

	m_background = new sf::Texture();
	if (!m_background->loadFromFile("background_extend_1200.png"))
	{
		
	}

	m_background->setRepeated(true);

	m_tir = new sf::Texture();
	if (!m_tir->loadFromFile("tir3.png"))
	{
		
	}

	sf::Texture* laser = new sf::Texture();
	if (!laser->loadFromFile("laserLigne.png"))
	{

	}
	laser->setRepeated(true);
	m_laser.push_back(laser);

	m_fontArial = new sf::Font();
	if (!m_fontArial->loadFromFile("arial.ttf"))
	{
		
	}

	//interface
	m_aiguille = new sf::Texture();
	if (!m_aiguille->loadFromFile("tableau_aiguille_rogne.png"))
	{

	}

	m_indicateur = new sf::Texture();
	if (!m_indicateur->loadFromFile("tableau_indicateurFull.png"))
	{

	}

	m_barreDeProgression = new sf::Texture();
	if (!m_barreDeProgression->loadFromFile("tableau_barreDeProgression.png"))
	{

	}
}

TextureManager::~TextureManager()
{
	for (int i = 0; i < m_texturesVaisseauJoueur.size(); i++)
	{
		if (m_texturesVaisseauJoueur[i] != 0)
		{
			delete m_texturesVaisseauJoueur[i];
			m_texturesVaisseauJoueur[i] = 0;
		}
	}

	for (int i = 0; i < m_texturesSatellite.size(); i++)
	{
		if (m_texturesSatellite[i] != 0)
		{
			delete m_texturesSatellite[i];
			m_texturesSatellite[i] = 0;
		}
	}

	for (int i = 0; i < m_texturesAsteroide.size(); i++)
	{
		if (m_texturesAsteroide[i] != 0)
		{
			delete m_texturesAsteroide[i];
			m_texturesAsteroide[i] = 0;
		}
	}

	delete m_background;
	m_background = 0;

	delete m_tir;
	m_background = 0;

	delete m_fontArial;
	m_fontArial = 0;
}

std::vector <sf::Texture*> TextureManager::getTextureVaisseauJoueur()
{
	return m_texturesVaisseauJoueur;
}

std::vector <sf::Texture*> TextureManager::getTextureAsteroide()
{
	return m_texturesAsteroide;
}

std::vector <sf::Texture*> TextureManager::getTextureSatellite()
{
	return m_texturesSatellite;
}


std::vector <sf::Texture*> TextureManager::getTextureBouclier()
{
	return m_texturesBouclier;
}

sf::Texture* TextureManager::getTextureBackground()
{
	return m_background;
}

sf::Texture* TextureManager::getTextureInterface()
{
	return m_interface;
}

sf::Texture* TextureManager::getTextureTir()
{
	return m_tir;
}

sf::Font* TextureManager::getFontArial()
{
	return m_fontArial;
}

std::vector <sf::Texture*> TextureManager::getTextureStateIndicateur()
{
	return m_stateIndicateur;
}

std::vector <sf::Texture*> TextureManager::chargerTexturesVaisseauJoueur()
{
	std::vector <sf::Texture*> texturesVaisseauJoueur;

	sf::Texture* vaisseauJoueur = new sf::Texture();
	if (!vaisseauJoueur->loadFromFile("vaisseauJoueurTest.png"))
	{
	
	}
	texturesVaisseauJoueur.push_back(vaisseauJoueur);

	sf::Texture* vaisseauJoueur2 = new sf::Texture();
	if (!vaisseauJoueur2->loadFromFile("vaisseauJoueur2.png"))
	{
		
	}
	texturesVaisseauJoueur.push_back(vaisseauJoueur2);

	sf::Texture* vaisseauJoueur3 = new sf::Texture();
	if (!vaisseauJoueur3->loadFromFile("vaisseauJoueur3.png"))
	{
		
	}
	texturesVaisseauJoueur.push_back(vaisseauJoueur3);

	sf::Texture* vaisseauJoueurSansFlamme = new sf::Texture();
	if (!vaisseauJoueurSansFlamme->loadFromFile("vaisseauJoueurSansFlamme.png"))
	{
		
	}
	texturesVaisseauJoueur.push_back(vaisseauJoueurSansFlamme);

	return texturesVaisseauJoueur;
}

std::vector <sf::Texture*> TextureManager::chargerTexturesAsteroide()
{
	std::vector <sf::Texture*> texturesAsteroide;

	sf::Texture* asteroide = new sf::Texture();
	if (!asteroide->loadFromFile("asteroide.png"))
	{

	}
	texturesAsteroide.push_back(asteroide);

	sf::Texture* asteroideBlanc = new sf::Texture();
	if (!asteroideBlanc->loadFromFile("asteroideBlanc.png"))
	{

	}
	texturesAsteroide.push_back(asteroideBlanc);

	return texturesAsteroide;
}

std::vector <sf::Texture*> TextureManager::chargerTexturesSatellite()
{
	std::vector <sf::Texture*> texturesSatellite;

	sf::Texture* satellite = new sf::Texture();
	if (!satellite->loadFromFile("satellite.png"))
	{
		
	}
	texturesSatellite.push_back(satellite);

	sf::Texture* satellite2 = new sf::Texture();
	if (!satellite2->loadFromFile("satellite2.png"))
	{
		
	}
	texturesSatellite.push_back(satellite2);

	sf::Texture* satellite3 = new sf::Texture();
	if (!satellite3->loadFromFile("satellite3.png"))
	{
		
	}
	texturesSatellite.push_back(satellite3);

	sf::Texture* satellite4 = new sf::Texture();
	if (!satellite4->loadFromFile("satellite4.png"))
	{
		
	}
	texturesSatellite.push_back(satellite4);

	sf::Texture* satellite5 = new sf::Texture();
	if (!satellite5->loadFromFile("satellite5.png"))
	{
		
	}
	texturesSatellite.push_back(satellite5);

	return texturesSatellite;
}

std::vector <sf::Texture*> TextureManager::chargerTexturesBouclier()
{
	std::vector <sf::Texture*> texturesBouclier;

	sf::Texture* bouclier = new sf::Texture();
	if (!bouclier->loadFromFile("vaisseauBouclier.png"))
	{

	}
	texturesBouclier.push_back(bouclier);

	/*sf::Texture* bouclier2 = new sf::Texture();
	if (!bouclier2->loadFromFile("bouclierTest2.png"))
	{

	}
	texturesBouclier.push_back(bouclier2);*/

	return texturesBouclier;
}

std::vector <sf::Texture*> TextureManager::getTextureLaser()
{
	return m_laser;
}

std::vector <sf::Texture*> TextureManager::chargerTexturesLed()
{
	std::vector <sf::Texture*> leds;
	//BLANCHE = 0, BLEU, BLEU_FONCE, ROUGE, VERTE, JAUNE, ROSE

	sf::Texture* led0 = new sf::Texture();
	if (!led0->loadFromFile("tableau_led_blanche.png"))
	{

	}
	leds.push_back(led0);

	sf::Texture* led = new sf::Texture();
	if (!led->loadFromFile("tableau_led_bleu.png"))
	{

	}
	leds.push_back(led);

	sf::Texture* led2 = new sf::Texture();
	if (!led2->loadFromFile("tableau_led_bleuFonce.png"))
	{

	}
	leds.push_back(led2);

	sf::Texture* led3 = new sf::Texture();
	if (!led3->loadFromFile("tableau_led_rouge.png"))
	{

	}
	leds.push_back(led3);

	sf::Texture* led4 = new sf::Texture();
	if (!led4->loadFromFile("tableau_led_verte.png"))
	{

	}
	leds.push_back(led4);

	sf::Texture* led5 = new sf::Texture();
	if (!led5->loadFromFile("tableau_led_jaune.png"))
	{

	}
	leds.push_back(led5);

	sf::Texture* led6 = new sf::Texture();
	if (!led6->loadFromFile("tableau_led_rose.png"))
	{

	}
	leds.push_back(led6);

	return leds;
}

sf::Texture* TextureManager::getTextureAiguille()
{
	return m_aiguille;
}

sf::Texture* TextureManager::getTextureIndicateur()
{
	return m_indicateur;
}

sf::Texture* TextureManager::getTextureBarreDeProgression()
{
	return m_barreDeProgression;
}

std::vector <sf::Texture*> TextureManager::getTextureLed()
{
	return m_leds;
}

std::vector <sf::Texture*> TextureManager::chargerTexturesStateIndicateur()
{
	std::vector <sf::Texture*> stateIndicateurs;

	sf::Texture* indicateur1 = new sf::Texture();
	if (!indicateur1->loadFromFile("tableau_indicateur_loading.png"))
	{

	}
	stateIndicateurs.push_back(indicateur1);

	sf::Texture* indicateur2 = new sf::Texture();
	if (!indicateur2->loadFromFile("tableau_indicateur_ready.png"))
	{

	}
	stateIndicateurs.push_back(indicateur2);

	sf::Texture* indicateur3 = new sf::Texture();
	if (!indicateur3->loadFromFile("tableau_indicateur_onUse.png"))
	{

	}
	stateIndicateurs.push_back(indicateur3);

	return stateIndicateurs;
}
