#include <stdio.h>
#include <stdlib.h>
#include "geek.c"
#define SZ 10
#define true 1 == 1
#define false 1 != 1
#define T int
#define SIZE 1000

typedef int boolean;

int cursor = -1;
T Stack[SIZE];

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

int Bull (int n);

typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

void init(){
    for (int i = 0; i < SZ; ++i){
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat){
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;

    if (tail < SZ){
        arr[tail++] = node;
        items++;
    }else if (items == SZ){
        printf("%s \n", "Queue is full");
        return;
    }
}

Node* remExcept(){
    Node *temp;
    if(items == 0){
        return NULL;
    }else {
        int max = arr[0]->pr;
        int maxpos = 0;
        for(int i = 0; i < SZ; i++){
            if (max < arr[i]->pr){
                max = arr[i]->pr;
                maxpos = i;
            }
        }
        temp = arr[maxpos];
	arr[maxpos] = NULL;
        for(int i=maxpos;i < items - 1;i++){
			arr[i]=arr[i+1];
		}
		items--;
        return temp;
    }

}

void printQueue(){
    printf("[ ");
    for(int i = 0; i < SZ; ++i){
        if (arr[i] == NULL)
            printf("[*, *]");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

int Bull (int n){
    if ( n >= 2 ){
        Bull( n / 2 );
    }
    printf("%d", n % 2);
    push(n % 2);
}

int main(){
    int n = 0;
    printf("Enter the number, which you want to transfer to bull:");
    scanf ("%d", &n);
    Bull (n);
    printf("\n");
    while (cursor != -1){
        printf("%d ", pop());
    }
    init();
    ins(1, 11);
    ins(3, 22);
    printQueue();
    remExcept();
    return 0;
}
