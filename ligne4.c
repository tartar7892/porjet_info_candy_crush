#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#include"ligne4_bas_dest.c"
#include"ligne4_haut_dest.c"
#include"ligne4_gauche_dest.c"
#include"ligne4_droite_dest.c"

bool ligne_4(int position_x, int position_y, int taille_ligne, int taille_colonne, int grille[taille_ligne][taille_colonne]){
	if(ligne_haut(position_x, position_y, 4)){
		ligne4_haut_dest();
		return 1;
	}
	if(ligne_bas(position_x, position_y, 4)){
		ligne4_bas_dest();
		return 1;
	}
	if(ligne_droite(position_x, position_y, 4)){
		ligne4_droite_dest();
		return 1;
	}
	if(ligne_gauche(position_x, position_y, 4)){
		ligne4_gauche_dest();
		return 1;
	}
	return 0;
}