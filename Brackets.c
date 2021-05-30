#include <stdio.h>
#include <stdlib.h>
#define T char
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

typedef struct Node{
     T dat;
     struct Node *next;
}Node;

typedef Node *STACK;

int Push(STACK *stack, T dat){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->dat = dat;
    if(!temp) return true;
    if(!*stack)
       temp->next = NULL;
    else
        temp->next = *stack;
    *stack = temp;
    return false;
}
int Pop( STACK *stack, T *dat ){
    if( !*stack ) return true;
    Node *temp = *stack;
    *dat = temp->dat;
    *stack = temp->next;
    free( temp );
    return false;
}

int main(const int argc, const char **argv){
    STACK head = NULL;
    boolean flag = true;
    printf( "Input string with symbols (){}[]\n" );
    T dat, dat_1;
    while( (dat = getchar()) != '\n')
    {
        if( dat == '('  || dat == '{' || dat == '[' )
        {
           Push( &head, dat );
        }
        if(  dat == ')' || dat == '}' || dat == ']'  )
        {
            if( !head ) { flag = false; break; }

                 if ( head->dat == '(' && dat == ')' ) Pop( &head, &dat_1 );
            else if ( head->dat == '[' && dat == ']' ) Pop( &head, &dat_1 );
            else if ( head->dat == '{' && dat == '}' ) Pop( &head, &dat_1 );
        }
    }
    if(  !head  && flag)
        printf( "Right braces seq\n" );
    else
        printf( "Wrong braces seq\n" );
    return false;
}
