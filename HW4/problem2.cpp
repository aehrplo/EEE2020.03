#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 5
#define COL 5

int arr[ROW][COL];
void rotateArr() {
	/**********Implement here*****************/
	int buffer[ROW][COL];
	for (int i = 0; i < COL; i++) {
		for (int j = 0; j < ROW ; j++) {
			buffer[i][j] = arr[ROW -1 - j][i];
			printf("%5d", buffer[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			arr[i][j] = buffer[i][j];
		}
	}
	/**********Implement here*****************/
}

int main() {

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			arr[i][j] = 1 + i * 5 + j;
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	rotateArr();
	rotateArr();
	rotateArr();
	return 0;
}

