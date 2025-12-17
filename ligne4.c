#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

bool ligne_4(int position_x, int position_y){
	if(ligne_haut(position_x, position_y, 4)){
		return 1;
	}
	if(ligne_bas(position_x, position_y, 4)){
		return 1;
	}
	if(ligne_droite(position_x, position_y, 4)){
		return 1;
	}
	if(ligne_gauche(position_x, position_y, 4)){
		return 1;
	}
	return 0;
}