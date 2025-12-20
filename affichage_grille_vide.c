#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>
void afficher_grille(char grille[TAILLE_LIGNE][TAILLE_COLONNE],
                     int curseur_x, int curseur_y,
                     int sel_x, int sel_y)
{
    printf("\033[2J\033[H"); // Efface l'écran

    // Numéros de colonnes
    printf("  ");
    for (int col = 0; col < TAILLE_COLONNE; col++) {
        printf("%4d", col + 1);
    }
    printf("\n");

    // Ligne du haut
    printf("   +");
    for (int col = 0; col < TAILLE_COLONNE; col++) {
        printf("---+");
    }
    printf("\n");

    // Corps de la grille
    for (int lig = 0; lig < TAILLE_LIGNE; lig++) {

        printf("%2d |", lig + 1);

        for (int col = 0; col < TAILLE_COLONNE; col++) {

            // Curseur
            if (lig == curseur_x && col == curseur_y) {
                printf("\033[47m\033[30m ");
                print_colored(grille[lig][col]);
                printf(" \033[0m|");
            }
            // Sélection
            else if (sel_x != -1 && lig == sel_x && col == sel_y) {
                printf("\033[42m\033[30m ");
                print_colored(grille[lig][col]);
                printf(" \033[0m|");
            }
            // Case normale
            else {
                printf(" ");
                print_colored(grille[lig][col]);
                printf(" |");
            }
        }

        printf("\n   +");
        for (int col = 0; col < TAILLE_COLONNE; col++) {
            printf("---+");
        }
        printf("\n");
    }

    printf("\nFleches = deplacer | ESPACE = selectionner | Q = quitter\n");

    if (sel_x != -1) {
        printf("Bonbon selectionne : ");
        print_colored(grille[sel_x][sel_y]);
        printf(" en (%d, %d)\n", sel_x, sel_y);
    }
}
void initialiser_grille(char grille[TAILLE_LIGNE][TAILLE_COLONNE]) {
    for (int i = 0; i < TAILLE_LIGNE; i++) {
        for (int j = 0; j < TAILLE_COLONNE; j++) {
            grille[i][j] = carac(generation());
        }
    }

    if (niveau == 3) {
        for (int k = 0; k < 10; k++) {
            int x = rand() % TAILLE_LIGNE;
            int y = rand() % TAILLE_COLONNE;
            grille[x][y] = '#';
        }
    }
}
