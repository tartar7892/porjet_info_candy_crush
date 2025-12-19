#include"carre_haut_droite_destruc.c"
#include"carre_haut_gauche_destruc.c"
#include"carre_bas_droite_destruc.c"
#include"carre_bas_gauche_destruc.c"

bool carree(int position_x, int position_y, int taille_ligne, int taille_colonne, int grille[taille_ligne][taille_colonne]){
	if(position_x+3<taille_ligne &&
	ligne_haut(position_x+3, position_y, 4) && 
	ligne_haut(position_x, position_y, 4) &&
	ligne_droite(position_x, position_y+3, 4) &&
	ligne_droite(position_x, position_y, 4))
	{
		carre_haut_droite_destruc();
		return 1;
	}// carre droite haut
	
	if(position_x+3<taille_ligne &&
	ligne_bas(position_x-3, position_y, 4) && 
	ligne_bas(position_x, position_y, 4) &&
	ligne_droite(position_x, position_y+3, 4) &&
	ligne_droite(position_x, position_y, 4))
	{
		carre_bas_droite_destruc();
		return 1;
	}//carre droite bas
	
	if(position_x+3<taille_ligne &&
	ligne_haut(position_x+3, position_y, 4) && 
	ligne_haut(position_x, position_y, 4) &&
	ligne_gauche(position_x, position_y-3, 4) &&
	ligne_gauche(position_x, position_y, 4))
	{
		carre_haut_gauche_destruc();
		return 1;
	}//carre haut gauche 
	
	if(position_x+3<taille_ligne &&
	ligne_bas(position_x-3, position_y, 4) && 
	ligne_bas(position_x, position_y, 4) &&
	ligne_gauche(position_x, position_y-3, 4) &&
	ligne_gauche(position_x, position_y, 4))
	{
		carre_bas_gauche_destruc();
		return 1;
	}//carre bas gauche
}