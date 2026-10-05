#ifndef BLOKUS_PIECE_H
#define BLOKUS_PIECE_H

#include "coordinate.h"
#include <vector>

class Piece
{
private:
	// Q2. Créer un conteneur de coordonnées
	std::vector<Coordinate> squares;

public:
	// Q2. Créer un constructeur prenant des coordonnées en paramètres
	Piece(const std::initializer_list<Coordinate>&& squares);
	std::vector<Coordinate>& getSquares();
	void setSquares(std::vector<Coordinate> newSquares);
	
	std::vector<Coordinate>::iterator begin();
	std::vector<Coordinate>::iterator end();

	//permet un parcours en read only d'un objet `const Piece&` (utilisé par `TextInterface')
	std::vector<Coordinate>::const_iterator begin() const;
	std::vector<Coordinate>::const_iterator end() const;

	friend bool operator<(const Piece& p1, const Piece& p2);
	friend bool operator==(const Piece& p1, const Piece& p2);
};

/* Q2. Définir les opérateurs < et == définissant un ordre total sur les
 * instances de Piece (on en aura besoin pour les comparer entre elles pour
 * certains algorithmes et structures de données).
 *
 * Avec les deux opérateurs < et ==, vous pouvez définir les autres opérateurs
 * de comparaison très simplement :
 *
 */
bool operator!=(const Piece& p1, const Piece& p2);
bool operator<=(const Piece& p1, const Piece& p2);
bool operator>(const Piece& p1, const Piece& p2);
bool operator>=(const Piece& p1, const Piece& p2);

#endif // BLOKUS_PIECE_H
