#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>
void afficher(int vies) {
    int i;
    printf("Vies: ");
    for (i = 0; i < VIES_MAX; i++) {
        if (i < vies) {
            printf("X ");  // Rond plein
        } else {
            printf("0 ");  // Rond vide
        }
    }
    printf("\n");
}

void perdre_vie(int *vies) {
    if (*vies > 0) {
        (*vies)--;
    }
}
