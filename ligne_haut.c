bool ligne_haut(int position_x, int position_y, int longueur, int taille_ligne, int taille_colonne, int grille[taille_ligne][taille_colonne]){
	if(position_x-longueur < 0){
		return 0;
	}
	for(int i=1; i<longueur; i++){
		if(grille[position_x-i][position_y] != grille[position_x][position_y]){
			return 0;
		}
	}
	return 1;
}