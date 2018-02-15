#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAILLE_X 30
#define TAILLE_Y 20

void creerZone (int T[TAILLE_X][TAILLE_Y]){
	int i;
	int j;
	for(i=0; i<30; i++){
		T[i][0]=1;
		T[i][19]=1;
		
	}
	for(j=0; j<20; j++){
		T[0][j]=1;
		T[29][j]=1;
	}

}
void affichage (int T[TAILLE_X][TAILLE_Y]){
	int i;
	int j;
	for(j=0; j<20; j++){
		for(i=0;i<30; i++){
			switch(T[i][j]){
				case 1:
					printf("#");
					break;

				case 0:
					printf(" ");
					break;
				case 2:
					printf("B");
					break;
			}		
		}
		printf("\n");

	}
}


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



int main(){
	int T[TAILLE_X][TAILLE_Y]={{0}};
	creerZone(T);
	T[10][10]=2;
	affichage(T);
	return 0;
}	
