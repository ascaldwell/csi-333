//
//  Andrew Caldwell
//  Unix ID: ac289774
//  Discussion Session: Friday 1:40 PM
//

#include <stdio.h>
#include <stdlib.h>

// This program takes in user input of a start date and an end date and finds the number of days
// in between them exclusively. I use a for loop to iterate and add the days of each month as
// they occur in the array. I also use the current day as an offset value to get the exact day number
// out of 366 days. The two dates' values are subtracted to get 


int main() {
    
    int count = 0;      // Rolling count of days.
    int sMonth;         // Starting month number. 
    int sDay;           // Starting day of the month 
    int eMonth;         // Ending month number 
    int eDay;           // Ending day number 
    int daysOfMonth[13] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Array of the number of days
                                                                            // of each month in order.
    
    printf("Enter start date: ");           // Prompts the user for the start date and collects the input 
    fflush(stdout);                         // as two integers (denoted by a space between them). 
    scanf("%2d" "%2d", &sMonth, &sDay);
    
    
    
    // Switch statement to determine if the user is inputting the correct starting month. 
    switch (sMonth) {
        case 1:     // Cases for months with 31 days 
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            
            // if-else statement to get the valid date values for months containing 31 days. 
            if((sMonth <= 0) || (sDay <= 0) || (sMonth > 12) || (sDay > 31)) {
                printf("Invalid date.\n");
                fflush(stdout);
                exit(0);
            } // end if 
            break;
       
        case 4:     // Cases for months with 30 days. 
        case 6:
        case 9:
        case 11:
            // if-else to detemine correct user input for months containing 30 days. 
            if((sMonth <= 0) || (sDay <= 0) || (sMonth > 12) || (sDay > 30)) {
                printf("Invalid date.\n");
                fflush(stdout);
                exit(0);
            } // end if 
            break;
        
        case 2:     // Case for the month of February 
        
        // Note that 2016 is a leap year so the value 29 is acceptable in this if statement. 
        if((sMonth <= 0) || (sDay <= 0) || (sMonth > 12) || (sDay > 29)) {
            printf("Invalid date.\n");
            fflush(stdout);
            exit(0);
        } // end if 
        break;

        default:
            printf("Invalid date.\n");
            fflush(stdout);
            exit(0);
            break;
    } // end switch 
    
    
    printf("Enter end date: ");             // Prompts the user for the start date and collects the input 
    fflush(stdout);                         // as two integers (denoted by a space between them). 
    scanf("%2d" "%2d", &eMonth, &eDay);

    
    // Switch statement to determine if the user is inputting the correct end month. 
    switch (eMonth) {
            
        case 1:     // Cases for months with 31 days 
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            
            // if-else statement to get the valid date values for months containing 31 days. 
            if((eMonth <= 0) || (eDay <= 0) || (eMonth > 12) || (eDay > 31)) {
                printf("Invalid date.\n");
                fflush(stdout);
                exit(0);
            } // end if 
            break;
            
        case 4:     // Cases for months with 30 days. 
        case 6:
        case 9:
        case 11:
            // if-else to detemine correct user input for months containing 30 days. 
            if((eMonth <= 0) || (eDay <= 0) || (eMonth > 12) || (eDay > 30)) {
                printf("Invalid date.\n");
                fflush(stdout);
                exit(0);
            } // end if 
            break;
            
        case 2:     // Case for the month of February 
            
            // Note that 2016 is a leap year so the value 29 is acceptable in this if statement. 
            // This if statement determines if the input is correct for the month of February. 
            if((eMonth <= 0) || (eDay <= 0) || (eMonth > 12) || (eDay > 29)) {
                printf("Invalid date.\n");
                fflush(stdout);
                exit(0);
            } // end if 
            break;
        default:
            printf("Invalid date.\n");
            fflush(stdout);
            exit(0);
            break;
    } // end switch 
    
    
    
    int totalDaysX = 0, c;   // totalDaysX is the cumulative days added by each month passed and c is the month count
    
    
    // for loop that iterates through each month and adds it to a total number of days x. 
    // x is the total number of days passed in sMonth. 
    for (c=0; c<sMonth-1; c++) {
        totalDaysX += daysOfMonth[c];
    } // end for loop 
    
    
    int totalDaysY = 0, d; // totalDaysY is the cumulative days added by each month passed and d is the month count
    
    // for loop that iterates through each month and adds it to a total number of days y. 
    // totalDaysY is the total number of days passed in eMonth.
    for (d=0; d<eMonth-1; d++) {
        totalDaysY +=daysOfMonth[d];
    } // end for loop
    
        
    int totalY = totalDaysY + eDay; // adds the offset of the end date
    int totalX = totalDaysX + sDay; // adds the offset of the start date
    
    // if statement to verify if the user is putting the dates in the correct order. 
    if (totalX > totalY) {
        printf("End date precedes start date.\n");
        fflush(stdout);
        exit(0);
    } // end if 

    count = totalY - totalX;      // Difference between the the two dates 
    
    
    // If statement to account for the possibility of two dates being the same 
    if (count == 0){
        printf("Answer = %d\n", count); // Final output :)
        fflush(stdout);
    } // end if 
    else {
    count--;  // Subtract 1 from the end date to account for exclusivity of days between the two dates. 
        printf("Answer = %d\n", count); // Final output :)
        fflush(stdout);
    } //end else 
} // end main

