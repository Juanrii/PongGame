#include <stdio.h>
#define V 21
#define H 75

void start(char field[V][H], int ballX, int ballY, int initPlayer, int endPlayer, int initIA, int endIA);
void border(char field[V][H]);
void racketPlayer(char field[V][H], int initPlayer, int endPlayer);
void racketIA(char field[V][H], int initIA, int endIA);
void ball(char field[V][H], int ballX, int ballY);
void drawField(char field[V][H]);

int main( ){
    int ballX, ballY, initPlayer, endPlayer, initIA, endIA;
	char field[V][H];
	
	ballX = 37;
	ballY = 10;
	
	initPlayer = 8;
	endPlayer = 12;
	
	initIA = 8;
	endIA = 12;
	
	start(field, ballX, ballY, initPlayer, endPlayer, initIA, endIA);
	
	drawField(field);
	
	system("pause");
    return 0;
}

void start(char field[V][H], int ballX, int ballY, int initPlayer, int endPlayer, int initIA, int endIA) {
	border(field);
	racketPlayer(field, initPlayer, endPlayer);
	racketIA(field, initIA, endIA);
	ball(field, ballX, ballY);
}

void border(char field[V][H]) {
	int i, j;
	
	for (i = 0; i < V; i++) {
		for (j = 0; j < H; j++) {
			if (i == 0 || i == V-1) {
				field[i][j] = '-';
			} else if (j == 0 || j == H-1) {
				field[i][j] = '|';
			} else {
				field[i][j] = ' ';
			}
		}
	}
}

void racketPlayer(char field[V][H], int initPlayer, int endPlayer) {
	int i, j;
	
	for (i = initPlayer; i <= endPlayer; i++) {
		for (j = 2; j <= 3; j++) {
			field[i][j] = 'X';
		}
	}
}

void racketIA(char field[V][H], int initIA, int endIA) {
	int i, j;
	
	for (i = initIA; i <= endIA; i++) {
		for (j = H - 4; j <= H - 3; j++) {
			field[i][j] = 'X';
		}
	}
}

void ball(char field[V][H], int ballX, int ballY) {
	field[ballY][ballX] = 'O';
}

void drawField(char field [V][H]) {
	int i, j;
	
	for(i = 0; i < V; i++) {
		for(j = 0; j < H; j++) {
			printf("%c", field[i][j]);
		}
		printf("\n");
	}	
}

