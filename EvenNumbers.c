#include <stdio.h>
#include <stdlib.h>

int InputNumber();

void CheckNumber(int a);

int main(){
    int a = InputNumber();
    CheckNumber(a);
    return 0;
}

int InputNumber(){
    int a;
    printf("Enter even number:\n");
    scanf("%d", &a);
    return a;
}

void CheckNumber(int a){
    if (a % 2 != 0 & a != 1 || a == 2){
        printf("The number %d is prime", a);
    }
    else {
        printf("The number %d is not prime", a);
    }
}
