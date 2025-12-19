#include"header.h"

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