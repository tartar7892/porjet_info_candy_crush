#include"header.h"

bool ligne_bas(int position_x, int position_y, int longueur){
	if(position_x+longueur > taille_ligne){
		return 0;
	}
	for(int i=1; i<longueur; i++){
		if(grille[position_x+i][position_y] != grille[position_x][position_y]){
			return 0;
		}
	}
	return 1;
}