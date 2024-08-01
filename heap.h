//Destiny Reynolds
//ID: 1225345732

#ifndef _head_h
#define _head_h 1
#include "data_structures.h"

bool MinHeap(HEAP*);
void Heapify(HEAP*, int);
void BuildHeap(HEAP*);
double ExtractMin(HEAP*);
HEAP * heapInit(int);
void heapInsert(HEAP*, double);
void heapDecrease(HEAP*, int, double);

#endif