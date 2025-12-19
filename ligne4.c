#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#include"ligne4_bas_dest.c"
#include"ligne4_haut_dest.c"
#include"ligne4_gauche_dest.c"
#include"ligne4_droite_dest.c"

#include"ligne_bas.c"
#include"ligne_haut.c"
#include"ligne_gauche.c"
#include"ligne_droite.c"

bool ligne4(int position_x, int position_y){
	if(ligne_haut(position_x, position_y, 4)){
		ligne4_haut_dest(position_x, position_y);
		return 1;
	}
	if(ligne_bas(position_x, position_y, 4)){
		ligne4_bas_dest(position_x, position_y);
		return 1;
	}
	if(ligne_droite(position_x, position_y, 4)){
		ligne4_droite_dest(position_x, position_y);
		return 1;
	}
	if(ligne_gauche(position_x, position_y, 4)){
		ligne4_gauche_dest(position_x, position_y);
		return 1;
	}
	return 0;
}