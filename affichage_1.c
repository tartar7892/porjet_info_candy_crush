#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int menu(){
	int choix;
	do {
		printf("\n");
		printf("Bienvenue sur notre jeu [inserer nom] !\n");
		printf("Que souhaitez vous faire ?\n");
		printf("\t1 : Lire les regles du jeu \n");
		printf("\t2 : Lancer une nouvelle partie \n");
		printf("\t3 : Reprendre votre ancienne partie \n");
		printf("\t4 : Quitter \n");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				printf("regle_jeu()");
			break;
			case 2:
				printf("nouvelle_partie()");
			break;
			case 3:
				printf("reprendre_partie(pseudo)");
			break;
			case 4:
				printf("Merci d'avoir joué et à bientot !");
			break;
		}
	}while (choix != 4);
}

void regle_jeu() {
    printf("Ce jeu est de type match 4.\n"
           "L'objectif est de réaliser des figures afin de faire disparaitre des élèments.\n"
		   "Pour cela, vous pouvez interchanger deux élèments en utilisants les fléches directionelles et entrées pour valider. \n" //les touches ne sont pas fixes
           "Les figures à réaliser sont les suivantes :\n"
		   "la croix, avec des branches de deux élèments, qui fait disparaitre tout les élèments de ce type sur la ligne et la colonne concernèes. ;\n"
		   "le carrré, de coté 4, fait disparaitre tout les élèments du type utilisé à l'intérieur de lui même;\n"
		   "la ligne de 6 élèments qui fait disparaitre tout les élèments utilisés pour la constituer, même ceux isolés;\n"
		   "la ligne de 4 élèments qui fait disparaitre tout les élèments utilisés pour la constituer.\n"
		   "\n"
		   "Il y a trois niveau, chacun de difficulté croissante.\n"
		   "Pour les réliser, vous disposez de d'un nombre de coup et d'un temps limité.\n"
		   "Si vous échouez, vous perdez une vie. Vous disposez de trois vies et si vous les perdez toutes vous recommencez à zéro.\n"
		   "Vous pouvez sauvegarder à tout moment votre progression.\n");
}

int main (){
	menu();
	return 0;
}
