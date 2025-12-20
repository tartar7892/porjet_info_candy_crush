#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>




int echanger_positions(char grille[TAILLE_LIGNE][TAILLE_COLONNE],
                       int x1, int y1, int x2, int y2)
{
    if (grille[x1][y1] == '#' || grille[x2][y2] == '#')
        return 0;

    if ((x1 == x2 && (y1 == y2 + 1 || y1 == y2 - 1)) ||
        (y1 == y2 && (x1 == x2 + 1 || x1 == x2 - 1)))
    {
        char temp = grille[x1][y1];
        grille[x1][y1] = grille[x2][y2];
        grille[x2][y2] = temp;
        return 1;
    }
    return 0;
}
