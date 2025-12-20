#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>


void jouer_niveau(int n) {
    niveau = n;
    printf("\n=== LANCEMENT DU NIVEAU %d ===\n", n);

    initialiser_grille(grille);

    boucle_curseur(grille);

    printf("\n=== NIVEAU %d TERMINE ===\n", n);
}
