#include<stdio.h>
#include<random.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

bool ligne_6(int position_x, int position_y){
	if(ligne_haut(position_x, position_y, 6)
	|| ligne_bas(position_x, position_y, 6)
	|| ligne_droite(position_x, position_y, 6)
	|| ligne_gauche(position_x, position_y, 6)){
		
		ligne6_destruction();
		return 1;
	}
	return 0;
}
