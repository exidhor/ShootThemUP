#include "Animation.h"

/**
Cree un animation a partir d'un tableau de textures
*/
Animation::Animation(std::vector <sf::Texture*> textures, float tempsIntervalleRafraichissement)
: m_indiceCurrentTexture(0), m_tempsIntervalleRafraichissement(tempsIntervalleRafraichissement),
m_tempsAttenteCurrent(tempsIntervalleRafraichissement)
{
	if (textures.size() <= 0)
	{
		std::cout << "ERROR SIZE OF TEXTURES ANIMATION < 0" << std::endl;
	}
	m_textures = textures;
}

/**
Copie une animation ainsi que ca situation actuelle
*/
Animation::Animation(Animation const& animation)
: m_indiceCurrentTexture(animation.m_indiceCurrentTexture), m_tempsIntervalleRafraichissement(animation.m_tempsIntervalleRafraichissement),
m_textures(), m_tempsAttenteCurrent(animation.m_tempsAttenteCurrent)
{
	for (int i = 0; i < animation.m_textures.size(); i++)
	{
		m_textures.push_back(animation.m_textures[i]);
	}
}

/**
USELESS
*/
Animation::~Animation()
{

}

/**
Retourne la texture suivante pour correspondre a l'animation
*/
sf::Texture* Animation::getTexture()
{
	return m_textures[m_indiceCurrentTexture];
}

void Animation::actualiser(float tempsPasse)
{
	m_tempsAttenteCurrent -= tempsPasse;
	if (m_tempsAttenteCurrent <= 0)
	{
		m_tempsAttenteCurrent += m_tempsIntervalleRafraichissement;

		m_indiceCurrentTexture++;

		if (m_indiceCurrentTexture >= m_textures.size())
		{
			m_indiceCurrentTexture = 0;
		}
	}
}

/**
ajoute une texture a la fin de l'animation
*/
void Animation::addTexture(sf::Texture* texture)
{
	m_textures.push_back(texture);
}


float Animation::getTempsIntervalleRafraichissement()
{
	return m_tempsIntervalleRafraichissement;
}
