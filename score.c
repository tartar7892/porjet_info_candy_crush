#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>


void afficher_score(int score) {
    printf("Score: %d\n", score);
}


void mettre_a_jour_score(int *score, int bonbons_detruits) {
    if (bonbons_detruits > 0) {
        *score += bonbons_detruits;
        printf("+ %d points! Score total: %d\n", bonbons_detruits, *score);
    }
}
