#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#define TAILLE_LIGNE 10
#define TAILLE_COLONNE 10
#define VIES_MAX 3

extern char grille[TAILLE_LIGNE][TAILLE_COLONNE];
extern int niveau;

void menu(void);
void regle_jeu(void);

bool ligne_haut(int x, int y, int len);
bool ligne_gauche(int x, int y, int len);
bool ligne_droite(int x, int y, int len);
bool ligne_bas(int x, int y, int len);

bool ligne6(int x, int y);
bool ligne4(int x, int y);
bool carree(int x, int y);
bool croix(int x, int y);

void ligne6_destruction(int x, int y);
void destruction_ligne4_haut(int x, int y);
void destruction_ligne4_gauche(int x, int y);
void destruction_ligne4_droite(int x, int y);
void destruction_ligne4_bas(int x, int y);
void destruction_croix(int x, int y);
int detruire_tout(char grille[TAILLE_LIGNE][TAILLE_COLONNE]);

int chrono(int *minutes, int *secondes);

void afficher_grille(char grille[TAILLE_LIGNE][TAILLE_COLONNE],int curseur_x, int curseur_y,int sel_x, int sel_y);

char carac(int choix);
int generation();

void remplissage(char grille[TAILLE_LIGNE][TAILLE_COLONNE]);
void initialiser_grille(char grille[TAILLE_LIGNE][TAILLE_COLONNE]);
void print_colored(char c);

void boucle_curseur(char grille[TAILLE_LIGNE][TAILLE_COLONNE]);

void perdre_vie(int *vies);
void afficher(int vies);

void gravite();
int echanger_positions(char grille[TAILLE_LIGNE][TAILLE_COLONNE],int x1, int y1, int x2, int y2);

void jouer_niveau(int n);
void afficher_score(int score);
void mettre_a_jour_score(int *score, int bonbons_detruits);

#endif // HEAD_H_INCLUDED
