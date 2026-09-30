#ifndef BLOKUS_PIECE_H
#define BLOKUS_PIECE_H

class Piece
{
private:
	// Q2. Créer un conteneur de coordonnées

public:
	// Q2. Créer un constructeur prenant des coordonnées en paramètres

};

/* Q2. Définir les opérateurs < et == définissant un ordre total sur les
 * instances de Piece (on en aura besoin pour les comparer entre elles pour
 * certains algorithmes et structures de données).
 *
 * Avec les deux opérateurs < et ==, vous pouvez définir les autres opérateurs
 * de comparaison très simplement :
 *
 * bool operator!=(const Piece& p1, const Piece& p2) {
 * 	return !(p1 == p2);
 * }
 * bool operator<=(const Piece& p1, const Piece& p2) {
 * 	return (p1 < p2) || (p1 == p2);
 * }
 * bool operator>(const Piece& p1, const Piece& p2) {
 * 	return !(p1 < p2) && !(p1 == p2);
 * }
 * bool operator>=(const Piece& p1, const Piece& p2) {
 * 	return !(p1 < p2) || (p1 == p2);
 * }
 */

#endif // BLOKUS_PIECE_H
