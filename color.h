#ifndef BLOKUS_COLOR_H
#define BLOKUS_COLOR_H

#include <ostream>

enum Color{
    Empty,
    Blue,
    Yellow,
    Red,
    Green
};

//Logique de couleur utilisé initialement dans text_interface.cpp, également utilisé dans le menu de séléction
inline const char* colorCode(Color c) {
    switch (c) {
        case Blue:   return "\033[34m";
        case Yellow: return "\033[33m";
        case Red:    return "\033[31m";
        case Green:  return "\033[32m";
        default:     return "\033[0m";
    }
}

inline const char* colorName(Color c) {
    switch (c) {
        case Blue:   return "Bleu";
        case Yellow: return "Jaune";
        case Red:    return "Rouge";
        case Green:  return "Vert";
        default:     return "Vide";
    }
}

// Affiche le nom du joueur ("Bleu", "Jaune"...) dans la couleur du joueur
inline std::ostream& operator<<(std::ostream& os, Color c) {
    return os << colorCode(c) << colorName(c) << "\033[0m";
}

#endif //BLOKUS_COLOR_H
