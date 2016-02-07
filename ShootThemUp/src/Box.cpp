#include "Box.h"

Box::Box(TypeField type, sf::Font* font, sf::Vector2f tailleTotal, sf::Vector2f position)
:	m_shapeContour(sf::Vector2f(tailleTotal.x, tailleTotal.y)),
	m_shapeValider(sf::Vector2f(tailleTotal.x /2, tailleTotal.y/6)),
	m_textField(type, position, font, tailleTotal),
	m_textValider("Valider", *font)
{
	m_retour = "";

	m_textValider.setColor(sf::Color::White);

	m_shapeContour.setFillColor(sf::Color::Blue);
	m_shapeContour.setPosition(position);
	m_shapeContour.setOutlineThickness(3);
	m_shapeContour.setOutlineColor(sf::Color::Black);

	m_shapeValider.setFillColor(sf::Color::Magenta);
	m_shapeValider.setPosition(position.x + (m_shapeContour.getGlobalBounds().width * 3 / 5), 
		position.y + (m_shapeContour.getGlobalBounds().height
		- m_shapeValider.getGlobalBounds().height) / 2);
}

Box::~Box()
{

}

sf::RectangleShape* Box::getShapeTotal()
{
	return &m_shapeContour;
}

/** TO DO !

bool Box::traitementEvent(sf::Event & event, sf::RenderWindow* window)
{
	if (event.type == sf::Event::TextEntered && estSelectionne)
	{
		if(event.text.unicode < 128 && event.text.unicode != 13 && event.text.unicode != 8 && event.text.unicode != 9)
			m_textField.entreeClavier(static_cast<char>(event.text.unicode));
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		//sur le textField
		if (m_textField.getRectangleShape()->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).x)))
		{
			m_estSelectionne = true;
			m_shapeContour.setOutlineColor(sf::Color::White);

		}

		else if (m_shapeValider.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).x)))
		{
			m_retour = m_textField.getText()->getString();
			return true;
		}

		m_estSelectionne = false;
		m_shapeContour.setOutlineColor(sf::Color::Black);
	}
	

}
*/

void Box::draw(sf::RenderWindow* window)
{
	window->draw(m_shapeContour);
	window->draw(*m_textField.getRectangleShape());
	window->draw(m_shapeValider);
}