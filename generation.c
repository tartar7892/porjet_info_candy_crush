#include<stdio.h>
#include<random.h>
#include<stdlib.h>
#include<time.h>

int generation(){
	int nb_aleatoire = 0;
	srand(time(NULL));
	nb_aleatoire = rand()%4 +1;
	return nb_aleatoire;
}