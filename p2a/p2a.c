//
//  Andrew Caldwell
//  Unix ID: ac289774
//  Discussion Session: Friday 1:40 PM
//
// This program takes in a decimal number and the base of another radix
// system and converts it to said radix and saves it to an array. The answer
// is then printed out to the console.


#include <stdio.h>
#include <string.h>

int main() {
   
    int base, number, index, remainder, digit, count=0;
    
    char a[30];                     // Array that accomadates 30 digits.
    
    printf("Enter two integers: ");         // Asks for the decimal and the radix to convert to
    scanf("%d" "%d",&number, &base);        // Takes in the user input
    
    while(number!=0)                    // Loop iterates and stores the modulus of the decimal
    {                                   // until the decimal number reaches 0 after dividing the number
        remainder= number % base;       // by the radix base.
        digit ='0'+ remainder;
        if(digit>'9')
            digit=digit+ 7;         // if >= 10, the digit will be stored as a char A-F
        a[count]=digit;
        count++;                // increment count
        number = number/base;
    }
    printf("\nAnswer = ");
    for(index=count-1;index>=0;--index)     // Output the array
        printf("%c",a[index]);
    printf("\n");
    
}
