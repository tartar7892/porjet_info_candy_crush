#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>

int interface_niveau(int n, const char *pseudo, int minutes, int secondes, int score, int vies) {
    niveau = n;
    int objectif = (n == 1 ? 50 : n == 2 ? 120 : 200);
    int curseur_x = 0, curseur_y = 0;
    int sel_x = -1, sel_y = -1;

    initialiser_grille(grille);

    while (vies > 0) {
        int maj_temps = chrono(&minutes, &secondes);
        int action = boucle_curseur(grille, &score, &curseur_x, &curseur_y, &sel_x, &sel_y);

        if (action == 3) {
            if (demander_sauvegarde()) {
                sauvegarder_partie(pseudo, n, minutes, secondes, score, vies);
                return -1;
            }
        }

        if (maj_temps || action != 0) {
            system("cls");
            afficher_grille(grille, curseur_x, curseur_y, sel_x, sel_y);
            afficher_interface(minutes, secondes, vies, score, objectif);
        }

        if (score >= objectif) {
            if (n == 3) {
                system("cls");
                printf("\n=============================================\n");
                printf("   FELICITATIONS %s !!!\n", pseudo);
                printf("   Vous avez termine les 3 niveaux du jeu !\n");
                printf("=============================================\n");
                printf("\n---------------------------------------------\n");
                printf("  Appuyez sur ESPACE pour revenir au menu...\n");
                printf("---------------------------------------------\n");
                char c = 0;
                while (c != ' ') c = getch();
                return -1;
            }
            attendre_espace(pseudo, n);
            return n + 1;
        }

        if (minutes == 0 && secondes == 0) {
            perdre_vie(&vies);
            if (vies > 0) {
                minutes = 3;
                secondes = 0;
                initialiser_grille(grille);
            }
        }
    }

    return -1;
}


void afficher_interface(int minutes, int secondes, int vies, int score, int objectif) {
    printf("Temps restant : %02d:%02d\n", minutes, secondes);
    afficher(vies);
    printf("Score : %d\n", score);
    printf("Objectif : %d\n\n", objectif);
}

void attendre_espace(const char *pseudo, int n) {
    system("cls");
    printf("\n=============================================\n");
    printf("   Bravo %s ! Vous avez termine le niveau %d !\n", pseudo, n);
    printf("=============================================\n");
    printf("\nPassage au niveau suivant...\n");
    printf("\n---------------------------------------------\n");
    printf("  Appuyez sur ESPACE pour continuer...\n");
    printf("---------------------------------------------\n");
    char c = 0;
    while (c != ' ') c = getch();
}



