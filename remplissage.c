#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void remplissage(int grile[][], taille_colonne, taille_ligne){
	for(int i =0, i<taille_colonne, i++){
		for(int j =0, j<taille_colonne, j++){
			if(grille[i][j] == 32){
				grille[i][j] = carac(generation());
			}
		}
	}
}