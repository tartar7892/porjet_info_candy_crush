#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>


void jouer_niveau(int n) {
    niveau = n;
    int score = 0;
    int objectif;

    if (n == 1) objectif = 50;
    if (n == 2) objectif = 120;
    if (n == 3) objectif = 200;

    int minutes = 3;
    int secondes = 0;

    initialiser_grille(grille);

    while (minutes > 0 || secondes > 0) {

        afficher_grille(grille, 0, 0, -1, -1);
        afficher_score(score);
        printf("Objectif : %d\n", objectif);
        printf("Temps restant : %02d:%02d\n", minutes, secondes);

        boucle_curseur(grille, &score);

        if (score >= objectif) {
            printf("\nBravo ! Niveau %d réussi !\n", n);
            return;
        }

        chrono(&minutes, &secondes);
    }

    printf("\nTemps écoulé ! Niveau %d perdu.\n", n);
}
