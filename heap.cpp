//Destiny Reynolds
//ID: 1225345732

#include <stdio.h>
#include <string.h>
#include "heap.h"
#include <stdlib.h>

bool MinHeap(HEAP* pHEAP) {
	for (int i = 0; i <= (pHEAP->size - 2) / 2; ++i) {
		//check if left child is smaller than parent
		if (pHEAP->H[2 * i + 1]->key < pHEAP->H[i]->key)
		{
			return false;
		}

		//check if right child is smaller than parent
		if (2 * i + 2 < pHEAP->size && pHEAP->H[2 * i + 2]->key < pHEAP->H[i]->key) {
			return false;
		}
	}
	return true;
}

void BuildHeap(HEAP* pHEAP) {
	for (int i = (pHEAP->size / 2); i >= 0; i--) {
		Heapify(pHEAP, i);
	}
}

void Heapify(HEAP* pHEAP, int i) {
	int smallest = i;
	int left = 2 * i + 1;  // Calculate left child index
	int right = 2 * i + 2; // Calculate right child index

	// Check if left child exists and is smaller than current smallest
	if (left < pHEAP->size &&  pHEAP->H[left]->key < pHEAP->H[smallest]->key) {
		smallest = left;
	}

	// Check if right child exists and is smaller than current smallest
	if (right < pHEAP->size && pHEAP->H[right]->key < pHEAP->H[smallest]->key) {
		smallest = right;
	}

	// If smallest is not the current node, swap and heapify recursively
	if (smallest != i) {
		ELEMENT* temp = pHEAP->H[i];
		pHEAP->H[i] = pHEAP->H[smallest];
		pHEAP->H[smallest] = temp;

		Heapify(pHEAP, smallest); // Recursively heapify the affected subtree
	}
}
HEAP * heapInit(int capacity) {
	HEAP* pHEAP = (HEAP*)calloc(1, sizeof(HEAP));
	pHEAP->capacity = capacity;
	pHEAP->size = 0;
	pHEAP->H = (ELEMENT**)calloc(capacity, sizeof(ELEMENT));

	return pHEAP;
}

void heapInsert(HEAP* pHEAP, double key) {
	ELEMENT *pELEMENT; 

		pELEMENT = (ELEMENT*)calloc(1, sizeof(ELEMENT));
		pELEMENT->key = key;
		pHEAP->H[pHEAP->size++] = pELEMENT;
		Heapify(pHEAP, 0);
        
	pELEMENT = NULL;
}

double ExtractMin(HEAP* pHEAP) {
	ELEMENT* pELEMENT;
	double root = pHEAP->H[0]->key;

	// Swap root with the last element
	pHEAP->H[0]->key = pHEAP->H[pHEAP->size-1]->key;
	free(pHEAP->H[pHEAP->size-1]);
	pHEAP->size--;

	// Restore heap property
	Heapify(pHEAP, 0);

	double key = root;


	// Return NULL or the extracted element based on your needs
	// You should return the actual extracted element here if needed
	return key;
}

void heapDecrease(HEAP* pHEAP, int position, double key) {
	ELEMENT* pELEMENT;
	pHEAP->H[position-1]->key = key;
    Heapify(pHEAP, 0);
	pELEMENT = NULL;
}