void ligne6_destruction(int position_x, int position_y, int taille_ligne, int taille_colonne, int grille[taille_ligne][taille_colonne]){
	for(int i=0; i<taille_ligne; i++){
		for(int j=0; j<taille_colonne; j++){
			if(grille[i][j] == grille[position_x][position_y]){
				grille[i][j] = ' ';
			}
		}
	}
}