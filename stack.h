//Destiny Reynolds
//ID: 1225345732

#ifndef _stack_h
#define _stack_h 1



typedef struct sNODE {
    double data;
    sNODE* next;
}sNODE;

typedef struct TAG_STACK{ 
    sNODE* top;
}STACK;

STACK* initializeStack();

bool isStackEmpty(STACK *stack);

void push(STACK *stack, int value);

int pop(STACK *stack);

int peek(STACK *stack);
#endif