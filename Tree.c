#include <stdio.h>
#include <stdlib.h>
#include "geek.h"
#define FOREST 50*10000

typedef struct Node {
  int key;
  struct tnode *left;
  struct tnode *right;
}TreeNode;


TreeNode* treeInsert(TreeNode *t, int data){
    TreeNode *newNode;
    newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode *current = t;
    TreeNode *parent = t;
    if (t == NULL){
        t = newNode;
    }else{
        while(current->key != data){
            parent = current;
            if(current->key > data){
                current = current->left;
                if(current == NULL){
                    parent->left = newNode;
                    return t;
                }
            }else{
                current = current->right;
                if(current == NULL){
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

int BalanceStat(TreeNode *root){
    int Leftcount = 0;
    int Rightcount = 0;
    int Bal = 0;
    if(root){
        if(root->left || root->right){
            if(root->left){
                Leftcount++;
                BalanceStat(root->left);
            }else{

            }
            if(root->right){
                Rightcount++;
                BalanceStat(root->right);
            }
        }
    }
    if(Leftcount = (Rightcount || Rightcount + 1)){
        Bal++;
        printf("The tree is balanced");
    }
    return Bal;
}



int Trees(){
    int *Trees[50];
    for(int i = 0; i < 50; i++){
        *Trees[i] = NULL;
        for(int j = 0; j < 10000; j++){
            int val = rand() % 10000 + 1;
            treeInsert(Trees[i], val);
        }
    }
    return *Trees[50];
}

boolean RecbinSearch(TreeNode *root, int value){
    if(root == NULL)
        return false;
    if(root->key == value)
        return true;

    TreeNode *current = root;
    if(current->key != value){
        if(value < current->key){
            current = current->left;
            RecbinSearch(current->left, value);
        }else{
            current = current->right;
            RecbinSearch(current->right, value);
        }
        if(current == NULL){
            return false;
        }
    }
}

int main(){
    int *a;
    int Bal = 0;
    a = (TreeNode*)malloc(FOREST * sizeof(TreeNode));
    a = Trees();
    BalanceStat(*a);
    for(int i = 1; i < 50; i++){
        Bal = BalanceStat(*(a + i));
    }
    printf("The percent of balanced trees is %d", (Bal / 50) * 100);
    return 0;
}
