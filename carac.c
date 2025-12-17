#include<stdio.h>
#include<random.h>
#include<stdlib.h>
#include<time.h>

char carac(int choix){
	switch(choix){
		case 1:
		return "V";
		case 2:
		return "O";
		case 3:
		return "I";
		case 4:
		return "X";
	}
}