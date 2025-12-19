#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#define TAILLE_LIGNE 20
#define TAILLE_COLONNE 20

extern char grille[TAILLE_LIGNE][TAILLE_COLONNE];
void menu(void);
void regle_jeu(void);
void chrono(void);

bool ligne_haut(int position_x, int position_y, int longueur);
bool ligne_gauche(int position_x, int position_y, int longueur);
bool ligne_droite(int position_x, int position_y, int longueur);
bool ligne_bas(int position_x, int position_y, int longueur);
bool ligne6(int position_x, int position_y);
bool ligne4(int position_x, int position_y);
void ligne6_destruction(int position_x, int position_y);
void destruction_ligne4_haut(int position_x, int position_y);
void destruction_ligne4_gauche(int position_x, int position_y);
bool carree(int position_x, int position_y);
bool croix(int position_x, int position_y);
void destruction_ligne4_droite(int position_x, int position_y);
void destruction_ligne4_bas(int position_x, int position_y);
void destruction_croix(int position_x, int position_y);
#endif // HEAD_H_INCLUDED
