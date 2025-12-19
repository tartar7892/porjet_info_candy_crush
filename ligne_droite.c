bool ligne_droite(int position_x, int position_y, int longueur){
	if(position_y+longueur > taille_colonne){
		return 0;
	}
	for(int i=1; i<longueur; i++){
		if(grille[position_x][position_y+i] != grille[position_x][position_y]){
			return 0;
		}
	}
	return 1;
}