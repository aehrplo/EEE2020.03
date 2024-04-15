#include <stdio.h>
#include <stdlib.h>

void fn1(char** arr, const int* row, const int* col) {
	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *col; j++) {
			arr[i][j] += 2;
		}
	}

	printf("\n=====arr values in fn1=====\n");
	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *col; j++) {
			printf(" %3d", arr[i][j]);
		}
		printf("\n");
	}
	/* Complete the funciton */

	printf("\n=====arr address in fn1=====\n");
	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *col; j++) {
			printf(" %p", &arr[i][j]);
		}
		printf("\n");
	}
	/* Complete the funciton */

}

void fn2(char**& arr, const int& row, const int& col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] += 2;
		}
	}
	printf("\n=====arr values in fn2=====\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}

	printf("\n=====arr address in fn2=====\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %p", &arr[i][j]);
		}
		printf("\n");
	}
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

	printf("\n=====arr values in Main=====\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %3d", arr[i][j]);
		}
		printf("\n");
	}

	printf("\n=====arr address in Main=====\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %p", &arr[i][j]);
		}
		printf("\n");
	}

	//fn1
	fn1(arr, &row, &col);

	printf("\n=====arr values in Main after fn1=====\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %3d", arr[i][j]);
		}
		printf("\n");
	}

	//fn2
	fn2(arr, row, col);

	printf("\n=====arr values in Main after fn2=====\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %3d", arr[i][j]);
		}
		printf("\n");
	}


	//free
	for (i = 0; i < row; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
} //end of main