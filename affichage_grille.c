#include <stdio.h>

void afficher_grille(int lignes, int colonnes,char grille[lignes][colonnes]) {
   
    printf("  "); 
    for (int col = 0; col < colonnes; col++) {
        printf("%4d", col + 1); 
    }
    printf("\n");

    printf("   +");
    for (int col = 0; col < colonnes; col++) {
        printf("---+");
    }
    printf("\n");

    for (int lig = 0; lig < lignes; lig++) {
        
        printf("%2d |", lig + 1); 
        for (int col = 0; col < colonnes; col++) {
            printf(" %c |", grille[lig][col]);
        }
        printf("\n");

        
        printf("   +");
        for (int col = 0; col < colonnes; col++) {
            printf("---+");
        }
        printf("\n");
    }
}

int main() {
    int lignes ,colonnes;
    printf("combien de lignes voulez vous utilisé pour jouer cette partie:  ");
    scanf("%d",&lignes);
    printf("combien de colonnes voulez vous utilisé pour jouer cette partie :  ");
    scanf("%d",&colonnes);
    char grille[lignes][colonnes];

    for (int i = 0; i < lignes; i++)
        for (int j = 0; j < colonnes; j++)
            grille[i][j] = ' ';

    
    grille[0][0] = 'X';   
    grille[9][1] = 'O';  
    grille[4][4] = 'X';   

    afficher_grille(lignes,colonnes,grille);
    return 0;
}
