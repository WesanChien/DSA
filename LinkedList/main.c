#include<stdio.h>
#include<stdlib.h>
#include "LinkedList.h"

int main() {
    // int x, k;
    // printf("How many nodes you want?");
    // scanf("%d", &x);
    // for(int i = 0; i < x; i++){
    //     printf("The node value is: ");
    //     scanf("%d", &k);
    //     insertBegin(k);
    // } 
    insertNth(2, 1); // List: 2
    insertNth(3, 2); // List: 2, 3
    insertNth(4, 1); // List: 4, 2, 3
    insertNth(5, 2); // List: 4, 5, 2, 3
    insertNth(6, 2); // List: 4, 6, 5, 2, 3
    deleteNth(2); // List: 4, 5, 2, 3
    printList(HEAD);
    reverse(); // List: 3, 2, 5, 4
    printList(HEAD);
    return 0;
}


