#ifndef _graph_h
#define _graph_h_1
#include "data_structures.h"
#include "stack.h"
#include "heap.h"
#include <cfloat>
//Destiny Reynolds
//ID: 1225345732


void addEdgeFront(NODE*& head, NODE* pNODE);

void addEdgeRear(NODE*& head, NODE* pNODE);

NODE* createNode(int index, int u, int v, int w);

bool isDirected(const char* graphType);

void initializeSingleSource(pVERTEX* V, int n, int source);

void Dijkstra(pVERTEX* V, pNODE* ADJ, HEAP* pHEAP, STACK* pSTACK, int source, int n);

void Relax(pVERTEX *V, int u, int v, double w);

void SinglePair(pVERTEX* V, pNODE* ADJ, HEAP* pHEAP, STACK* pSTACK, int source, int destination, int n);

void SingleSource(pVERTEX* V, pNODE* ADJ, HEAP* pHEAP, STACK* pSTACK, int source, int n);

void PrintPath(pVERTEX* V, int s, int t);

void PrintLength(pVERTEX* V, int s, int t);
#endif