/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>

int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	int swap;
	for (int i = 0; i < (len - 1); i++)
	{
		for (int j = 0; j < (len - i - 1); j++)
		{
			if (A[j] > A[j + 1])
			{
				swap = A[j];
				A[j] = A[j + 1];
				A[j + 1] = swap;
			}
		}
	}
	int i = 0;
	while (i<len-3)
	{
		if (A[i] == A[i + 2])
			i = i + 3;
		else
			return A[i];
	}
	return A[len-1];
}