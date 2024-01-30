void mySort(int d[], unsigned int n)
{
  int i, j, k;
  	  //Iterates through the array until the second last array index
      for (i = 0; i < n - 1; i++) {
    	  //Iterates through the remaining unsorted array while 
    	  //- i ensures no repeat sort of the previous inner loop
          for (j = 0; j < n - i - 1; j++) {
        	  //Does the comparing and swapping, 
        	  //compares current value with the next value 
        	  //if true then they swap
              if (d[j] > d[j + 1]) {
                  // Swaps arr[j] and arr[j+1] using the temp var K
                  k = d[j];
                  d[j] = d[j + 1];
                  d[j + 1] = k;
              }
          }
      }
}
