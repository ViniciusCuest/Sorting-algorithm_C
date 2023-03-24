#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int* vector, int qtt) {
    int fim, i, aux;
    for (fim = qtt-1; fim > 0; fim--)
        for (i = 0; i < fim; i++)
            if (vector[i] > vector[i+1]) {
                aux = vector[i];
                vector[i] = vector[i+1];
                vector[i+1] = aux;
            }
    printf("Bubble Sort: [");
    for (i = 0; i < qtt; i++) {
        if (i != (qtt - 1))
            printf("%d,", vector[i]);
        else
            printf("%d", vector[i]);
    }
    printf("]");
}

void insertionSort(int* vector, int qtt) {
    int i, aux, j = 1;

    while (j < qtt) {
        aux = vector[j];
        i = j - 1;
        while ((i >= 0) && (vector[i] > aux)) {
            vector[i + 1] = vector[i];
            i = i - 1;
        }
        vector[i + 1] = aux;
        j = j + 1;
    }

    printf("Insertion Sort: [");
    for (i = 0; i < qtt; i++) {
        if (i != (qtt - 1))
            printf("%d,", vector[i]);
        else
            printf("%d", vector[i]);
    }
    printf("]");
}

void selectionSort(int* vector, int qtt) {
    int i, j, min, aux;
    for (i = 0; i < (qtt - 1); i++) {
        min = i;
        for (j = (i+1); j < qtt; j++)
            if (vector[j] < vector[min])
                min = j;
        if (vector[i] != vector[min]) {
            aux = vector[i];
            vector[i] = vector[min];
            vector[min] = aux;
        }
    }

    printf("Selection Sort: [");
    for (i = 0; i < qtt; i++) {
        if (i != (qtt - 1))
            printf("%d,", vector[i]);
        else
            printf("%d", vector[i]);
    }
    printf("]");
}

int main() {
    /*
        generate random vector;
        https://onlineintegertools.com/create-integer-array
    */

    int values[50] = {145, 440, 122, 113, 255, 430, 162, 299, 143, 446, 431, 85, 62, 325, 201, 367, 478, 406, 59, 10, 39, 434, 350, 471, 58, 346, 441, 121, 266, 59, 116, 302, 417, 107, 165, 343, 135, 48, 4, 412, 67, 75, 246, 213, 446, 244, 443, 174, 308, 142};
    size_t length = sizeof(values) / sizeof(values[0]);

    bubbleSort(values, length);
    printf("\n");
    insertionSort(values, length);
    printf("\n");
    selectionSort(values, length);
    printf("\n");

    return 0;
}
