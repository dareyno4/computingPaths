//Destiny Reynolds
//ID: 1225345732

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "util.h"
#include "heap.h"
#include "stack.h"


int main(int argc, char** argv) {
    FILE* fp;
    int flag, m, n, u, v, w, edgeIndex, vertIndex, returnVar, s, t, source, destination;
    const char* graphType;
    double key;
    char Word[100];

    if (argc < 4) {
        fprintf(stderr, "Usage: ./PJ3  %s <InputFile> <GraphType> <Flag>\n", argv[0]);
        exit(0);
    }
    flag = atoi(argv[3]);
    graphType = argv[2];

    fp = NULL;
    fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
    }
    //process n and m values
    fscanf(fp, "%d %d", &n, &m);
    //make a new array of n elements that contain pointers to the vertices
    pVERTEX* V;
    V = (pVERTEX*)calloc(n + 1, sizeof(pVERTEX));
    for (int i = 1; i <= n; i++) {
        V[i] = (VERTEX*)calloc(1, sizeof(VERTEX));
    }
    pNODE* ADJ;
    ADJ = (pNODE*)calloc(n + 1, sizeof(pNODE));
    for (int i = 1; i <= n; i++) {
        ADJ[i] = (NODE*)calloc(1, sizeof(NODE));
        ADJ[i] = NULL;
    }

    while (fscanf(fp, "%d %d %d %d", &edgeIndex, &u, &v, &w) == 4) {
        NODE* newNode = createNode(edgeIndex, u, v, w);
        bool val = isDirected(graphType);
        if (val == true) {
            if (flag == 1) {
                addEdgeFront(ADJ[u], newNode);
            }
            else if (flag == 2) {
                addEdgeRear(ADJ[u], newNode);
            }
        }
        else {
            if (flag == 1) {
                addEdgeFront(ADJ[u], newNode);
                NODE* mirrorNode = createNode(edgeIndex, v, u, w);
                addEdgeFront(ADJ[v], mirrorNode);
            }
            else if (flag == 2) {
                addEdgeRear(ADJ[u], newNode);
                NODE* mirrorNode = createNode(edgeIndex, v, u, w);
                addEdgeRear(ADJ[v], mirrorNode);
            }
        }


    }
    fclose(fp);

    //initialize min-heap of capacity n and stack of capacity n
    HEAP* pHEAP = heapInit(n);
    STACK* pSTACK = initializeStack();

    while (1) {
        returnVar = nextInstruction(Word, &key, &s, &t, &source, &destination);
        if (returnVar == 0) {
            fprintf(stderr, "Invalid instruction.\n");
            continue;
        }

        if (strcmp(Word, "Stop") == 0) {
            return 0;
        }
        if (strcmp(Word, "PrintADJ") == 0) {
            for (int i = 1; i <= n; ++i) {
                NODE* temp = ADJ[i];
                if (ADJ[i] == NULL) {
                    break;
                }
                fprintf(stdout, "ADJ[%d]:", i);
                while (temp) {
                    fprintf(stdout, "-->[%d %d: %.2f]", temp->u, temp->v, temp->w);
                    temp = temp->next;
                }
                printf("\n");
            }
            continue;
        }

        if (strcmp(Word, "SingleSource") == 0) {
            SingleSource(V, ADJ, pHEAP, pSTACK, source, n);
            continue;
        }


        if (strcmp(Word, "SinglePair") == 0) {
            SinglePair(V, ADJ, pHEAP, pSTACK, source, destination, n);
            continue;
        }
        if (strcmp(Word, "PrintLength") == 0) {
            PrintLength(V, s, t);
            continue;
        }
        if (strcmp(Word, "PrintPath") == 0) {
            PrintPath(V, s, t);
            continue;
        }
    }
}