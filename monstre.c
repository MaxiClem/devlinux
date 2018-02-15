#include <stdio.h>
#include <stdlib.h>
#define TAILLE_X 30
#define TAILLE_Y 20

void monstre(int t[TAILLE_X][TAILLE_Y], int x, int y) {
	int haut=t[x][y+1];
	int bas=t[x][y-1];
	int gauche=t[x-1][y];
	int droite=t[x+1][y];
	int move=rand()%4;
	t[x][y]=0;
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
	t[x][y]=2;
}


