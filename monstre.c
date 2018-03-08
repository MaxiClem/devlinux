#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<unistd.h>
#define TAILLE_X 50
#define TAILLE_Y 30
#define NBmonstre 1000
void monstre(int T[TAILLE_X][TAILLE_Y], int x, int y) {
	int move=0;
	int haut=T[x][y+1];
	int bas=T[x][y-1];
	int gauche=T[x-1][y];
	int droite=T[x+1][y];
	move=rand()%4;
	T[x][y]=0;
	if (move == 0) {
		if (haut != 1) {
			y++;
		}
	}
	if (move == 1) {
		if (bas != 1) {
			y--;
		}
	}
	if (move == 2) {
		if (gauche != 1) {
			x--;
		}
	}
	if (move == 3) {
		if (droite != 1) {
			x++;
		}
	}
	T[x][y]=2;
}
void scanmonstre(int T[TAILLE_X][TAILLE_Y]){
	int i,j;
	for(i=0;i<TAILLE_X;i++){
		for(j=0;j<TAILLE_Y;j++){
			if(T[i][j]==2){
				monstre(T,i,j);
			}
		}
	}
}

void spawnmonstre(int T[TAILLE_X][TAILLE_Y]){
	int xrand,yrand,i;
	for(i=0;i<NBmonstre;i++){
		xrand=(rand()%(TAILLE_X-3))+1;
		yrand=(rand()%(TAILLE_Y-3))+1;
		T[xrand][yrand]=2;}
}


