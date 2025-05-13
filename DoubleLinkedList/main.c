#include<stdio.h>
#include<stdlib.h>
#include "DoubleLinkedList.h"

int main() {
    insertNth(2, 1); // List: 2
    insertNth(3, 2); // List: 2, 3
    insertNth(4, 1); // List: 4, 2, 3
    insertNth(5, 2); // List: 4, 5, 2, 3
    insertNth(6, 4); // List: 4, 5, 2, 6, 3
    insertNth(7, 3); // List: 4, 5, 7, 2, 6, 3
    deleteNth(2); // List: 4, 7, 2, 6, 3
    deleteBegin(); // List: 7, 2, 6, 3
    printList(HEAD);
    reverse();
    printList(HEAD);
    return 0; 
}
