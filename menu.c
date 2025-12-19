#include <stdio.h>
#include "head.h"


void menu() {
    int choix;
    do {
        printf("\n");
        printf("\t#####################################################################\n");
        printf("\t########################## RUNE MATCHER #############################\n");
        printf("\t#####################################################################\n");
        printf("\n");
        printf("\tBienvenue sur notre jeu Rune matcher!\n");
        printf("\tQue souhaitez vous faire ?\n");
        printf("\t\t1 : Lire les regles du jeu \n");
        printf("\t\t2 : Lancer une nouvelle partie \n");
        printf("\t\t3 : Reprendre votre ancienne partie\n");
        printf("\t\t4 : Quitter \n");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                regle_jeu();
                break;
            case 2:
                printf("nouvelle_partie()\n");
                break;
            case 3:
                printf("reprendre_partie(pseudo)\n");
                break;
            case 4:
                printf("Merci d'avoir joue et a bientot!\n");
                break;
        }
    } while (choix != 4);
}

void regle_jeu() {
    printf("\t=== REGLES DU JEU ===\n\n");
    printf("Ce jeu est de type match 4.\n");
    printf("L'objectif est de realiser des figures afin de faire disparaitre des elements.\n");
    printf("Vous pouvez interchanger deux elements en utilisant les fleches directionnelles et la touche entree pour valider.\n\n");
    printf("Les figures a realiser sont :\n");
    printf("\t- La croix (branches de 2 elements) : fait disparaitre tous les elements de ce type sur la ligne et la colonne concernees.\n");
    printf("\t- Le carre (cote 4) : fait disparaitre tous les elements du type utilise a l'interieur.\n");
    printf("\t- La ligne de 6 elements : fait disparaitre tous les elements utilises pour la constituer, meme isoles.\n");
    printf("\t- La ligne de 4 elements : fait disparaitre tous les elements utilises pour la constituer.\n\n");
    printf("Il y a trois niveaux, chacun de difficulte croissante.\n");
    printf("Pour les realiser, vous disposez d'un nombre de coups et d'un temps limite.\n");
    printf("Si vous echouez, vous perdez une vie. Vous avez trois vies, et si vous les perdez toutes vous recommencez a zero.\n");
    printf("Vous pouvez sauvegarder votre progression a tout moment.\n");
}
