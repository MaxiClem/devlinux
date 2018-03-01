#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<unistd.h>
#define TAILLE_X 30
#define TAILLE_Y 20
#define NBmonstre 6

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
					printf("M");
					break;
			}		
		}
		printf("\n");

	}
}


void monstre(int T[TAILLE_X][TAILLE_Y], int x, int y) {
	int haut=T[x][y+1];
	int bas=T[x][y-1];
	int gauche=T[x-1][y];
	int droite=T[x+1][y];
	int move=rand()%4;
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
	for(i=0;i<TAILLE_Y;i++){
		for(j=0;TAILLE_X;j++){
			if(T[j][i]==2){
				monstre(T,j,i);}
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

int main(){
	srand(time(NULL));
	int T[TAILLE_X][TAILLE_Y]={{0}};
	creerZone(T);
	spawnmonstre(T);
	while(1==1){
		system("clear");
		affichage(T);
		scanmonstre(T);
		sleep(1);
	}
	return 0;
}	
