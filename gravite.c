#include"header.h"

void gravite() {
    for (int i = 0; i < taille_colonne; i++) {
        int position_cible = taille_ligne - 1;
        for (int j = taille_ligne - 1; j >= 0; j--) {
            if (grille[j][i] != ' ') {
                grille[position_cible][i] = grille[j][i];
                if (position_cible != j) {
                    grille[j][i] = ' ';
                }
                position_cible--;
            }
        }
        for (int j = position_cible; j >= 0; j--) {
            grille[j][i] = ' ';
        }
    }
}
