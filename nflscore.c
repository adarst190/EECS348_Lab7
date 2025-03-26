/*
Program will take in a input of a football game score in the NFL,
and output all the possible combinations of scores that could have
occurred to get that final score.
*/

#include <stdio.h>

int main(){
    int score;          //Declare score variable
    int touchdown = 6;  //Declare the point values for each score in 11-15
    int fieldgoal = 3;
    int safety = 2;
    int td_extapoint = 7;
    int td_2ptconversion = 8;
    
    while (1){      //Infinite loop asking for scores until 0 or 1 is inputted
        printf("Enter 0 or 1 to STOP\n"); //Tells user to how to stop program
        printf("Enter the NFL score: ");        //Asks user for score
        scanf("%d", &score);                //Gets input into the variable of score
        if (score == 0 || score == 1){      //If the user inputted a 0 or 1
            break;              //Breaks from loop immediately
        }else if (score < 0){       //If the score entered is negative
            printf("Invalid score, please enter a valid score\n");      //Tells the user it is an invalid score
            continue;       //Continues with next iteration of loop, skipping for loop below
        }   
        
        for (int i = 0; i <= score; i++){           //Represents iterating through combinations of TD and 2pt conversion
            for (int j = 0; j <= score; j++){       //Represents iterating through combinations of TD and extra point
                for (int k = 0; k <= score; k++){       //Represents iterating through combinations of single TDs
                    for (int l = 0; l <= score; l++){       //Represents iterating through combinations of Field Goals
                        for (int m = 0; m <= score; m++){           //Represents iterating through combinations of safeties
                            if (i*td_2ptconversion + j*td_extapoint + k*touchdown + l*fieldgoal + m*safety == score){       //Multiplies the iteration # at the given loop point of each category by the point value it represents, and
                                                                                                                            //if they all equal the score, it will print the given amount of iterations of each loop(i.e the number of scores in each category at that point)
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safeties\n",i,j,k,l,m);       //Prints # of scores in each category
                            }
                        }
                    }
                }
            }
        }

    }
    return 0;       //Returns 0 to leave main program
}

