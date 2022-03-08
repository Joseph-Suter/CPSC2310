/*
 ***********************
       *Joseph Suter
       *CPSC 2311 Sp22 Section 004
       *jfsuter@g.clemson.edu
 ***********************
 */
#include <stdio.h>
#include "Lab3Fgetc.h"
int main(int argc, char**argv)
{
    FILE * fileIN = NULL;
    
    if(argc != 2){
        printf("WRONG NUM OF INPUTS\n");
        exit(0);
    }
    
    //Open and read file
    fileIN = fopen(argv[1], "r");
    
    //Check to make sure opened
    if(fileIN == NULL){
        printf("Error opening file \n");
	return - 1;
        
    }
    
    start(fileIN);
    fclose(fileIN);
    
    return 0;
}
