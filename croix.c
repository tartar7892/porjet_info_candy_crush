#include<stdio.h>
#include<random.h>
#include<stdlib.h>
#include<time.h>

bool croix(int position_x, int position_y, int taille_ligne, int taille_colonne, int grille[taille_ligne][taille_colonne]){
	if(ligne_haut(position_x, position_y, 4) && 
	ligne_bas(position_x, position_y, 4) &&
	ligne_droite(position_x, position_y, 4) &&
	ligne_gauche(position_x, position_y, 4))
	{
		destruction_croix(position_x, position_y, taille_ligne, taille_colonne, grille);
		return 1;
	}
	return 0;
}