//Destiny Reynolds
//ID: 1225345732

#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int recent_source = -1;
int recent_destination = -1;
int recent_computation_type = -1;

NODE* createNode(int index, int u, int v, int w) {
    NODE* pNODE = (NODE*)calloc(1, sizeof(NODE));
    pNODE->index = index;
    pNODE->u = u;
    pNODE->v = v;
    pNODE->w = w;
    pNODE->next = NULL;
    return pNODE;
}

void addEdgeFront(NODE*& head, NODE* pNODE) {
    pNODE->next = head;
    head = pNODE;
}

void addEdgeRear(NODE*& head, NODE* pNODE) {
    if (!head) {
        head = pNODE;
    }
    else {
        NODE* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = pNODE;
    }
}

bool isDirected(const char* graphType) {
    if (strcmp(graphType, "DirectedGraph") == 0) {
        return true;
    }
    return false;
}
void initializeSingleSource(pVERTEX *V, int n, int source) {
    for (int i = 1; i <=n; i++) {
        V[i]->key = DBL_MAX;
        V[i]->pi = -1;
    }
    V[source]->key = 0;
}

void Dijkstra(pVERTEX* V, pNODE* ADJ, HEAP* pHEAP, STACK* pSTACK, int source, int n) {
    initializeSingleSource(V, n, source);
    int position = 0;
    for (int i = 1; i <= n; i++) {
        V[i]->position = position;
        heapInsert(pHEAP, V[i]->key);
        position++;
    }
    while (pHEAP->size != 0) {
        int u = ExtractMin(pHEAP);
        push(pSTACK, u);
        for (int i = 1; i <= n; ++i) {
            pNODE temp = ADJ[i];
            while (temp) {
                Relax(V, temp->u, temp->v, temp->w);
                if (V[temp->v]->key == temp->u + temp->w) {
                    heapDecrease(pHEAP, V[temp->v]->position, V[temp->v]->key);
                }
                temp = temp->next;
            }
        }

    }
        
}
void Relax(pVERTEX* V, int u, int v, double w) {
    if (V[v]->key > V[u]->key + w) {
        V[v]->key = V[u]->key + w;
        V[v]->pi = u;
    }
}

void SinglePair(pVERTEX* V, pNODE* ADJ, HEAP *pHEAP, STACK *pSTACK, int source, int destination, int n) {
    recent_source = source;
    recent_destination = destination;
    recent_computation_type = 0;

    Dijkstra(V, ADJ, pHEAP, pSTACK, source, n);
}

void SingleSource(pVERTEX* V, pNODE* ADJ, HEAP *pHEAP, STACK *pSTACK, int source, int n) {
    recent_source = source;
    recent_destination = -1; // No specific destination
    recent_computation_type = 1; // SingleSource

    Dijkstra(V, ADJ, pHEAP, pSTACK, source, n);
}

void PrintPath(pVERTEX* V, int s, int t) {
    if (recent_computation_type == 1 && recent_source == s ||
        recent_computation_type == 0 && recent_source == s && recent_destination == t) {
        if (V[t]->key == DBL_MAX) {
            printf("There is no path from %d to %d.\n", s, t);
        }
        else {
            // Print the path using predecessors
            printf("The shortest path from %d to %d is:\n", s, t);
            int path[100]; // Assuming a maximum path length of 100
            double distance[100];
            int count = 0;
            int temp = t;

            while (temp != -1) {
                path[count] = temp;
                distance[count] = V[temp]->key;
                count++;
                temp = V[temp]->pi;
            }

            for (int i = count - 1; i > 0; i--) {
                printf("[%d:    %.2f]-->", path[i], distance[i]);
            }
            printf("[%d:    %.2f].\n", path[0], distance[0]);
        }
    }
    else {
        fprintf(stderr,"Error: Invalid instruction.");
    }
}

void PrintLength(pVERTEX* V, int s, int t) {
    if (recent_computation_type == 1 && recent_source == s ||
        recent_computation_type == 0 && recent_source == s && recent_destination == t) {
        if (V[t]->key == DBL_MAX) {
            printf("There is no path from %d to %d.\n", s, t);
        }
        else {
            printf("The length of the shortest path from %d to %d is:     %.2f\n", s, t, V[t]->key);
        }
    }
    else {
        printf("There is no path from %d to %d.\n", s, t);
    }
}