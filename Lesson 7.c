#include <stdio.h>
#include <stdlib.h>
#include "geek.c"

void Augmentedqs (int* arr, int len, int first, int last);

void SortInserts (int* arr, int len);

void qs (int* arr, int first, int last);

void bucketSort (int* arr, int len);

int main(){
    const int SIZE = 100;
    int arr[SIZE];
    fillIntRandom(arr, SIZE, 100);
    printIntArray(arr, SIZE, 3);
    Augmentedqs(arr, SIZE, 0, SIZE - 1);
    printf("\n");
    printIntArray(arr, SIZE, 3);
    printf("\n");
    const int SZ = 12;
    int arr2[12] = {0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};
    printIntArray(arr2, SZ, 3);
    bucketSort(arr2, SZ);
    printIntArray(arr2, SZ, 3);
    int g = 2 / 4;
    printf("%d", g);
    return 0;
}

void Augmentedqs (int* arr, int len, int first, int last){
    int EndFirst = len / 3;
    int BeginLast = EndFirst * 2;
    int BeginMid = EndFirst + 1;
    int EndMid = BeginLast - 1;
    if (len <= 10){
        SortInserts(arr, len);
    }
    else{
        qs(arr, first, EndFirst);
        qs(arr, BeginMid, EndMid);
        qs(arr, BeginLast, last);
        qs(arr, first, last);
    }
}


void SortInserts (int* arr, int len){
    int temp, pos;
    for (int i = 1; i < len; ++i){
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp){
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

void qs (int* arr, int first, int last){
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j){
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }while (i <= j);

    if (i < last) qs(arr, i, last);
    if (first < j) qs(arr, first, j);
}

void bucketSort (int* arr, int len){
    const int max = len;
    const int b = 10;

    int buckets[b][max + 1];
    for (int i = 0; i < b; i++){
        buckets[i][max] = 0;
    }
    for (int digit = 1; digit < 1000000000; digit *= 10){
        for (int i = 0; i < max; ++i){
            if (arr[i] % 2 == 0){
                int d = (arr[i] / digit) % b;
                buckets[d][buckets[d][max]++] = arr[i];
            }
            else {
                int d = (arr[i] / digit) % b;
                buckets[d][++buckets[d][max]];
            }
        }
        int idx = 0;
        for (int i = 0; i < b; ++i){
                for (int j = 0; j < buckets[i][max]; ++j){
                    if (arr[idx] % 2 == 0){
                    arr[idx++] = buckets[i][j];
                    }
                    else {
                        arr[idx++];
                    }
                }
                buckets[i][max] = 0;
        }
    }
}
