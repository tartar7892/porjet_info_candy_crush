#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

char grille[TAILLE_LIGNE][TAILLE_COLONNE];
int niveau = 1;

int main() {

    srand(time(NULL));

    jouer_niveau(3);

    return 0;
}
