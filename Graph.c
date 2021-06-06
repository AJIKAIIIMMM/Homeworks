#include <stdio.h>
#include <stdlib.h>
#include "geek.h"
#include "geek.c"
#define true 1 == 1
#define false 1 != 1
#define T int
#define SIZE 1000

typedef int boolean;

int cursor = -1;
T Stack[SIZE];

enum { n = 6 };
enum { m = 8 };

int matrix[n][n] = {
            {0, 1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1, 1},
            {0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0},
};

int visited[m] = {0};

int matrix2[m][m] = {
            {0, 1, 0, 1, 0, 0, 0, 1},
            {1, 0, 1, 0, 0, 1, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 1},
            {1, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 1, 0, 1},
            {1, 0, 1, 0, 0, 0, 1, 0},
};

void depthTraversStack(int st){
    int r;

    push(st);
    for(r = 0; r < n; ++r){
        if(matrix[st][r] == 1){
            push(r);
        }
    }

}


boolean push(T data){
    if(cursor < SIZE){
        Stack[++cursor] = data;
        return true;
    }else{
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T pop(){
    if(cursor != -1){
        return Stack[cursor--];
    }else{
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

void depthTravers(int st){
    int r;
    int countPikes = 0;
    printf("%d ", st);

    visited[st] = 1;
    for(r = 0; r < n; ++r){
        if(matrix2[st][r] == 1 && !visited[r]){
            depthTravers(r);
            ++countPikes;
        }
    }
    printf("Amount of neighbour pikes %d", countPikes);
}

void widthTravers(int** matrix2, int start, const int size){
    int Pikes = 0;
    TwoLinkList* queue = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    visited[size];
    resetArr(size);
    TwoLinkEnqueue(queue, start);
    while(queue->size > 0){
        int indx = TwoLinkDequeue(queue);
        if(visited[indx] == 1)continue;
        visited[indx] = 1;
        printf("%d", indx);
        for(int i = 0; i < size; ++i){
            if(matrix[indx][i] == 1 && visited[i] == 0)
                TwoLinkEnqueue(queue, i);
                ++Pikes;
        }
    }
    printf("Amount of pikes %d", Pikes);
}

void resetArr(int n){
    for(int i = 0; i < n; ++i){
        visited[i] = 0;
    }
}


int main(){
    depthTraversStack(0);
    resetArr(n);
    depthTravers(0);
    resetArr(m);
    widthTravers(matrix2[m][m], 0, m);
    resetArr(m);
    return 0;
}
