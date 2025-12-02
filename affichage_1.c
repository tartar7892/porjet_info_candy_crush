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
           "L'objectif est de réaliser des figures afin de faire disparaitre des élèments. Pour cela, \n"
           "carotte\n");
}

int main (){
	menu();
}

int main (){
	menu();
	return 0;
}

