#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void chrono(){
	int minutes = 3;
	int secondes = 0;
	clock_t debut;
	
	while(minutes > 0 || secondes > 0){  
		printf("\r%02d:%02d", minutes, secondes);
		fflush(stdout); // affiche immédiatement 
		
		debut = clock();
		while(clock() - debut < CLOCKS_PER_SEC);
		
		if(secondes == 0){
			minutes--;
			secondes = 59;
		} else {
			secondes--;
		}
	}
	
	printf("\r00:00\n"); //affiche le chrono
	printf("Temps ecoule\n"); //affiche Temps écoulé 
}	
	
int main(){
	chrono();	
	return 0;
}