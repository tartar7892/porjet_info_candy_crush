#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>

void ligne6_destruction(int position_x, int position_y){
    char rune = grille[position_x][position_y];

    for(int i = 0; i < TAILLE_LIGNE; i++){
        for(int j = 0; j < TAILLE_COLONNE; j++){
            if(grille[i][j] == rune){
                grille[i][j] = ' ';
            }
        }
    }
}

void destruction_ligne4_haut(int position_x, int position_y){
    if(position_x - 3 < 0) return;

    for(int i = 0; i < 4; i++){
        grille[position_x - i][position_y] = ' ';
    }
}

void destruction_ligne4_gauche(int position_x, int position_y){
    if(position_y - 3 < 0) return;

    for(int i = 0; i < 4; i++){
        grille[position_x][position_y - i] = ' ';
    }
}

void destruction_ligne4_droite(int position_x, int position_y){
    if(position_y + 3 >= TAILLE_COLONNE) return;

    for(int i = 0; i < 4; i++){
        grille[position_x][position_y + i] = ' ';
    }
}

void destruction_ligne4_bas(int position_x, int position_y){
    if(position_x + 3 >= TAILLE_LIGNE) return;

    for(int i = 0; i < 4; i++){
        grille[position_x + i][position_y] = ' ';
    }
}

void destruction_croix(int position_x, int position_y){
    char rune = grille[position_x][position_y];


    for(int i = 0; i < TAILLE_LIGNE; i++){
        if(grille[i][position_y] == rune){
            grille[i][position_y] = ' ';
        }
    }

    for(int j = 0; j < TAILLE_COLONNE; j++){
        if(grille[position_x][j] == rune){
            grille[position_x][j] = ' ';
        }
    }
}

int detruire_tout(char grille[TAILLE_LIGNE][TAILLE_COLONNE]) {
    int destruction = 0;

    for (int i = 0; i < TAILLE_LIGNE; i++) {
        for (int j = 0; j < TAILLE_COLONNE; j++) {

            if (grille[i][j] == ' ' || grille[i][j] == '#')
                continue;

            if (ligne6(i, j) ||
                ligne4(i, j) ||
                carree(i, j) ||
                croix(i, j)) {
                destruction = 1;
            }
        }
    }

    return destruction;
}
