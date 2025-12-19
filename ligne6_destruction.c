void ligne6_destruction(int position_x, int position_y){
	for(int i=0; i<taille_ligne; i++){
		for(int j=0; j<taille_colonne; j++){
			if(grille[i][j] == grille[position_x][position_y]){
				grille[i][j] = ' ';
			}
		}
	}
}