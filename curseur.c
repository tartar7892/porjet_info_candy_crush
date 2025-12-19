#include <stdio.h>
#include <conio.h>  

void afficher_curseur(int lignes, int colonnes, char grille[lignes][colonnes], 
                     int curseur_x, int curseur_y, int sel_x, int sel_y) {
    int i, j;
    
    printf("\033[2J\033[H");  
    
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            if (i == curseur_x && j == curseur_y) {
                printf("\033[47m\033[30m %c \033[0m", grille[i][j]);  
            } else if (sel_x != -1 && i == sel_x && j == sel_y) {
                printf("\033[42m\033[30m %c \033[0m", grille[i][j]);  
            } else {
                printf(" %c ", grille[i][j]);  
            }
        }
        printf("\n");
    }
    
    printf("\nFleches = deplacer | ESPACE = selectionner | Q = quitter\n");
    if (sel_x != -1) {
        printf("Bonbon selectionne: %c a la position (%d, %d)\n", grille[sel_x][sel_y], sel_x, sel_y);
    }
}

void deplacer_curseur(int lignes, int colonnes, char grille[lignes][colonnes], 
                     int *curseur_x, int *curseur_y, int *sel_x, int *sel_y) {
    char touche;
    
    afficher_curseur(lignes, colonnes, grille, *curseur_x, *curseur_y, *sel_x, *sel_y);
    
    touche = getch();
    
    if (touche == 'q' || touche == 'Q') {
        return;
    }
    
    // ESPACE pou 
    if (touche == ' ') {
        if (*sel_x == *curseur_x && *sel_y == *curseur_y) {
            // Désélectionner si on clique sur la même case
            *sel_x = -1;
            *sel_y = -1;
        } else {
            // Sélectionner
            *sel_x = *curseur_x;
            *sel_y = *curseur_y;
        }
    }
    
    // Flèches
    if (touche == -32 || touche == 0) {
        touche = getch();
        if (touche == 72 && *curseur_x > 0) (*curseur_x)--;
        if (touche == 80 && *curseur_x < lignes - 1) (*curseur_x)++;
        if (touche == 75 && *curseur_y > 0) (*curseur_y)--;
        if (touche == 77 && *curseur_y < colonnes - 1) (*curseur_y)++;
    }
}
int main() {
    int lignes = 5;
    int colonnes = 5;
    char grille[5][5] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'J'},
        {'K', 'L', 'M', 'N', 'O'},
        {'P', 'Q', 'R', 'S', 'T'},
        {'U', 'V', 'W', 'X', 'Y'}
    };
    
    int curseur_x = 0, curseur_y = 0;
    int sel_x = -1, sel_y = -1;
    
    while (1) {
        deplacer_curseur(lignes, colonnes, grille, &curseur_x, &curseur_y, &sel_x, &sel_y);
    }
    
    return 0;
}