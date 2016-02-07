#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Game.h"
#include "TextureManager.h"
#include "AnimationManager.h"


/*
to do :
important : ajouter un sprite au competence et le placer(setPosition) dans les classes

-Implementer 5 types de vaisseaux ennemis
-faire un menu classique
-ameliorer la phase de jeu exploration (revoir les decors)
-ajouter 1 decors et 2 decors mobiles
-creer l'aternance entre phase de combat et phase d'exploration

Graphique :
-refaire les tirs (plus visibles)
-faire les competences speciales
-faire un autre background
-faire les 5 vaisseaux ennemis
-faire les animations du vaisseau quand il tourne
*/

int main()
{
	//création de la fenetre
	sf::RenderWindow window(sf::VideoMode(1200, 725), "PROJET Shoot them all");
	window.setFramerateLimit(100);

	//chargement des textures
	TextureManager textureManager;
	AnimationManager animationManager(&textureManager);
	sf::Clock clock;

	while (window.isOpen())
	{
		//création de la partie
		Game game(&window, textureManager, animationManager);

		//Timer pour gérer la vitesse des frames
		float tempsPasse = 1;

		//boucle gestion fenetre
		while (game.gameLoop(clock))
		{
			
		}
	}

	return 0;
}

