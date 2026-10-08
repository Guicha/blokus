#include <iostream>
#include <vector>
#include "game.h"
#include "color.h"
#include "text_interface.h"

int main()
{
	TextInterface ui{std::cin, std::cout};

	// Création de la partie
	Game g{ui};

	ui.getMessageOutput() << "Début de la partie\n";

	// Boucle principale du jeu
	const Color colors[4] = {Blue, Yellow, Red, Green};

	bool someonePlayed = true;
	while (someonePlayed) {
		someonePlayed = false;

		for (Color color : colors) {
			int before = g.remainingPieces(color);

			// playTurn vérifie lui-même si le joueur peut jouer : s'il ne
			// peut pas, il affiche un message et passe son tour
			g.playTurn(color);

			// S'il lui reste moins de pièces qu'avant, il a réellement joué
			if (g.remainingPieces(color) < before) {
				someonePlayed = true;
			}
		}
	}

	ui.getMessageOutput() << "La partie est terminée\n";

	// Afficher le score des joueurs
	const char* names[4] = {"Bleu", "Jaune", "Rouge", "Vert"};
	for (int i = 0; i < 4; i++) {
		ui.getMessageOutput() << "Score " << names[i] << " : "
		                      << g.computeScore(colors[i]) << "\n";
	}

	std::vector<Color> winners = g.winners();
	if (winners.size() == 1) {
		ui.getMessageOutput() << "Vainqueur : " << winners[0] << "\n";
	} else {
		ui.getMessageOutput() << "Égalité entre : ";
		for (size_t i = 0 ; i < winners.size() ; i++) {
			if (i > 0)
				ui.getMessageOutput() << ", ";
			ui.getMessageOutput() << winners[i];
		}
		ui.getMessageOutput() << "\n";
	}

	return 0;
}
