/*
 * File: pernum.h
 *
 * Author: Richard Perkins (richardperkins89@gmail.com)
 * Date:   09/28/2017
 *
 * Summary:
 *    This file contains functions that test for and
 *    find perfect numbers
 *
 */



#ifndef perfect_number
    #define perfect_number
#endif

#define FAIL 0
#define SUCCESS 1

/**
 * List of perfect numbers
 */
unsigned long int perfect_numbers[] = {
    6,
    28,
    496,
    8128,
    33550336,
    8589869056,
    137438691328,
    2305843008139952128 //Largest perfect number that can fit into an unsigned 64-bit int.
};


/**
 * Function: is_perfect_number
 *
 * calculates whether number is perfect or not
 *
 * @param number
 *
 * @return int 0 for false, 1 for true
 */
int is_perfect_number (int number) {
    int sum = 0;

    //Cycle through divisors
    for (int n = 1; n < (number - 1); n++) {

        //Check to see if number is divisor
        int rem = number % n;
        
        //Add n to sum if n is divisor of number
        if(rem == 0) {
            sum += n;
        }
    }

    //Check if perfect number and return respectively
    return (sum == number);
}


/**
 * Function: is_perfect_number_lookup
 *
 * Check to see if number is in perfectNumbers list
 *
 * @param number
 *
 * @return
 */
int is_perfect_number_lookup (int number) {

    //TODO: search for "number" in "perfect_numbers"

    return 0;
}

/*
 * Function: lookup_perfect_numbers
 *
 * Find and display all perfect numbers between 1 and "number"
 * 
 * HAX AHEAD!
 * Why do countless calculations for one of 8 possible numbers that can fit into an unsigned long int?
 *
 * @param number int number to search to
 *
 * @return void
 */
void lookup_perfect_numbers (int number) {

    //Iterate possible perfect numbers
    for (int n = 0; n < 8; n++) {
        if (perfect_numbers[n] <= number) {
            printf("%lu\r\n", perfect_numbers[n]);
        }
    }
}
