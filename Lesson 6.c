#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PrintArray (int arr[5][2],int ROW,int COL);

void Swap (int *a, int *b);

void BubbleSort (int arr[5][2], int ROW, int COL);

void Trabba (int seq[11]);

int main(const int argc, const char** argv){
    const int ROW = 5;
    const int COL = 2;
    int arr[5][2] = {1, 9, 2, 5, 7, 6, 4, 3, 8};
    PrintArray (arr, ROW, COL);
    BubbleSort (arr, ROW, COL);
    printf("\n");
    PrintArray (arr, ROW, COL);
    int seq[11];
    printf("Enter 11 even numbers\n");
    for (int i = 0; i < 11; i++) {
        printf("seq[%d] = ", i);
        scanf("%d", &seq[i]);
    }
    Trabba(seq);
    return 0;
}

void PrintArray (int arr[5][2],int ROW,int COL){
    for (int i=0; i<ROW; i++, putchar('\n')){
        for (int j=0; j<COL; j++){
            printf (" %d", arr[i][j]);
        }
    }
}

void BubbleSort (int arr[5][2], int ROW, int COL) {
    for (int a = 0; a < 9; a++){
        for (int i = 0; i < ROW; i++){
            for (int j = 0; j < COL; j++){
                if (i == ROW - 1 && j == COL - 1){
                    continue;
                }
                if (arr[i][j] > arr[i][j + 1]){
                    Swap(&arr[i][j], &arr[i][j + 1]);
                }
            }
        }
    }
}

void Swap (int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}


void Trabba (int* seq){
    int mid = 5;
    int result;
    for (int i = 0; i < 11; i++){
        printf("%d ", seq[i]);
    }
    printf("\n");
    for (int i = 1; i < 6; i++){
        Swap(&seq[mid - i], &seq[mid + i]);
    }
    for (int i = 0; i < 11; i++){
        printf("%d ", seq[i]);
    }
    printf("\n");
    for (int i = 0; i < 11; i++){
        result = sqrt(fabs(seq[i])) + 5 * pow(seq[i], 3);
        if (result > 400){
            printf("Result of the number %d is more than 400\n", i);
        }
    }
}


