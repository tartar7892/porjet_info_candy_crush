void carre_haut_gauche(int position_x, int position_y, int taille_ligne, int taille_colonne, int grille[taille_ligne][taille_colonne]){
	for(int i=0; i<4; i++){
		for(int i=0; i<4; i++){
			if(grille[position_x - i][position_y - j] == grille[position_x][position_y]){
				grille[position_x - i][position_y - j] = ' ';
			}
		}
	}
}