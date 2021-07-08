#pragma once

typedef enum { STAR, COLON, POINT , SPACE } SIGN;
typedef struct {
	int n;//chars to skip
	int p;//evaluateDifference
}Pair;

char* createSequence(char* fileName);
char* createSigns(char* SEQ1, char* SEQ2,int n);
char copmare(char c1, char c2);
void printSigns(char* SEQ3, int numOfChars, int sizeOfComp,int n);
int getCount(char* SEQ, int size, int numOfComp);
int evaluateDifference(char* SEQ1, char* SEQ2, int n);
void getNewSize(int* newSize, int size);
Pair* createAllPairs(char* SEQ1, char* SEQ2);
int comparePair(void* pair1, void* pair2);
Pair* findLocation(Pair* pairs,int size,const Pair p);