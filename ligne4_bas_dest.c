#include"header.h"

void destruction_ligne4_bas(int position_x, int position_y){
	for(int i=0; i<4; i++){
		grille[position_x + i][position_y] = ' ';
	}
}