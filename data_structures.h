//Destiny Reynolds
//ID: 1225345732

#ifndef _data_structures_h
#define _data_structures_h 1

#define WHITE 0
#define GRAY 1
#define BLACK 2


//vertex
typedef struct TAG_VERTEX{
    int index;
    int color;
    double key;
    int pi;
    int position;
}VERTEX;
typedef VERTEX *pVERTEX;

//edge
typedef struct TAG_NODE {
    int index;
    int u;
    int v;
    double w;
    TAG_NODE *next;
}NODE;
typedef NODE *pNODE;

typedef VERTEX ELEMENT;
typedef ELEMENT *pELEMENT;

typedef struct TAG_HEAP {
	int capacity;
	int size;
	pELEMENT* H;
}HEAP;

typedef HEAP *pHEAP;
#endif