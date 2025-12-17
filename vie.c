#include <stdio.h>

#define VIES_MAX 3

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

int main(){
	int vies = VIES_MAX;
	
	afficher(vies);
	return 0;
}