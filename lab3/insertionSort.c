#include "mySort.h"
#include "metrics.h"

void mySort(int array[], unsigned int first, unsigned int last)
    {
	//2 indices 1 temp
	int i, j, k;
	
	//starting from 1 this forloop iterates until "last"
	//we consider the first element to already be sorted
	for(i = 1; i < last + 1; i++){
		
		//copies the elements in index "i" to the temp var k
		//then i - 1 is initialized to represent the last index of 
		//the new sorted array
		myCopy(&array[i], & k);
		j = (i - 1);
		
		//will continue to compare for j >= 0 and the element at under j is >= k
		//swaps elements at j at index j + 1 "moves it to the right"
		//then j-- to continue to loop and check previous elements
		
		//compares the values stored in k with its left at index j
		//if left > k then they swap
		while(j >= 0 && myCompare(array[j], k) >= 0){
			mySwap(&array[j], &array[j + 1]);
			j--;
		}
		
		//copies the value of k into the array at the correct position "j+1" 
		myCopy(&array[j + 1], &k);
	}
    } 

