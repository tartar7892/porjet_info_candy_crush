void destruction_ligne4_droite(int position_x, int position_y, int taille_ligne, int taille_colonne, int grille[taille_ligne][taille_colonne]){
	for(int i=0; i<4; i++){
		grille[position_x][position_y + i] = ' ';
	}
}