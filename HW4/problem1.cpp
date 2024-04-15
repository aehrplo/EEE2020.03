#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

void setArray(int& row, int& column, int**& array) {    // 왜 레퍼런스 해야 하는지
    /*fill in the blank*/
    array = new int*[row];
    for(int i=0; i<row; i++){
        array[i] = new int[column];
    }
}

void createMatrix(int& row, int& column, int** array) {
    /*fill in the blank*/
    srand((unsigned int)time(NULL));
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            array[i][j] = rand() % 100;
            cout.width(2);
            cout << array[i][j] << "  ";
        }
        cout << endl;
    }
}

void transposeMatrix(int& row, int& column, int**& array) {
    /*fill in the blank*/
    int** buffer;
    int swap = column;
    column = row;
    row = swap;
    setArray(row, column, buffer);
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            buffer[i][j] = array[j][i];
            cout.width(2);
            cout << buffer[i][j] << "  ";
        }
        cout << endl;
    }

    // 메모리 해제
    for (int i = 0; i < column; i++) {
        free(array[i]);
    }
    free(array);
    array = buffer;
}

int main() {
    int row, column;
    /* define randomArray */
    int ** randomArray;

    cout << "Type row value: ";
    cin >> row;
    cout << "Type column value: ";
    cin >> column;

    setArray(row, column, randomArray);
    cout << "========Original Matrix========" << endl;
    createMatrix(row, column, randomArray);

    cout << endl << "=======Transposed Matrix=======" << endl;
    transposeMatrix(row, column, randomArray);

    // 메모리 해제
    for (int i = 0; i < row; i++) {
        free(randomArray[i]);
    }
    free(randomArray);

    return 0;
}
