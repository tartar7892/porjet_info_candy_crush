#include <stdio.h>


void echanger(int lignes, int colonnes, char grille[lignes][colonnes]) {
    int x1, y1, x2, y2;
    char temp;
    
    printf("Premier bonbon (ligne colonne): ");
    scanf("%d %d", &x1, &y1);
    x1--; y1--;  
    
    printf("Deuxieme bonbon (ligne colonne): ");
    scanf("%d %d", &x2, &y2);
    x2--; y2--;
    
    
    if ((x1 == x2 && (y1 == y2 + 1 || y1 == y2 - 1)) || (y1 == y2 && (x1 == x2 + 1 || x1 == x2 - 1))) {
        
        
        temp = grille[x1][y1];
        grille[x1][y1] = grille[x2][y2];
        grille[x2][y2] = temp;//echange de bonbon
        
        printf("Echange OK!\n");
    } else {
        printf("Bonbons pas colles!\n");
    }
}