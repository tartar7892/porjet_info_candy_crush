#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>
void boucle_curseur(char grille[TAILLE_LIGNE][TAILLE_COLONNE]) {
    int curseur_x = (TAILLE_LIGNE - 1) / 2;
    int curseur_y = (TAILLE_COLONNE - 1) / 2;
    int sel_x = -1;
    int sel_y = -1;

    while (1) {
        afficher_grille(grille, curseur_x, curseur_y, sel_x, sel_y);
        char touche = getch();

        if (touche == 'q' || touche == 'Q')
            break;

        if (touche == ' ') {
            if (sel_x != -1 && sel_y != -1) {

                if (echanger_positions(grille, sel_x, sel_y, curseur_x, curseur_y)) {

                    while (1) {
                        int detruit = detruire_tout(grille);
                        if (!detruit)
                            break;

                        gravite();
                        remplissage(grille);
                    }

                    sel_x = sel_y = -1;
                } else {
                    sel_x = sel_y = -1;
                }

            } else {
                sel_x = curseur_x;
                sel_y = curseur_y;
            }
        }

        if (touche == -32 || touche == 0) {
            touche = getch();
            if (touche == 72 && curseur_x > 0) curseur_x--;
            if (touche == 80 && curseur_x < TAILLE_LIGNE - 1) curseur_x++;
            if (touche == 75 && curseur_y > 0) curseur_y--;
            if (touche == 77 && curseur_y < TAILLE_COLONNE - 1) curseur_y++;
        }
    }
}
