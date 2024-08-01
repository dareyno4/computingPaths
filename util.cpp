//Destiny Reynolds
//ID: 1225345732

#include <stdio.h>
#include <string.h>
#include "util.h"

int nextInstruction(char *Word, double *Key, int *s, int *t, int *source, int *destination) 
{
	int returnVar;

	fscanf(stdin, "%s", Word);
	
	if (strcmp(Word, "Stop") == 0) return 1;
	if (strcmp(Word, "PrintADJ") == 0) return 1;

	if (strcmp(Word, "SingleSource") == 0) {
		returnVar = fscanf(stdin, "%d", source);
		if (returnVar == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}


	if (strcmp(Word, "SinglePair") == 0) {
		returnVar = fscanf(stdin, "%d %d", source, destination);
		if (returnVar == 2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (strcmp(Word, "PrintLength") == 0) {
		returnVar = fscanf(stdin, "%d %d", s, t);
		
		if (returnVar == 2) {
			return 1;
		}
		else {
			return 0;
		}
	}
    if (strcmp(Word, "PrintPath") == 0) {
		returnVar = fscanf(stdin, "%d %d", s, t);

        if(returnVar == 2) {
            return 1;
        }
        else {
            return 0;
        }
    }
	return 0;
}