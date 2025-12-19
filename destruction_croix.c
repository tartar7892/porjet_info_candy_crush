#include"header.h"

void destruction_croix(int position_x, int position_y){
	for(int i=0; i<taille_ligne; i++){
		if(grille[i][position_y] == grille[position_x][position_y]){
			grille[i][position_y] = ' ';
		}
	}
	
	for(int i=0; i<taille_colonne; i++){
		if(grille[position_x][i] == grille[position_x][position_y]){
			grille[position_x][i] = ' ';
		}
	}
}