#include <stdio.h>

#define LIGNES 4
#define COLONNES 4

void afficher_grille(char grille[LIGNES][COLONNES]) {
    for (int i = 0; i < LIGNES; i++) {
        // Ligne horizontale
        for (int j = 0; j < COLONNES; j++) {
            printf("+---");
        }
        printf("+\n");

        // Ligne avec contenu
        for (int j = 0; j < COLONNES; j++) {
            printf("| %c ", grille[i][j]);
        }
        printf("|\n");
    }

    // Dernière ligne horizontale
    for (int j = 0; j < COLONNES; j++) {
        printf("+---");
    }
    printf("+\n");
}
int main() {
    char grille[LIGNES][COLONNES];

    // Initialisation à vide
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            grille[i][j] = ' '; // case vide
        }
    }

    // Exemple de remplissage
    grille[0][0] = 'X';
    grille[1][2] = 'O';
    grille[3][3] = 'X';

    afficher_grille(grille);

    return 0;
}