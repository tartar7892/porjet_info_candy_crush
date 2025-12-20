#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>

char carac(int choix) {
    switch (choix) {
        case 1: return 'V';
        case 2: return 'O';
        case 3: return 'I';
        case 4: return 'X';
        case 5: return 'R';
        case 6: return 'B';
        case 7: return 'M';
        default: return ' ';
    }
}
int generation() {
    if (niveau == 1) return rand() % 4 + 1;
    if (niveau == 2) return rand() % 7 + 1;
    if (niveau == 3) return rand() % 7 + 1;
    return 1;
}

void remplissage(char grille[TAILLE_LIGNE][TAILLE_COLONNE]) {
	for (int i = 0; i < TAILLE_LIGNE; i++) {
		for (int j = 0; j < TAILLE_COLONNE; j++) {
			if (grille[i][j] == ' ') {
				grille[i][j] = carac(generation());
			}
		}
	}
}
void print_colored(char c) {
    switch (c) {
        case 'V': printf("\033[32mV\033[0m"); break;
        case 'O': printf("\033[33mO\033[0m"); break;
        case 'I': printf("\033[34mI\033[0m"); break;
        case 'X': printf("\033[31mX\033[0m"); break;
        case 'R': printf("\033[35mR\033[0m"); break;
        case 'B': printf("\033[37mB\033[0m"); break;
        case 'M': printf("\033[90mM\033[0m"); break;
        default:  printf(" "); break;
    }
}
