#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>


bool ligne_haut(int x, int y, int len) {
    if (grille[x][y] == '#') return 0;
    if (x - (len - 1) < 0) return 0;
    for (int i = 1; i < len; i++)
        if (grille[x - i][y] != grille[x][y]) return 0;
    return 1;
}
bool ligne_bas(int x, int y, int len) {
    if (grille[x][y] == '#') return 0;
    if (x + (len - 1) >= TAILLE_LIGNE) return 0;
    for (int i = 1; i < len; i++)
        if (grille[x + i][y] != grille[x][y]) return 0;
    return 1;
}

bool ligne_gauche(int x, int y, int len) {
    if (grille[x][y] == '#') return 0;
    if (y - (len - 1) < 0) return 0;
    for (int i = 1; i < len; i++)
        if (grille[x][y - i] != grille[x][y]) return 0;
    return 1;
}


bool ligne_droite(int x, int y, int len) {
    if (grille[x][y] == '#') return 0;
    if (y + (len - 1) >= TAILLE_COLONNE) return 0;
    for (int i = 1; i < len; i++)
        if (grille[x][y + i] != grille[x][y]) return 0;
    return 1;
}

bool ligne6(int x, int y) {
    if (grille[x][y] == '#') return 0;

    if (ligne_haut(x, y, 6) ||
        ligne_bas(x, y, 6) ||
        ligne_gauche(x, y, 6) ||
        ligne_droite(x, y, 6)) {
        ligne6_destruction(x, y);
        return 1;
    }
    return 0;
}

bool ligne4(int x, int y) {
    if (grille[x][y] == '#') return 0;

    if (ligne_haut(x, y, 4)) { destruction_ligne4_haut(x, y); return 1; }
    if (ligne_bas(x, y, 4)) { destruction_ligne4_bas(x, y); return 1; }
    if (ligne_droite(x, y, 4)) { destruction_ligne4_droite(x, y); return 1; }
    if (ligne_gauche(x, y, 4)) { destruction_ligne4_gauche(x, y); return 1; }

    return 0;
}

bool carree(int x, int y) {
    if (grille[x][y] == '#') return 0;

    if (x + 3 < TAILLE_LIGNE &&
        ligne_haut(x + 3, y, 4) &&
        ligne_haut(x, y, 4) &&
        ligne_droite(x, y + 3, 4) &&
        ligne_droite(x, y, 4))
        return 1;

    if (x + 3 < TAILLE_LIGNE &&
        ligne_bas(x - 3, y, 4) &&
        ligne_bas(x, y, 4) &&
        ligne_droite(x, y + 3, 4) &&
        ligne_droite(x, y, 4))
        return 1;

    if (x + 3 < TAILLE_LIGNE &&
        ligne_haut(x + 3, y, 4) &&
        ligne_haut(x, y, 4) &&
        ligne_gauche(x, y - 3, 4) &&
        ligne_gauche(x, y, 4))
        return 1;

    if (x + 3 < TAILLE_LIGNE &&
        ligne_bas(x - 3, y, 4) &&
        ligne_bas(x, y, 4) &&
        ligne_gauche(x, y - 3, 4) &&
        ligne_gauche(x, y, 4))
        return 1;

    return 0;
}
bool croix(int x, int y) {
    if (grille[x][y] == '#') return 0;

    if (ligne_haut(x, y, 4) &&
        ligne_bas(x, y, 4) &&
        ligne_droite(x, y, 4) &&
        ligne_gauche(x, y, 4)) {
        destruction_croix(x, y);
        return 1;
    }
    return 0;
}
