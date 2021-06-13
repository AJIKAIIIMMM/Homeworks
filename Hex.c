#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geek.c"
#include "geek.h"

typedef char K;
typedef char htIndex;

int htSize;

htIndex hash(T *string, int count){
    int hashResult = 0;
    int idx = count;
    for (int i = 0; i < count; i++){
        hashResult = hashResult + string[i] % idx--;
    }
    return abs(hashResult);
}

int coinsCalc(int* coins, int SUM, int AMOUNT){
    int sum = 0;
    int BestNom[] = {0};
    int i = 0;
    int j = 0;
    for (i; i < 5; i++){
        do{
            sum = SUM - coins[i];
            if(sum < 0){
                sum = sum + coins[i];
                break;
            }
            BestNom[j++] = coins[i];
        }while(sum > 0);
    }
}

int main(){
    char string[256];
    printf("Enter some string in a range 256 symbols: ");
    gets(string);
    int i = 0;
    int count = 0;
    while (string[i] != '\0'){
        count++;
        i++;
    }
    printf("Your sum of codes: %d", hash(string, count));
    const int AMOUNT = 5;
    const int SUM = 98;
    int coins[] = {50, 10, 5, 2, 1};
    coinsCalc(coins, SUM, AMOUNT);
    return 0;
}
