#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int nouvelle_partie(int niveau, int grille[][], int taille_ligne, int taille_colonne){
	int contrat = 0;
	int score = 0;
	switch(contrat){
		case 1:
		contrat = 30;
		break;
		case 2:
		contrat = 60;
		break;
		case 3:
		contrat = 90;
		break;
	}
	
	remplissage(int grille[][], int taille_ligne, int taille_colonne);
	affichage(int grille[][], int taille_ligne, int taille_colonne);
	
	do{
		
	}while(contrat != 0 || nb_coups != 0);
}