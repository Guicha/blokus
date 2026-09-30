#ifndef BLOKUS_PIECES_SET_H
#define BLOKUS_PIECES_SET_H

#if 0
/*
 * Liste des coordonnées de chaque pièce, selon la figure 3 du sujet.
 *
 * Selon les structures de données que vous choisirez, il faudra utiliser les
 * informations ci-dessous différemment.
 *
 * Ici, un objet écrit "{{0, 0}, {1, 0}}" est du type
 * std::initializer_list<Coordinate>. Il est possible d'instancier toutes les
 * collections usuelles à partir d'un objet std::initializer_list.
 */


// 1-square piece
/*
 * #
 */
{{0, 0}},

// 2-square piece
/*
 * # #
 */
{{0, 0}, {1, 0}},

// 3-square pieces
/*
 * # # #
 */
{{0, 0}, {1, 0}, {2, 0}},
/*
 * #
 * # #
 */
{{0, 0}, {1, 0}, {0, 1}},

// 4-square pieces
/*
 * # # # #
 */
{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
/*
 * # #
 * # #
 */
{{0, 0}, {1, 0}, {0, 1}, {1, 1}},
/*
 * #
 * # # #
 */
{{0, 0}, {1, 0}, {2, 0}, {0, 1}},
/*
 *   #
 * # # #
 */
{{0, 0}, {1, 0}, {2, 0}, {1, 1}},
/*
 *   # #
 * # #
 */
{{0, 0}, {1, 0}, {1, 1}, {2, 1}},

// 5-square pieces
/*
 * # # # # #
 */
{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}},
/*
 * #
 * # # # #
 */
{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {0, 1}},
/*
 *   #
 * # # # #
 */
{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {1, 1}},
/*
 * #
 * #
 * # # #
 */
{{0, 0}, {1, 0}, {2, 0}, {0, 1}, {0, 2}},
/*
 *   #
 *   #
 * # # #
 */
{{0, 0}, {1, 0}, {2, 0}, {1, 1}, {1, 2}},
/*
 *     #
 * # # #
 * #
 */
{{0, 1}, {1, 1}, {2, 1}, {0, 0}, {2, 2}},
/*
 *   #
 * # # #
 * #
 */
{{0, 1}, {1, 1}, {2, 1}, {0, 0}, {1, 2}},
/*
 *   #
 * # # #
 *   #
 */
{{0, 1}, {1, 1}, {2, 1}, {1, 0}, {1, 2}},
/*
 * # #
 * # # #
 */
{{0, 0}, {1, 0}, {2, 0}, {0, 1}, {1, 1}},
/*
 *     # #
 * # # #
 */
{{0, 0}, {1, 0}, {2, 0}, {2, 1}, {3, 1}},
/*
 *     #
 *   # #
 * # #
 */
{{0, 0}, {1, 0}, {1, 1}, {2, 1}, {2, 2}},
/*
 * #   #
 * # # #
 */
{{0, 0}, {1, 0}, {2, 0}, {0, 1}, {2, 1}}
#endif

class PiecesSet
{
private:

public:
};


#endif //BLOKUS_PIECES_SET_H
