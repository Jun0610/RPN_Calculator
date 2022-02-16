#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"

//constrsucts a new node in the stack
Node * cons(float key, Node * list){
    Node * newNode = malloc(sizeof(Node));
    newNode -> val = key;
    newNode -> next = list;
    return newNode;
}

void removeNode(stack * s){
    Node * todelete = s -> top;
    s -> top =  s -> top -> next;
    free(todelete);
    return;
}

void push(stack * s, float key){
    s -> top = cons(key, s -> top);
}


bool pop(stack * s, float * num){
    if(s -> top == NULL){
        return false;
    }
    *num = s -> top -> val;
    removeNode(s);
    return true;
}

void freeStack(stack * s){
    Node * tofree = NULL;
    while(s -> top != NULL){
        tofree = s -> top;
        s -> top = s -> top -> next;
        free(tofree);
    }

    free(s -> top);
    free(s);
}
