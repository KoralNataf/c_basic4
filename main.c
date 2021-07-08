//////////////////////////////////////
//Koral Nataf : 20872625            //
//Gal Or: 316083690	                //
//**we solved all premissiom tasks**//
//////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seq.h"

#define PRINT_SEQUENCES
		
int main(int args,char* argc[])
{
	if (args != 3) {
		printf("Wrong number of argument! Only two argument is allowed\nPlease enter two file names and try again!\n"); //if did not have 2 file names
		return;
	}
	char* SEQ1 = createSequence(argc[1]);//create sequence 1
	char* SEQ2 = createSequence(argc[2]);//create sequence 2
	int maxN = strlen(SEQ1) - strlen(SEQ2);
	int n,temp,res ;
	printf("Please Enter Number Of Chars To Skip(between 0 - %d): ",maxN);
	temp=scanf("%d", &n);
	while (n > maxN || n < 0 )
	{
		printf("Number Of Char To Skip Must Between 0 - %d ! Try Again: ", maxN);
		temp = scanf("%d", &n);
	}
	res = evaluateDifference(SEQ1, SEQ2, n);

#ifdef PRINT_SEQUENCES //if we dont wont all pring -> cancle the define
	printf("%s\n", SEQ1);
	for (int i = 0; i < n; i++)
		printf(" ");
	printf("%s\n", SEQ2);
	int newSize, size = strlen(SEQ2);
	getNewSize(&newSize, size);
	char* SEQ3 = createSigns(SEQ1, SEQ2, n);
	printSigns(SEQ3, newSize, size,n);
	free(SEQ3);
#endif

	printf("\nEvaluate The Difference Between SEQ1 And SEQ2 Calculate By : Count Stars - Count Colons = %d\n", res);
	Pair* pairs=createAllPairs(SEQ1, SEQ2);
	printf("The sorted array of all pairs is:\n");
	for (int i = 0; i < maxN; i++)
		printf("(%d,%d) ", pairs[i].n, pairs[i].p);

	Pair p = {5,-5};//search a pair that the value op p = -5
	Pair* foundPair =findLocation(pairs, maxN, p);

	if (!foundPair) printf("\nPair not found!\n");
	else
		printf("\nfound pair (%d,%d)\n", foundPair->n, foundPair->p);
	
	
	//free 
	free(SEQ1);
	free(SEQ2);
}
