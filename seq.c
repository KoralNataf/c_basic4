#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seq.h"
#define COLON_SIZE 9
#define POINT_SIZE 11

char colonSign[][5] = { "STA","NEQK","NDEQ","NHQK","QHRK","MILV","MILF","HY","FYW" };
char pointSign[][7] = { "CSA","ATV","SAG","STNK","STPA","SGND","SNDEQK","NDEQHK","NEQHRK","FVLIM","HFY" };

char* createSequence(char* fileName)
{//create sequence from file
	FILE* f = fopen(fileName, "r");
	if (!f) return NULL;
	fseek(f, 0, SEEK_END);
	int size = ftell(f)+1;
	rewind(f);
	char* seq = (char*)malloc(size*sizeof(char));
	if (!fgets(seq, size, f)) return NULL;
	fclose(f);
	return seq;
}

char* createSigns(char* SEQ1, char* SEQ2, int n)
{//create a compressed string of signs
	int newSize,size = strlen(SEQ2);
	getNewSize(&newSize, size);

	char* SEQ3 = (char*)malloc(newSize * sizeof(char));
	char temp, res;
	int x = 0;
	for (int i = 0; i < newSize; i++)
	{
		temp = 0;
		for (int j = 6; j >= 0; j -= 2)
		{
			res = copmare(SEQ1[n + x], SEQ2[x]);
			res = res << j;
			temp = temp | res;
			x++;
			if (x > size) break;
		}
		SEQ3[i] = temp;
		if (x>size)break;
	}
	return SEQ3;
}

char copmare(char c1, char c2)
{//check the difference between two chars
	if (c1 == c2)
		return 0; // for *

	int i;
	for (i = 0; i < COLON_SIZE; i++)
		if (strchr(colonSign[i], c1) && strchr(colonSign[i], c2))
			return 1;  // for :

	for (i = 0; i < POINT_SIZE; i++)
		if (strchr(pointSign[i], c1) && strchr(pointSign[i], c2))
			return 2; // for .

	return 3; // for " "
}

void printSigns(char* SEQ3, int numOfChars, int sizeOfComp,int n)
{//pring the compressed String as signs
	for (int i = 0; i < n; i++)
		printf(" ");

	char temp, temp1;
	char mask = 3;
	for (int i = 0; i < numOfChars; i++)
	{
		temp = SEQ3[i];

		for (int j = 6; j >= 0; j -= 2)
		{
			sizeOfComp--;
			temp1 = temp >> j;
			temp1 = temp1 & mask;

			switch (temp1)
			{
			case STAR:
				printf("*");
				break;
			case COLON:
				printf(":");
				break;
			case POINT:
				printf(".");
				break;
			case SPACE:
				printf(" ");
				break;
			default:
				break;
			}
			if (sizeOfComp <= 0) break;
		}
		if (sizeOfComp <= 0) break;
	}
	printf("\n");
}

int getCount(char* SEQ, int size,int numOfComp)
{//calculate  countStars - countColons
	int countStars = 0, countColons = 0;
	
	char temp, temp1;
	char mask = 3;
	for (int i = 0; i < size; i++)
	{
		temp = SEQ[i];

		for (int j = 6; j >= 0; j -= 2)
		{
			numOfComp--;
			temp1 = temp >> j;
			temp1 = temp1 & mask;

			switch (temp1)
			{
			case STAR:
				countStars++;
				break;
			case COLON:
				countColons++;
				break;
			default:
				break;
			}
			if (numOfComp <= 0) break;
		}
		if (numOfComp <= 0) break;
	}
	return countStars - countColons;

}

int evaluateDifference(char* SEQ1, char* SEQ2, int n)
{
	char* SEQ3 = createSigns(SEQ1, SEQ2, n);
	int newSize,size =strlen(SEQ2);
	getNewSize(&newSize,size);
	int count = getCount(SEQ3, newSize, size);
	free(SEQ3);
	return count;
}

void getNewSize(int* newSize,int size)
{//count number of bytes for compressed string
	if (size % 4 == 0)
		*newSize = size / 4;
	else
		*newSize = (size / 4) + 1;

}

Pair* createAllPairs(char* SEQ1, char* SEQ2)
{//creat array of pairs and sort the array by p
	int maxN = strlen(SEQ1) - strlen(SEQ2);
	Pair* pairs = (Pair*)malloc(maxN * sizeof(Pair));

	for (int i = 0; i < maxN; i++)
	{
		pairs[i].n = i;
		pairs[i].p = evaluateDifference(SEQ1, SEQ2, i);
	}
	qsort(pairs, maxN, sizeof(Pair), comparePair);
	return pairs;
}

int comparePair(void* pair1, void* pair2)
{//compare two pairs by the value of p
	Pair* p1 = (Pair*)pair1;
	Pair* p2 = (Pair*)pair2;

	return p1->p - p2->p;
}

Pair* findLocation(Pair* pairs, int size, const Pair p)
{//binary search of pair in the array by p
	int* foundPair =(Pair*)bsearch(&p, pairs, size, sizeof(Pair), comparePair);
	return foundPair;
}