#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"
#include <conio.h>

int chrono(int *minutes, int *secondes) {
    static clock_t heure_depart = 0;

    if (heure_depart == 0) {
        heure_depart = clock();
    }

    if (clock() - heure_depart >= CLOCKS_PER_SEC) {
        heure_depart = clock();

        if (*secondes == 0) {
            if (*minutes > 0) {
                (*minutes)--;
                *secondes = 59;
            }
        } else {
            (*secondes)--;
        }

        printf("\r%02d:%02d", *minutes, *secondes);
        fflush(stdout);
    }

    if (*minutes == 0 && *secondes == 0) {
        printf("\r00:00\n");
        printf("Temps ecoule\n");
    }

    return 0;
}
