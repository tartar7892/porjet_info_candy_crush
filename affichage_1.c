#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <wchar.h>
#include <locale.h>

void regle_jeu();
void menu(){
	int choix;
	do {
		printf("\n");
		printf("Bienvenue sur notre jeu [inserer nom] !\n");
		printf("Que souhaitez vous faire ?\n");
		printf("\t1 : Lire les regles du jeu \n");
		printf("\t2 : Lancer une nouvelle partie \n");
		printf("\t3 : Reprendre votre ancienne partie\n");
		printf("\t4 : Quitter \n");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				regle_jeu();
			break;
			case 2:
				printf("nouvelle_partie()");
			break;
			case 3:
				printf("reprendre_partie(pseudo)");
			break;
			case 4:
				
				wchar_t texte[] = L"Merci d'avoir joué et à bientot!";
				wprintf(L"%ls\n", texte);

			break;
		}
	}while (choix != 4);
}

void regle_jeu() {
    wchar_t text_regle[]=L"\t=== RÈGLES DU JEU ===\n\n"
       "Ce jeu est de type match 4.\n"
       "L'objectif est de réaliser des figures afin de faire disparaître des éléments.\n"
       "Vous pouvez interchanger deux éléments en utilisant les flèches directionnelles et la touche entrée pour valider.\n\n"
       "Les figures à réaliser sont :\n"
       "\t- La croix (branches de 2 éléments) : fait disparaître tous les éléments de ce type sur la ligne et la colonne concernées.\n"
       "\t- Le carré (côté 4) : fait disparaître tous les éléments du type utilisé à l'intérieur.\n"
       "\t- La ligne de 6 éléments : fait disparaître tous les éléments utilisés pour la constituer, même isolés.\n"
       "\t- La ligne de 4 éléments : fait disparaître tous les éléments utilisés pour la constituer.\n\n"
       "Il y a trois niveaux, chacun de difficulté croissante.\n"
       "Pour les réaliser, vous disposez d'un nombre de coups et d'un temps limité.\n"
       "Si vous échouez, vous perdez une vie. Vous avez trois vies, et si vous les perdez toutes vous recommencez à zéro.\n"
       "Vous pouvez sauvegarder votre progression à tout moment.\n";
	   wprintf(L"%ls\n", text_regle);
}

int main (){
	setlocale(LC_ALL, "");
	menu();
	return 0;
}
