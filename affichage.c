#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<unistd.h>
#define TAILLE_X 50
#define TAILLE_Y 30
#define NBmonstre 1000

void creerZone (int T[TAILLE_X][TAILLE_Y]){
	int i;
	int j;
	for(i=0; i<TAILLE_X; i++){
		T[i][0]=1;
		T[i][TAILLE_Y-1]=1;
		
	}
	for(j=0; j<TAILLE_Y; j++){
		T[0][j]=1;
		T[TAILLE_X-1][j]=1;
	}

}
void affichage (int T[TAILLE_X][TAILLE_Y]){
	int i;
	int j;
	for(j=0; j<TAILLE_Y; j++){
		for(i=0;i<TAILLE_X; i++){
			switch(T[i][j]){
				case 1:
					printf("#");
					break;

				case 0:
					printf(" ");
					break;
				case 2:
					printf("M");
					break;
			}		
		}
		printf("\n");

	}
}


