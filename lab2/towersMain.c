#include <stdio.h>
#include <stdlib.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;
    
    //for two line arg, "Tower 10"
    //no additional arguments were given, so command line only reads towers 	
    if (argc == 2) {
        n = atoi(argv[1]);
    }
    
    // Three line arguments (numberDisks fromID toID) (towers 8 1 2 )
    else if(argc == 4){
    	  n = atoi(argv[1]);
    	  from = atoi(argv[2]);
    	  dest = atoi(argv[3]);
    	}
        // Checks if tower IDs are valid
        //based on the conditions the FromID, toID must be between 1 and 3 including 3
        //and must not be equal to each other otherwise error
        //conditions below are so we MUST input the correct param otherwise Error, ...
    if(from==dest || from>3 || dest > 3 || from==0 || dest == 0){
    	printf("towers must not be equal or greater than 3");
    	exit(1);
    }
    towers(n, from, dest);
    exit(0);
} 
