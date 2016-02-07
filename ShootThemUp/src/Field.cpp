#include "Field.h"

Field::Field(TypeField type, sf::Vector2f position, sf::Font* font, sf::Vector2f boundsContour)
:	m_shapeField(sf::Vector2f(boundsContour.x/2, boundsContour.y/2)),
	m_text("", *font)
{
	m_shapeField.setFillColor(sf::Color::Black);
	m_shapeField.setPosition(position.x + (boundsContour.x - m_shapeField.getGlobalBounds().width) / 5,
		position.y + (boundsContour.y - m_shapeField.getGlobalBounds().height) / 2);

	m_text.setColor(sf::Color::White);

	m_type = type;
}

Field::~Field()
{

}

void Field::entreeClavier(char caractere)
{
	if (estUneEntreeValide(caractere))
		m_text.setString(m_text.getString() + sf::String(caractere));

}

bool Field::estUneEntreeValide(char caractere)
{
	switch (m_type)
	{
	case TypeField::NUMERIC :
		if (caractere - '0' >= 0 && '9' - caractere >= 0)
			return true;
		else
			return false;
	case TypeField::TEXT :
		if ((caractere - 'a' >= 0 && 'z' - caractere >= 0) ||
			(caractere - 'A' >= 0 && 'Z' - caractere >= 0))
			return true;
		else
			return false;
	}
}

sf::RectangleShape* Field::getRectangleShape()
{
	return &m_shapeField;
}

sf::Text* Field::getText()
{
	return &m_text;
}