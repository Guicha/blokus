#ifndef BLOKUS_COORDINATE_H
#define BLOKUS_COORDINATE_H

#include "transformation.h"

/*
 * Dans une struct, les membres sont public par défaut tandis que dans une
 * classe, ils sont private par défaut. Ici, on n'applique pas le principe
 * d'encapsulation à la structure Coordinate, ses attributs x et y constituent
 * directement son interface publique.
 */
struct Coordinate
{
	int x;
	int y;

	Coordinate operator*(Transformation transformation) const;
	Coordinate& operator*=(Transformation transformation);
	Coordinate operator+(const Coordinate& translation) const;
	Coordinate& operator+=(const Coordinate& translation);
};

bool operator<(const Coordinate& c1, const Coordinate& c2);
bool operator>(const Coordinate& c1, const Coordinate& c2);
bool operator<=(const Coordinate& c1, const Coordinate& c2);
bool operator>=(const Coordinate& c1, const Coordinate& c2);
bool operator==(const Coordinate& c1, const Coordinate& c2);
bool operator!=(const Coordinate& c1, const Coordinate& c2);

#endif //BLOKUS_COORDINATE_H
