//
//  Unix ID: ac289774
//  Discussion Session: Friday 1:40 PM
//
// This program takes an expression containing integers 0-9 and calculates the result. This does not correctly
// calculate more than a single digit and dividing by 0 will crash the program.

#include <stdio.h>

int main() {
    
    int i;
    char arr[50];
    //char dest[50];
    int length = sizeof(arr);
    printf("Enter an expression: ");
    fgets(arr, sizeof(arr), stdin);
    
    // printf("Raw user input: %s\n", arr);
    
    char value;
    int solution = 0;
    int j =0;
    while (j <= length) {                    // While loop to remove white space
        if (arr[j] == ' ') {
            for (i = j; i < length; i++)    // If there's white space, delete element and shift array
                arr[i] = arr[i+1];          // Set each element forward to the one behind it.
        }
        else
            j++;                            // Increment if it's not white space
    }

   // printf("Without whitespace: %s", arr);


   // printf("%s\n", arr);
    
    for(i = 0; i < length; i++) {                       // Loop that reads for arithmetic operators and uses
                                                        // the elements around them as factors.
        // printf("Rolling value = %d\n", solution);
        value = arr[i];                                 // Get value of current element.
        int prevValue;
        int nextValue;

        if((value == '+') || (value == '-') || (value == '*') || (value == '/')) {      // Gets arithmetic value
            
            switch(value) {                                                             // Performs operation depending on operator.
                case '+':
                    prevValue = (int) arr[i-1] - '0';
                    nextValue = (int) arr[i+1] - '0';
                    if (i>1)
                        solution += nextValue;
                    else
                        solution = (prevValue + nextValue);
                    i++;
                    break;
                case '-':
                    prevValue = (int) arr[i-1] - '0';
                    nextValue = (int) arr[i+1] - '0';
                    if (i>1)
                        solution -= nextValue;
                    else
                        solution = (prevValue - nextValue);
                    i++;
                    break;
                case '*':
                    prevValue = (int) arr[i-1] - '0';
                    nextValue = (int) arr[i+1] - '0';
                    if (i>1)
                        solution *= nextValue;
                    else
                        solution = (prevValue * nextValue);
                    i++;
                    break;
                case '/':
                    prevValue = (int) arr[i-1] - '0';
                    nextValue = (int) arr[i+1] - '0';
                    if (nextValue == 0) {
                        printf("Error! You can't divide by 0, the world will explode!");
                        void exit();
                    }
                    if (i>1)
                        solution /= nextValue;
                    else
                        solution = (prevValue / nextValue);
                    i++;
                    break;
                default:
                    printf("Invalid input! Single digit integers only. Terminating program\n");
                    void exit();
                    
            }
        }

    }
    printf("Value = %d\n", solution);       // Print the solution to the expression.

}
