#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 8
#define WIDTH 8
#define OBST 8
#define KING 55

int board [HEIGHT][WIDTH];
// Ходы короля
int possible [][1] = {
    {-1, 0},{0, 1},
    {1, 0},{0, -1}
};
// Задание №1
int Bull (int n);
// Задание №2
int Square (int a, int b);
// Задание №3
int Parity (int a, int b);
// Задание №4
void annul();

int obstacles (int n);

void PrintBoard();

int CheckBoard ();

int checkObst(int x, int y);

int isPossible(int x, int y);

int KingMove (int x, int y, int move);

int main()
{
    int Task = 0;
    while (1){
        printf("Choose the task(1-4):");
        scanf("%d", &Task);
        switch (Task){
            case 1:{
                int n = 0;
                printf("Enter the number, which you want to transfer to bull:");
                scanf ("%d", &n);
                Bull (n);
                printf("\nPress enter to continue");
                getch();
                system("cls");
                break;
            }
            case 2: {
                int a, b;
                printf("Enter the number, which you want to square:");
                scanf ("%d", &a);
                printf("Enter the square number:");
                scanf ("%d", &b);
                Square (a, b);
                printf("\nPress enter to continue");
                getch();
                system("cls");
                break;
            }
            case 3: {
                int a, b;
                printf("Enter the number, which you want to square:");
                scanf ("%d", &a);
                printf("Enter the square number:");
                scanf ("%d", &b);
                Parity(a, b);
                printf("\nPress enter to continue");
                getch();
                system("cls");
                break;
            }
            case 4:{
                annul();
                obstacles(1);
                PrintBoard();
                KingMove(1, 0, 1);
                printf("\n");
                printf("\nPress enter to continue");
                getch();
                system("cls");
                break;
            }
    return 0;
        }
    }
}

// Задание №1
int Bull (int n){
    if ( n >= 2 ){
        Bull( n / 2 );
    }
    printf("%d", n % 2);
}
// Задание №2
int Square (int a, int b){
   if (b == 0) {
        return 1;
   }
    else if (b == 1){
        printf("%d", a);
        return a;
    }
    else {
        return Square( a * a, b - 1);
    }
}
// Задание №3
int Parity (int a, int b){
    if (b == 0){
        printf("%d", a);
        return 1;
    }
    else if (b == 1){
        printf("%d", a);
        return a;
    }
    else if (b % 2 == 0 ){
        return Parity( a * a, b / 2);
    }
    else{
        return Parity( ((a * a) * a), --b);
    }
}
// Задание №4
void annul(){
    for (int i = 0; i < HEIGHT; ++i){
        for (int j = 0; j < WIDTH; ++j){
            board[i][j] = 0;
        }
    }
}


void PrintBoard(){
    for (int i = 0; i < HEIGHT; ++i){
        for (int j = 0; j < WIDTH; ++j){
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int checkObst(int x, int y){
    for (int i = 0; i < HEIGHT; ++i){
        for (int j = 0; j < WIDTH; ++j){
            if (board[i][j] != 0)
                if (!(i == x && j == y)){
                    if (i - x == 0 || j - y == 0) return 0;
                    if (abs(i - x) == abs(j - y)) return 0;
                }
        }
    }
    return 1;
}

int CheckBoard (){
    for (int y = 0; y < HEIGHT; ++y){
        for (int x = 0; x < WIDTH; ++x){
            if (board[y][x] != 0){
                if (checkObst(y, x) == 0)
                    return 0;
            }
        }
    }
    return 1;
}

int obstacles (int n){
    if (CheckBoard() == 0) return 0;
    if (n == OBST + 1) return 1;
     for (int y = 0; y < HEIGHT; ++y){
        for (int x = 0; x < WIDTH; ++x){
            if (board[y][x] == 0){
                board[y][x] = 1;
                if (obstacles(n + 1))
                    return 1;
                board[y][x] = 0;
            }
        }
    }
    return 0;
}



int isPossible(int x, int y){
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && board[y][x] == 0;
}

int KingMove (int x, int y, int move){
    int nextX;
    int nextY;
    board[y][x] = move;
    if (move > KING) return 1;
    for (int i = 0; i < 3; ++i){
        nextX = x + possible[i][1];
        nextY = y + possible[i][0];
        if (isPossible(nextX, nextY) && KingMove(nextX, nextY, move + 1))
            return 1;
    }
    board[y][x] = 0;
    PrintBoard();
    return 0;
}

