#include"header.h"

void carre_haut_droite(int position_x, int position_y){
	for(int i=0; i<4; i++){
		for(int i=0; i<4; i++){
			if(grille[position_x - i][position_y + j] == grille[position_x][position_y]){
				grille[position_x - i][position_y + j] = ' ';
			}
		}
	}
}