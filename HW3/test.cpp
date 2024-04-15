void fn2(char*& arr, const int& row, const int& col){
	printf("\n=====arr values in fn2=====\n");
	/* Complete the funciton */

    printf("\n=====arr address in fn2=====\n");
	/* Complete the funciton */

}

int main(void) {
	int i = 0;
	int j = 0;
	const int row = 4;
	const int col = 4;

	char** arr = (char**)malloc(sizeof(char*) * row);

	for (i = 0; i < row; i++) {
		arr[i] = (char*)malloc(sizeof(char) * col);
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			arr[i][j] = 10 * i + j;
		}
	}

	fn2(/* Complete the funciton */);

    return 0;

}