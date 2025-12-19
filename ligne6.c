#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#include"ligne_bas.c"
#include"ligne_haut.c"
#include"ligne_gauche.c"
#include"ligne_droite.c"

#include"ligne6_destruction.c"

bool ligne6(int position_x, int position_y){
	if(ligne_haut(position_x, position_y, 6)
	|| ligne_bas(position_x, position_y, 6)
	|| ligne_droite(position_x, position_y, 6)
	|| ligne_gauche(position_x, position_y, 6)){
		
		ligne6_destruction(position_x, position_y);
		return 1;
	}
	return 0;
}
