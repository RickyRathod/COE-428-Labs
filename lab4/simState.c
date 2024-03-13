#include <stdlib.h>
#include <stdio.h>

#define NUM_STATES 8

//we use this to conevrt integers to their corresponding Chars 
//starting at 64->90 rep A-Z
int ACSIIADDER(int value) {
    return value + 65;
}

int main(int argc, char * argv[]) {
    // Counter vars
    int i;

    // Temp array to tag reachable states, Temp var to track current state
    // Temp index var to store the index of the row for a given current state
    
    // Unreachable states
    int temp_arr[NUM_STATES] = {0};
    
    int temp_0 = 0;
    int temp_1;
    int tempIndex;
    int Counter = 0;

    // Var to initialize rows of the FSM
    int row = NUM_STATES;

    // Initializes the FSM dimensions
    int column = 3;
    int FSM[row][column];

    // Var to track index of Current State
    int TrackIndex;

    // Var to be used to force quit program
    int Quit = 0;

    // Var to track user inputs
    char Input[3];

    // State Starting at C
    int Current_State = 2;
    TrackIndex = 2;

    // Initialize FSM
    int S_FSM[NUM_STATES] = {0, 1, 2, 3, 4, 5, 6, 7};
    int ZERO_FSM[NUM_STATES] = {2, 3, 0, 3, 5, 1, 4, 5};
    int ONE_FSM[NUM_STATES] = {3, 6, 1, 7, 0, 6, 2, 4};

    for (i = 0; i < NUM_STATES; i++) {
        FSM[i][0] = S_FSM[i];
        FSM[i][1] = ZERO_FSM[i];
        FSM[i][2] = ONE_FSM[i];
    }

    // Prints the current state of the FSM
    fprintf(stdout, "Starting State: %c \n", ACSIIADDER(Current_State));

    while (Quit != 1) {
        fprintf(stdout, "Enter Inputs as per the lab document \n");
        // Get Input inputs from the user
        fscanf(stdin, "%s", &Input[0]);

        switch (Input[0]) {
        
        //user inputs either 0 or 1 indicating which col to change (FSM)
        //where it then stores that FSM in input 1,
        //next it will ask the user to input the state to be changed
        //that gets stores in input2 where we - 'A' to convert it in ASCII format
            case 'c':
                fprintf(stdout, "Enter the FSM (0 or 1) you would like to change\n");
                fscanf(stdin, "%s", &Input[1]);

                fprintf(stdout, "Enter the new state\n");
                fscanf(stdin, "%s", &Input[2]);

                if (Input[1] == '0') {
                    FSM[TrackIndex][1] = Input[2] - 'A';
                } else if (Input[1] == '1') {
                    FSM[TrackIndex][2] = Input[2] - 'A';
                }
                break;
                
            //delete funtion not fully implemented     
            case 'd':
                for (i = 0; i < NUM_STATES; i++) {
                    if (temp_arr[i] == 0) {
                        FSM[i][0] = 0;
                        FSM[i][1] = 0;
                        FSM[i][2] = 0;
                        fprintf(stdout, "Deleted: %c\n", ACSIIADDER(i));
                    }
                }
                break;

            case 'p':
                for (i = 0; i < row; i++) {
                    fprintf(stdout, "%c %c %c \n", ACSIIADDER(FSM[i][0]), ACSIIADDER(FSM[i][1]), ACSIIADDER(FSM[i][2]));
                }
                break;
                
                //prints the nextState at FSM[current][0 or 1] index for 
            case '0':
                Current_State = FSM[TrackIndex][1];
                TrackIndex = Current_State;
                fprintf(stdout, "%c \n", ACSIIADDER(Current_State));
                break;
                
            case '1':
                Current_State = FSM[TrackIndex][2];
                TrackIndex = Current_State;
                fprintf(stdout, "%c \n", ACSIIADDER(Current_State));
                break;

            case 'q':
                Quit = 1;
                break;

            default:
                fprintf(stdout, "Please enter a valid input\n");
                break;
                
            //garbadge
            //checks for reachable and unreachable states
                
            //this is done by iterating through the FSM
            // while the value temp state != the current state, it will iterate through the rest of the states
            //then the state gets initialized to the array FSM where FSM[tempindex] is the current state,
            //and the [k+1] represents the index of its next state
            //after which we set the new current to reachable and then increment the counter
                
            //if the counter is >= number of states then temp_0 is the current state.
            //then we reset the var for the next iteration and the for loop prints all the unreachable
                
            //temp_0 will eventually hold the value of the current state, initially non specific.
            case 'g':
                // Reset temp_arr to mark all states as unreachable by default
                for (int i = 0; i < NUM_STATES; i++) {
                    temp_arr[i] = 0;
                }

                // Traverse the FSM starting from the current state
                tempIndex = TrackIndex;
                for (int k = 0; k < 2; k++) {
                    while (temp_0 != Current_State) {
                        tempIndex = FSM[tempIndex][k + 1];
                        temp_arr[tempIndex] = 1; // Mark the state as reachable
                        temp_0 = tempIndex;
                        Counter++;
                        
                        //once it goes in a full circle it sets temp_0 as the current basically giong back to 'C'
                        if (Counter >= NUM_STATES)
                            temp_0 = Current_State;
                    }
                    
                    // Reset variables for the next iteration
                    Counter = 0;
                    temp_0 = 0;
                    tempIndex = TrackIndex;
                }

                // Print unreachable states
                for (int i = 0; i < NUM_STATES; i++) {
                    if (temp_arr[i] == 0 && i != Current_State) {
                        fprintf(stdout, "Garbage: %c \n", ACSIIADDER(i));
                    }
                }
                break;
        }
    }
    exit(0);
}