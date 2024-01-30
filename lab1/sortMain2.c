#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"
int main(int argc, char * argv[])
{
	
	//argc reps the number or arg passed through the system
	//argv is an array of string that hold the cmd args 
	//where argv[0] holds the name of the program and 
	//argv[1] to argv[argc-1] hold the remaining cmd args
	
	
 int data[100000]; /* Array of ints to sort */
 int nDataItems; /* number of actual items in the array */ 
 int i;
 //checks for cmd args where if argc > 1 there are indeed cmd args
 if (argc > 1) {
	 //if no cmd args, nDataitems is set to #of args passed not including itself (argc - 1)
         nDataItems = argc-1;
         //iterates through the args starting at index 1 and converts strings into ints
         //I start at 1 so it doesnt include the program name (argv)
         //data[i-1] doesnt include itself and atoi is used to convert the string argv[] into integers
     for(i = 1; i < argc; i++) {
 		data[i-1]=atoi(argv[i]);

         }
     
     //if the above is false then it uses the hardcoded data 
     } else { 
         /* Test data */
 		nDataItems = 4;
 		data[0] = 30;
 		data[1] = 40;
 		data[2] = 10;
 		data[3] = 20;
 }
 mySort(data, nDataItems);

 /* Check that the data array is sorted. */
 for(i = 0; i < nDataItems-1; i++) {
 if (data[i] > data[i+1]) {
 fprintf(stderr, "Sort error: data[%d] (= %d)"
 " should be <= data[%d] (= %d)- -aborting\n",
 i, data[i], i+1, data[i+1]);
 exit(1);
 }
 }

 /* Print sorted array to stdout */
 for(i = 0; i < nDataItems; i++) {
 printf("%d\n", data[i]);
 }
 exit(0);
}