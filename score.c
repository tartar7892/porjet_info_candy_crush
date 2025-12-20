#include <stdio.h>

// Affiche le score actuel
void afficher_score(int score) {
    printf("Score: %d\n", score);
}

// Met à jour le score en fonction du nombre de bonbons détruits
void mettre_a_jour_score(int *score, int bonbons_detruits) {
    if (bonbons_detruits > 0) {
        *score += bonbons_detruits;
        printf("+ %d points! Score total: %d\n", bonbons_detruits, *score);
    }
}