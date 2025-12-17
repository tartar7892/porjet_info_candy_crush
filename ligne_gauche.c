bool ligne_gauche(int position_x, int position_y, int longueur){
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