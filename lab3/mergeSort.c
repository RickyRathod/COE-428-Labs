#include "mySort.h"
#include "metrics.h"
#include <stdio.h>

void myMerge(int array[], int a, int b, int c, int d)
{
	//3 indices and 1 temp
	//i, j represent the arrays to be merged
	//while b and d represent the end of the first and second subarray
	int temp[MAX_SIZE_N_TO_SORT];
	int i, j, k;
	i = a;
	j = c;
	k = 0;
		
		//responsible for merging the segments by compareing elements
		//in the indices i and j which then copies them into a temp array
		//compare the left and right subarray 
		while((myCompare(i, b) <= 0) && (myCompare(j, d) <= 0))
		{
			//if the element at indices i are less than j then 
			//it get copied into the temp array where both i and k get incremented
			//otherwise j is copied into the temp array 
			if(myCompare(array[i], array[j]) < 0)
				myCopy(&array[i++], &temp[k++]);
			else
				myCopy(&array[j++], &temp[k++]);
		}
		
		//for both sub arrays*
		//it will loop through the arrays until 
		//there is nothing left for it to compare
		
		//also copies the segments into the temp array
		while(myCompare(i, b) <= 0)
		{
			myCopy(&array[i++], &temp[k++]);
		}

		while(myCompare(j, d) <= 0)
		{
			myCopy(&array[j++], &temp[k++]);
		}
		
		//lastly this swaps the merged elements into a new full array
		for(i=a, k=0; i <= d; i++, k++)
		{
			mySwap(&array[i], &temp[k]);
		}	
}

//recursive function that sorts the given arrays

//basically responsible for splitting the arrays until it reaches a base case
//and then the above "mergeSort" merges them together
void mySort(int array[], unsigned int first, unsigned int last)
{
	int middle;
		
		if(first < last)
		{
			middle = (first + last) / 2;
			mySort(array, first, middle);
			mySort(array, (middle + 1), last);
			myMerge(array, first, middle, (middle +1), last);
		}
}