#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

STACK* initializeStack() {
    STACK* pSTACK = (STACK*)calloc(1, sizeof(STACK));
    pSTACK->top = NULL;

    return pSTACK;
}

bool isStackEmpty(STACK *stack) {
    return stack->top == nullptr;
}
//Destiny Reynolds
//ID: 1225345732

void push(STACK *stack, int value) {
    sNODE* newNode = (sNODE*)calloc(1, sizeof(sNODE*));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;

}

int pop(STACK *stack) {
    if (isStackEmpty(stack)) {
        fprintf(stderr, "Stack is empty");
        return -1;
    }
    sNODE* temp = stack->top;
    int poppedVal = temp->data;
    stack->top = stack->top->next;
    delete temp;
    return poppedVal;
}

int peek(STACK *stack) {
    if(isStackEmpty(stack) == true) {
        fprintf(stderr, "Stack is empty");
        return -1;
    }
    return stack->top->data;
}