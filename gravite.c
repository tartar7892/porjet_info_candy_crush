#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>

void gravite() {
    for (int j = 0; j < TAILLE_COLONNE; j++) {
        for (int i = TAILLE_LIGNE - 1; i >= 0; i--) {

            if (grille[i][j] == '#')
                continue;

            int k = i;
            while (k + 1 < TAILLE_LIGNE &&
                   grille[k + 1][j] == ' ')
            {
                char tmp = grille[k][j];
                grille[k][j] = grille[k + 1][j];
                grille[k + 1][j] = tmp;
                k++;
            }
        }
    }
}
