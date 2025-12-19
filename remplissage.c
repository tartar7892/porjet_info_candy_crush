#include"header.h"

void remplissage(){
	for(int i =0; i<taille_colonne; i++){
		for(int j =0; j<taille_colonne; j++){
			if(grille[i][j] == 32){
				grille[i][j] = carac(generation());
			}
		}
	}
}