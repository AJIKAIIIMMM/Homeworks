#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int dat;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
    int size;
} List;

void init(List* lst){
    lst->head = NULL;
    lst->size = 0;
}

void ins(List *lst, int data){
    Node *new = (Node*) malloc(sizeof(Node));
    new->dat = data;
    new->next = NULL;

    Node *current = lst->head;
    if (current == NULL){
        lst->head = new;
        lst->size++;
        return;
    }else{
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}

Node* CopyList(List *lst){
    if(lst->head != NULL) {
        typedef struct Node1{
            int dat;
            struct Node1 *next;
        }Node1;
        typedef struct {
            Node1 *head;
            int size;
        } List1;
        List1* lst1;
        lst1->head = NULL;
        lst1->size = 0;

        Node1 *new1 = (Node1*) malloc(sizeof(Node));
        new1->dat = lst->head;
        new1->next = NULL;

        Node *current1 = lst1->head;
        if (current1 == NULL){
            lst1->head = lst;
            lst1->size++;
            return;
        }else{
            while(current1->next != NULL){
            current1 = current1->next;
            }
        current1->next = lst;
        lst1->size++;
    }
    }else{
        return 0;
    }
}

Node* InsertionSort(List *lst)
{
    if(!lst || !lst->head)
        return printf("The list sorted");
    else printf("The list unsorted");

    Node ptr = lst->head;
    Node result = lst;
    result->head = NULL;

    while(ptr)
    {
        Node temp = ptr;
        ptr = ptr->head;
        result = SortedInsert(result, temp);
    }

    return result;
}

int main(const int argc, const char **argv){
    List *lst = (List*) malloc(sizeof(List));
    init(lst);
    ins(lst, 1);
    ins(lst, 10);
    CopyList(lst);
    return 0;
}


