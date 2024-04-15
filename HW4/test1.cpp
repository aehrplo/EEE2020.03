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

int main() {
    int row, column;
    /* define randomArray */
    int ** randomArray;

    cout << "Type row value: ";
    cin >> row;
    cout << "Type column value: ";
    cin >> column;

    setArray(row, column, randomArray);

    // 메모리 해제
    for (int i = 0; i < row; i++) {
        free(randomArray[i]);
    }
    free(randomArray);

    return 0;
}