#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "head.h"




bool ligne_haut(int position_x, int position_y, int longueur){
	if(position_x-longueur < 0){
		return 0;
	}
	for(int i=1; i<longueur; i++){
		if(grille[position_x-i][position_y] != grille[position_x][position_y]){
			return 0;
		}
	}
	return 1;
}

bool ligne_gauche(int position_x, int position_y, int longueur){
	if(position_y-longueur < 0){
		return 0;
	}
	for(int i=1; i<longueur; i++){
		if(grille[position_x][position_y-i] != grille[position_x][position_y]){
			return 0;
		}
	}
	return 1;
}
bool ligne_droite(int position_x, int position_y, int longueur){
	if(position_y+longueur > TAILLE_COLONNE){
		return 0;
	}
	for(int i=1; i<longueur; i++){
		if(grille[position_x][position_y+i] != grille[position_x][position_y]){
			return 0;
		}
	}
	return 1;
}
bool ligne_bas(int position_x, int position_y, int longueur){
	if(position_x+longueur > TAILLE_LIGNE){
		return 0;
	}
	for(int i=1; i<longueur; i++){
		if(grille[position_x+i][position_y] != grille[position_x][position_y]){
			return 0;
		}
	}
	return 1;
}

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

bool ligne4(int position_x, int position_y){
	if(ligne_haut(position_x, position_y, 4)){
		destruction_ligne4_haut(position_x, position_y);
		return 1;
	}
	if(ligne_bas(position_x, position_y, 4)){
		destruction_ligne4_bas(position_x, position_y);
		return 1;
	}
	if(ligne_droite(position_x, position_y, 4)){
		destruction_ligne4_droite(position_x, position_y);
		return 1;
	}
	if(ligne_gauche(position_x, position_y, 4)){
		destruction_ligne4_gauche(position_x, position_y);
		return 1;
	}
	return 0;
}
bool carree(int position_x, int position_y){
	if(position_x+3<TAILLE_LIGNE &&
	ligne_haut(position_x+3, position_y, 4) &&
	ligne_haut(position_x, position_y, 4) &&
	ligne_droite(position_x, position_y+3, 4) &&
	ligne_droite(position_x, position_y, 4))
	{
		return 1;
	}// carre droite haut

	if(position_x+3<TAILLE_LIGNE &&
	ligne_bas(position_x-3, position_y, 4) &&
	ligne_bas(position_x, position_y, 4) &&
	ligne_droite(position_x, position_y+3, 4) &&
	ligne_droite(position_x, position_y, 4))
	{
		return 1;
	}//carre droite bas

	if(position_x+3<TAILLE_LIGNE &&
	ligne_haut(position_x+3, position_y, 4) &&
	ligne_haut(position_x, position_y, 4) &&
	ligne_gauche(position_x, position_y-3, 4) &&
	ligne_gauche(position_x, position_y, 4))
	{
		return 1;
	}//carre haut gauche

	if(position_x+3<TAILLE_LIGNE &&
	ligne_bas(position_x-3, position_y, 4) &&
	ligne_bas(position_x, position_y, 4) &&
	ligne_gauche(position_x, position_y-3, 4) &&
	ligne_gauche(position_x, position_y, 4))
	{
		return 1;
	}//carre bas gauche
}
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
