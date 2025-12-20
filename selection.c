#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>
int boucle_curseur(char grille[TAILLE_LIGNE][TAILLE_COLONNE], int *score,
                   int *curseur_x, int *curseur_y, int *sel_x, int *sel_y)
{
    if (!_kbhit())
        return 0;

    char touche = getch();

    if (touche == 'q' || touche == 'Q')
        return 1;

    if (touche == 's' || touche == 'S')
        return 3;

    if (touche == ' ') {
        if (*sel_x != -1) {
            if (echanger_positions(grille, *sel_x, *sel_y, *curseur_x, *curseur_y)) {
                int combo = 0;
                while (1) {
                    int avant = 0;
                    for (int i = 0; i < TAILLE_LIGNE; i++)
                        for (int j = 0; j < TAILLE_COLONNE; j++)
                            if (grille[i][j] != ' ' && grille[i][j] != '#')
                                avant++;

                    int detruit = detruire_tout(grille);
                    if (!detruit)
                        break;

                    int apres = 0;
                    for (int i = 0; i < TAILLE_LIGNE; i++)
                        for (int j = 0; j < TAILLE_COLONNE; j++)
                            if (grille[i][j] != ' ' && grille[i][j] != '#')
                                apres++;

                    int nb = avant - apres;
                    combo++;
                    int bonus = (combo - 1) * 2;
                    *score += nb + bonus;

                    gravite();
                    remplissage(grille);
                }
                *sel_x = *sel_y = -1;
            } else {
                *sel_x = *sel_y = -1;
            }
        } else {
            *sel_x = *curseur_x;
            *sel_y = *curseur_y;
        }
        return 1;
    }

    if (touche == -32 || touche == 0) {
        touche = getch();
        int moved = 0;

        if (touche == 72 && *curseur_x > 0) { (*curseur_x)--; moved = 1; }
        if (touche == 80 && *curseur_x < TAILLE_LIGNE - 1) { (*curseur_x)++; moved = 1; }
        if (touche == 75 && *curseur_y > 0) { (*curseur_y)--; moved = 1; }
        if (touche == 77 && *curseur_y < TAILLE_COLONNE - 1) { (*curseur_y)++; moved = 1; }

        if (moved)
            return 2;
    }

    return 0;
}
