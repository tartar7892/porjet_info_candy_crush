#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>
#include <string.h>

void menu() {
    int choix;
    char pseudo[50];

    do {
        system("cls");
        printf("\t##############################################\n");
        printf("\t################ RUNE MATCHER ################\n");
        printf("\t##############################################\n\n");

        printf("\tBienvenue sur notre jeu Rune matcher!\n");
        printf("\tQue souhaitez vous faire ?\n");
        printf(" \t1 : Lire les regles du jeu\n");
        printf(" \t2 : Lancer une nouvelle partie\n");
        printf(" \t3 : Reprendre votre ancienne partie\n");
        printf(" \t4 : Quitter\n\n");

        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {

            case 1:
                regle_jeu();
                break;

            case 2: {
                demander_pseudo(pseudo);

                int next = interface_niveau(1, pseudo, 3, 0, 0, VIES_MAX);

                while (next > 0 && next <= 3) {
                    next = interface_niveau(next, pseudo, 3, 0, 0, VIES_MAX);
                }

                break;
            }

            case 3: {
                char pseudo_sauv[50];
                int n, min, sec, sc, v;

                printf("\nEntrez votre pseudo : ");
                scanf("%s", pseudo_sauv);

                if (charger_sauvegarde(pseudo_sauv, &n, &min, &sec, &sc, &v)) {
                    int next = interface_niveau(n, pseudo_sauv, min, sec, sc, v);
                    while (next > 0 && next <= 3) {
                        next = interface_niveau(next, pseudo_sauv, 3, 0, 0, VIES_MAX);
                    }
                } else {
                    printf("\nAucune sauvegarde trouvee pour ce pseudo.\n");
                    getch();
                }
                break;
            }

            case 4:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }

    } while (choix != 4);
}

void regle_jeu() {
    printf("\t=== REGLES DU JEU ===\n\n");
    printf("Ce jeu est de type match 3.\n");
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
    printf("\n");
    printf("Les niveaux du jeu :\n\n");

    printf("Le jeu comporte trois niveaux successifs, chacun plus exigeant que le precedent.\n");
    printf("Votre objectif est d'atteindre un certain score avant la fin du temps imparti,\n");
    printf("tout en gerant vos vies et vos coups.\n\n");

    printf("Niveau 1 - Initiation :\n");
    printf("Objectif : 50 points\n");
    printf("Temps : 3 minutes\n");
    printf("Description : Ce premier niveau vous permet de vous familiariser avec les\n");
    printf("mecaniques du jeu. Les combinaisons sont plus faciles a reperer et les grilles\n");
    printf("sont plus indulgentes. Ideal pour prendre vos marques avant d'affronter la suite.\n\n");

    printf("Niveau 2 - Maitrise :\n");
    printf("Objectif : 120 points\n");
    printf("Temps : 3 minutes\n");
    printf("Description : Les grilles deviennent plus complexes et les combinaisons moins\n");
    printf("evidentes. Vous devrez reflechir plus vite et optimiser vos deplacements pour\n");
    printf("atteindre l'objectif dans le temps imparti. La difficulte augmente sensiblement.\n\n");

    printf("Niveau 3 - Expertise :\n");
    printf("Objectif : 200 points\n");
    printf("Temps : 3 minutes\n");
    printf("Description : Le defi ultime. Les grilles sont plus piegeuses, les opportunites\n");
    printf("de combinaisons sont plus rares et chaque seconde compte. Seuls les joueurs les\n");
    printf("plus attentifs et strategiques parviendront a atteindre l'objectif final.\n\n");

    printf("Souvenez-vous : vous disposez de trois vies pour progresser dans l'aventure.\n");
    printf("Si vous echouez a un niveau, vous perdez une vie. Si vous les perdez toutes,\n");
    printf("vous devrez recommencer depuis le debut.\n\n");
    printf("\nAppuyez sur une touche pour revenir au menu...");
    getch();
}

void demander_pseudo(char *pseudo) {
    printf("\nEntrez votre pseudo : ");
    scanf("%s", pseudo);
}

void sauvegarder_partie(const char *pseudo, int niveau, int minutes, int secondes, int score, int vies) {
    FILE *f = fopen("sauvegardes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    char p[50];
    int n, min, sec, sc, v;
    int trouve = 0;

    if (f) {
        while (fscanf(f, "%s %d %d %d %d %d", p, &n, &min, &sec, &sc, &v) == 6) {
            if (strcmp(p, pseudo) == 0) {
                fprintf(temp, "%s %d %d %d %d %d\n", pseudo, niveau, minutes, secondes, score, vies);
                trouve = 1;
            } else {
                fprintf(temp, "%s %d %d %d %d %d\n", p, n, min, sec, sc, v);
            }
        }
        fclose(f);
    }

    if (!trouve) {
        fprintf(temp, "%s %d %d %d %d %d\n", pseudo, niveau, minutes, secondes, score, vies);
    }

    fclose(temp);

    remove("sauvegardes.txt");
    rename("temp.txt", "sauvegardes.txt");

    printf("\nPartie sauvegardee avec succes !\n");
}


int charger_sauvegarde(const char *pseudo, int *niveau, int *minutes, int *secondes, int *score, int *vies) {
    FILE *f = fopen("sauvegardes.txt", "r");
    if (!f)
        return 0;

    char p[50];
    int n, min, sec, sc, v;

    while (fscanf(f, "%s %d %d %d %d %d", p, &n, &min, &sec, &sc, &v) == 6) {
        if (strcmp(p, pseudo) == 0) {
            *niveau = n;
            *minutes = min;
            *secondes = sec;
            *score = sc;
            *vies = v;
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}


int demander_sauvegarde() {
    printf("\nVoulez-vous sauvegarder la partie ? (O/N) : ");
    char c = getch();

    if (c == 'o' || c == 'O')
        return 1;

    return 0;
}


