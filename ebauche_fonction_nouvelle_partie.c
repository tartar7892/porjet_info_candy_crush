#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int nouvelle_partie(int niveau, int grille[][], int taille_ligne, int taille_colonne){
	int position_x;
	int position_y;
	int contrat = 0;
	int score = 0;
	
	switch(contrat){ // à modifier selon les choix de contrats
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
		input = getch(); // récupére le touche appuyée par l'utilisateur sous forme de code ASCII
		switch(input){
			case 100: // correspond à d en ascii
			position_x += 1;
			
			case 113: // correspond à q en ascii
			position_x -= 1;
			
			case 115: // correspond à s en ascii
			position_y -= 1;
			
			case 122: // correspond à z en ascii
			position_y += 1;
			
			case 32:
			cases_echanger(position); // fonction à compléter
		}
		
		// pour éviter les dépassements de la grille
		if(position_x > 9{
			position_x %= 10;
		}
		if(position_y > 9){
			position_y %= 10;
		}
		
	}while(contrat != 0 || nb_coups != 0);
}
