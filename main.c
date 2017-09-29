#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "pernum.h"

unsigned long int number;


/*
 * Function: display_help
 * 
 * displays help menu
 *
 * @returns void
 */
void display_help () {
    printf("Usage: perfect-number [OPTION] NUMBER\r\n");
    printf("Check if NUMBER is perfect or fetch list of perfect numbers in range of 1 to NUMBER.\r\n\r\n");

    printf("Options:\r\n");
    printf("-h, --help  Display this help\r\n");
    printf("-c          Display whether NUMBER is perfect or not \r\n");
    printf("-r          Display all perfect numbers between 1 and NUMBER\r\n\r\n");

}



/*
 * Function: parse_arguments
 *
 * parse command arguments and execute
 * functions accordingly
 *
 * @param argc number of arguments
 * @param argv list of argument values
 *
 * @return void
 */
void parse_arguments (int argc, char * argv[]) {
    
    unsigned long int number;   /* used to store number from arguments */
    char *ptr;                  /* used in parsing arguments from strtoul */
    
    if(argc == 1) {

        display_help();

    } else if (!strcmp(argv[1], "-h") || 
               !strcmp(argv[1], "--help")) {

        display_help();

    } else if (!strcmp(argv[1], "-c") && argc == 3) {
        
        //Read "number" from argv
        number = strtoul(argv[2], &ptr, 10);


        (is_perfect_number(number))
            ? printf("true\r\n")
            : printf("false\r\n");

    } else if (!strcmp(argv[1], "-r") && argc == 3) {

        //Read "number" from argv
        number = strtoul(argv[2], &ptr, 10);

        //Fetch all perfect numbers in range from 1 to NUMBER
        lookup_perfect_numbers(number);
    }
    
}

/*
 * Function: main
 *
 * @param argc number of arguments
 * @param argv list of arguments
 *
 * @return int
 */

int main (int argc, char * argv[]) {

    parse_arguments(argc, argv);

    return 0;

}
