#include <iostream>
using namespace std;

void Swap(int& a, int& b) {
    //*************** Problem2-1****************//
    int temp = a;
    a = b;
    b = temp;

    //*************** Problem2-1****************//
}

void BubbleSort(int* arr, int n) {
    //*************** Problem2-2****************//
    int i, j;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (arr[j] < arr[j + 1]) {
                Swap(arr[j], arr[j + 1]);
            }
        }
    }
    //*************** Problem2-2****************//
}

void QuickSort(int* arr, int low, int high) {
    //*************** Problem2-3****************//
    if (low >= high) {
        return;
    }

    int pivot = low;
    int i = pivot + 1;
    int j = high;

    while (i <= j) {
        while (arr[i] >= arr[pivot]) {
            i++;
        }
        while (arr[j] <= arr[pivot] && j > low) {
            j--;
        }

        if (i > j) {
            Swap(arr[j], arr[pivot]);
        }
        else {
            Swap(arr[i], arr[j]);
        }
    }
    QuickSort(arr, low, j - 1); // pivot 왼쪽
    QuickSort(arr, j + 1, high); // pivot 오른쪽
    //*************** Problem2-3****************//
}

int main() {
    int arr1[12] = { 5, 11, 6, 2, 3, 1, 9, 12, 7, 8, 10, 4 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[12] = { 10, 2, 6, 11, 4, 1, 9, 8, 7, 12, 5, 3 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    BubbleSort(arr1, n1);
    QuickSort(arr2, 0, n2 - 1);


    cout << "Sorted array(BubbleSort): \n";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\nSorted array(QuickSort): \n";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
