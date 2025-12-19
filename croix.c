#include<stdio.h>
#include<random.h>
#include<stdlib.h>
#include<time.h>

bool croix(int position_x, int position_y){
	if(ligne_haut(position_x, position_y, 4) && 
	ligne_bas(position_x, position_y, 4) &&
	ligne_droite(position_x, position_y, 4) &&
	ligne_gauche(position_x, position_y, 4))
	{
		destruction_croix();
		return 1;
	}
	return 0;
}