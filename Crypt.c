#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geek.c"
#include "geek.h"
#define ENG 26
#define RUS 32

T encrypt(T *string, int n){
    int flag;
    int i = 0;
    int j = 0;
    char crypt[256] = {0};
    while (string[i] != '\0'){
        flag = 0;
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            crypt[i] = string[i] + (n % ENG);
            if (string[i] > 'Z') crypt[i] = 'A' + (string[i] - 'Z') - 1;
            flag = 1;
        }
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            crypt[i] = string[i] + (n % ENG);
            if (string[i] > 'z') crypt[i] = 'a' + (string[i] - 'z') - 1;
            flag = 1;
        }
        if (string[i] >= 'А' && string[i] <= 'Я')
        {
            crypt[i] = string[i] + (n % RUS);
            if (string[i] > 'Я') crypt[i] = 'А' + (string[i] - 'Я') - 1;
            flag = 1;
        }
        if (string[i] >= 'а' && string[i] <= 'я')
        {
            crypt[i] = string[i] + (n % RUS);
            if (string[i] > 'я') crypt[i] = 'а' + (string[i] - 'я') - 1;
            flag = 1;
        }
        i++;
    }
    while(crypt[j] != '\0'){
        printf("%c", crypt[j]);
        ++j;
    }
    return crypt;
}

void decrypt(T *crypt, int n){
    int flag;
    int i = 0;
    int j = 0;
    char decrypt[256] = {0};
    while (crypt[i] != '\0'){
        flag = 0; //обработан ли текущий символ
        if (crypt[i] >= 'A' && crypt[i] <= 'Z')
        {
            decrypt[i] = crypt[i] + (n % ENG);
            if (crypt[i] > 'Z') decrypt[i] = 'A' + (crypt[i] - 'Z') - 1;
            flag = 1;
        }
        if (crypt[i] >= 'a' && crypt[i] <= 'z')
        {
            decrypt[i] = crypt[i] + (n % ENG);
            if (crypt[i] > 'z') decrypt[i] = 'a' + (crypt[i] - 'z') - 1;
            flag = 1;
        }
        if (crypt[i] >= 'А' && crypt[i] <= 'Я')
        {
            decrypt[i] = crypt[i] + (n % RUS);
            if (crypt[i] > 'Я') decrypt[i] = 'А' + (crypt[i] - 'Я') - 1;
            flag = 1;
        }
        if (crypt[i] >= 'а' && crypt[i] <= 'я')
        {
            decrypt[i] = crypt[i] + (n % RUS);
            if (crypt[i] > 'я') decrypt[i] = 'а' + (crypt[i] - 'я') - 1;
            flag = 1;
        }
        ++i;
    }
    while(decrypt[j] != '\0'){
        printf("%c", decrypt[j]);
        ++j;
    }
}

void RelocCrypt(T *string, int column){
    char transposition[column];
    printf("Enter the key:");
    for(int j = 0; j < column; j++){
        scanf("%d", transposition[j]);
    }
    int len = sizeof(transposition);
    char ch, temp[len];
    int i, k;
    i=0;
    do{
        for( int j = 0; j < len; ++j){
            ch = string[i];
            if(ch != '\n' && ch != '\0'){
                temp[j] = ch;
                ++i;
            } else {
                temp[j] = '.';
            }
        }
        if(temp[0] != '.')
            for( k = 0; k < len; ++k){
                printf("%c", temp[transposition[k]]);
            }
    }while(ch != '\n' && ch != '\0');
    printf("\n");
}

int main(){
    char string[256];
    char *crypt;
    int n = 0;
    int column = 0;
    printf("Enter some string in a range 256 symbols: ");
    gets(string);
    printf("How long will be shift: ");
    scanf("%d", n);
    crypt = encrypt(string, n);
    decrypt(crypt, n);
    printf("Enter amount of coulumns: ");
    scanf("%d", column);
    RelocCrypt(string, column);
    return 0;
}
