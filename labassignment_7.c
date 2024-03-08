/*Lindsey Duong
3/7/24
Lab Assignment 7*/

#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp, totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps[arr[j+1]]++;
                totalSwaps++;
            }
        }
    }
    printf("Bubble Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", arr[i], swaps[arr[i]]);
    }
    printf("Total number of swaps: %d\n\n", totalSwaps);
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, minimumIndex, temp, totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        minimumIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minimumIndex]) {
                minimumIndex = j;
            }
        }
        if (minimumIndex != i) {
            temp = arr[i];
            arr[i] = arr[minimumIndex];
            arr[minimumIndex] = temp;
            swaps[arr[i]]++;
            totalSwaps++;
        }
    }
    printf("Selection Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", arr[i], swaps[arr[i]]);
    }
    printf("Total number of swaps: %d\n\n", totalSwaps);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    int swaps1_bubble[101] = {0}; 
    int swaps1_selection[101] = {0};
    int swaps2_bubble[101] = {0};
    int swaps2_selection[101] = {0};

    printf("Array 1:\n");
    int array1_copy_bubble[n1];
    for (int i = 0; i < n1; i++) {
        array1_copy_bubble[i] = array1[i];
    }
    bubbleSort(array1_copy_bubble, n1, swaps1_bubble);

    int array1_copy_selection[n1];
    for (int i = 0; i < n1; i++) {
        array1_copy_selection[i] = array1[i];
    }
    selectionSort(array1_copy_selection, n1, swaps1_selection);

    printf("Array 2:\n");
    int array2_copy_bubble[n2];
    for (int i = 0; i < n2; i++) {
        array2_copy_bubble[i] = array2[i];
    }
    bubbleSort(array2_copy_bubble, n2, swaps2_bubble);

    int array2_copy_selection[n2];
    for (int i = 0; i < n2; i++) {
        array2_copy_selection[i] = array2[i];
    }
    selectionSort(array2_copy_selection, n2, swaps2_selection);

    return 0;
}