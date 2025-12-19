#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"ligne_bas.c"
#include"ligne_haut.c"
#include"ligne_gauche.c"
#include"ligne_droite.c"

bool croix(int position_x, int position_y){
	if(ligne_haut(position_x, position_y, 4) && 
	ligne_bas(position_x, position_y, 4) &&
	ligne_droite(position_x, position_y, 4) &&
	ligne_gauche(position_x, position_y, 4))
	{
		destruction_croix(position_x, position_y);
		return 1;
	}
	return 0;
}