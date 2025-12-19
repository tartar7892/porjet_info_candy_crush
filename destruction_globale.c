#include"ligne6.c"
#include"ligne4.c"
#include"croix.c"
#include"carre.c"

bool destruction(int position_x, int position_y){
	ligne6(position_x, position_y);
	croix(position_x, position_y);
	carre(position_x, position_y);
	ligne4(position_x, position_y);
}