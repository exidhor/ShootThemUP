#include "EquationDroite.h"

/**
le type définit si le terme à gauche de l'equation est x ou y
*/
EquationDroite::EquationDroite(float pente, float ordonneeOrigine, char type)
	:  m_pente(pente), m_ordonneeOrigine(ordonneeOrigine)
{
	if (type != 'x' && type != 'y')
	{
		m_type = 'y';
	}
	else
	{
		m_type = type;
	}
}

EquationDroite::~EquationDroite()
{
	//useless for the moment
}

char EquationDroite::getType()
{
	return m_type;
}

float EquationDroite::getPente()
{
	return m_pente;
}

float EquationDroite::getOrdonneeOrigine()
{
	return m_ordonneeOrigine;
}

/**
L'utilisation de cette fonction necessite une verification que les coord ne soient pas -1
*/
TokenPoint EquationDroite::trouverPoint(float abscisseOuOrdonnee, Axe axe)
{
	TokenPoint tokenPoint(sf::Vector2f(abscisseOuOrdonnee, abscisseOuOrdonnee));

	if (m_type == 'y')
	{
		if (axe == Axe::ABSCISSE)
		{
			if (m_pente != 0)
			{
				tokenPoint.point.x = (abscisseOuOrdonnee - m_ordonneeOrigine) / m_pente;
			}
			else
			{
				tokenPoint.estValide = false;
			}
		}

		else if (axe == Axe::ORDONNEE)
		{
			tokenPoint.point.y = m_pente * abscisseOuOrdonnee + m_ordonneeOrigine;
		}
	}
	else if (m_type == 'x')
	{
		if (axe == Axe::ABSCISSE)
		{
			tokenPoint.estValide = false;
		}

		else if (axe == Axe::ORDONNEE)
		{
			tokenPoint.point.y = abscisseOuOrdonnee;
		}
	}
	else
	{
		tokenPoint.estValide = false;
	}

	return tokenPoint;
}


/**
retourne un token qui determinera si la droite coupe un des bords de la fenetre et qui renverra
le point d'intersection
*/
TokenPoint EquationDroite::trouverIntersectionAvecBord(sf::Vector2f const& direction,
	float width, float height)
{
	TokenPoint token(direction);

	if (direction.x < 0)
	{
		token = trouverPoint(0, Axe::ORDONNEE);
		if (token.estValide && estDansLeCadreDeLaFenetre(width, height, token.point))
		{
			return token;
		}
	}

	else if (direction.x > width)
	{
		token = trouverPoint(width, Axe::ORDONNEE);
		if (token.estValide && estDansLeCadreDeLaFenetre(width, height, token.point))
		{
			return token;
		}
	}

	if (direction.y < 0)
	{
		token = trouverPoint(0, Axe::ABSCISSE);
		if (token.estValide && estDansLeCadreDeLaFenetre(width, height, token.point))
		{
			return token;
		}
	}

	else if (direction.y > height)
	{
		token = trouverPoint(height, Axe::ABSCISSE);
		if (token.estValide && estDansLeCadreDeLaFenetre(width, height, token.point))
		{
			return token;
		}
	}

	std::cout << "return token default !!!" << std::endl;
	token.point = direction;
	return token;
}

/**
determine si la droite coupe le cardre de la fenetre
*/
bool EquationDroite::estDansLeCadreDeLaFenetre(float width, float height, sf::Vector2f const& point)
{
	return ((point.x == 0 && point.y >= 0 && point.y <= height) ||
		(point.x == width && point.y >= 0 && point.y <= height) ||
		(point.y == 0 && point.x >= 0 && point.x <= width) ||
		(point.y == height && point.x >= 0 && point.x <= width));
}