#include <iostream>
#include <map>

//#include "game.h"
//#include "color.h"
#include "text_interface.h"

int main()
{
	// Création des joueurs (vous puvez changer les noms)
	/*
	std::map<Color, std::string> players{
		{Color::Blue, "Myrtille"},
		{Color::Yellow, "Citron"},
		{Color::Red, "Cerise"},
		{Color::Green, "Kiwi"}
	};
	*/

	TextInterface ui{std::cin, std::cout};
	// Créer une partie
	//Game g{ui, /* ... */ };

	ui.getMessageOutput() << "Début de la partie\n";
	// Afficher le tableau
	ui.displayBoard(g.getBoard());

	// Boucle principale du jeu
	while (/* le jeu n'est pas fini */) {
		// Passer au tour suivant

		// Pour chaque joueur :
		// - afficher le tableau
		// - tester si le joueur peut jouer
		// - demander au joueur de jouer (lui demander une pièce, une
		// orientation et une position)
	}

	ui.getMessageOutput() << "La partie est terminée\n";

	// Afficher le score des joueurs
}
