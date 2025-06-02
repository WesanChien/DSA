#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct bstNode{
    int data;
    struct bstNode* left;
    struct bstNode* right;
};

struct bstNode* insert(struct bstNode* rootPtr, int data){
    if(rootPtr == NULL){
        struct bstNode* newNode = (struct bstNode*)malloc(sizeof(struct bstNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if(data >= rootPtr->data){
        rootPtr->right = insert(rootPtr->right, data);
    }
    else {
        rootPtr->left = insert(rootPtr->left, data);
    }
    return rootPtr;
}

bool search(struct bstNode* rootPtr, int data){
    if(rootPtr == NULL) return false;
    else if(data == rootPtr->data) return true;
    else if(data >= rootPtr->data) {
        search(rootPtr->right, data);
    }
    else{
        search(rootPtr->left, data);
    }
}

int findMin(struct bstNode* rootPtr){
    if(rootPtr == NULL) {
        printf("The tree is empty.\n");
        return -1;
    }
    else{
        struct bstNode* tmp = rootPtr;
        while(tmp->left != NULL){
            tmp = tmp->left;
        }
        return tmp->data;
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int findHeight(struct bstNode* rootPtr){
    if(rootPtr == NULL){
        return -1;
    }
    else{
        return max(findHeight(rootPtr->left), findHeight(rootPtr->right)) + 1;
    }
}

void preorder(struct bstNode* rootPtr){
    if(rootPtr == NULL) return;
    printf("%d ", rootPtr->data);
    preorder(rootPtr->left);
    preorder(rootPtr->right);
}

void inorder(struct bstNode* rootPtr){
    if(rootPtr == NULL) return;
    inorder(rootPtr->left);
    printf("%d ", rootPtr->data);
    inorder(rootPtr->right);
}

void postorder(struct bstNode* rootPtr){
    if(rootPtr == NULL) return;
    postorder(rootPtr->left);
    postorder(rootPtr->right);
    printf("%d ", rootPtr->data);
}

struct bstNode* delete(struct bstNode* rootPtr, int data){
    if(rootPtr == NULL) return rootPtr;
    else if(data > rootPtr->data){
        delete(rootPtr->right, data);
    }
    else if(data < rootPtr->data){
        delete(rootPtr->left, data);
    }
    else{ // found the node
        if(rootPtr->left == NULL && rootPtr->right == NULL){
            free(rootPtr);
            rootPtr = NULL;
        }
        else if(rootPtr->left == NULL){
            struct bstNode* tmp = rootPtr;
            rootPtr = rootPtr->right;
            free(tmp);
        }
        else if(rootPtr->right == NULL){
            struct bstNode* tmp = rootPtr;
            rootPtr = rootPtr->left;
            free(tmp);
        }
        else{
            struct bstNode* tmp = findMin(rootPtr->right);
            rootPtr->data = tmp->data;
            rootPtr->right = delete(rootPtr->right, tmp->data);
        }
    }
    return rootPtr;
}

int main(){
    struct bstNode* root1 = NULL;
    root1 = insert(root1, 50); 
    root1 = insert(root1, 80);
    root1 = insert(root1, 70);
    root1 = insert(root1, 40);
    if(search(root1, 30) == true){
        printf("Found.\n");
    }
    else{
        printf("Not found.\n");
    }
    printf("%d\n", findMin(root1));
    printf("%d\n", findHeight(root1));
    preorder(root1);
    return 0;
}