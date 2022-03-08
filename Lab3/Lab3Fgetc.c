/*
 ***********************
    *Joseph Suter
    *CPSC 2311 Sp22 Section 004
    *jfsuter@g.clemson.edu
 ***********************
 */
#include <stdio.h>
#include "Lab3Fgetc.h"

void start(FILE* in){
    char str;
    
    //loop to read till file end
    while(! feof(in)){
	   str  = fgetc(in);
        if(str == '/'){
            str = ' ';
            rcomment(in);
        }
        
        //Stops printing of EOF char
	if(str != EOF){
        printf("%c", str);
	}
    }
    printf("\n");
}

//detects comments
void rcomment(FILE *in){
    char str;
    str = fgetc(in);
    if(str == '/'){
        skipS_comment(in);
    }
    if(str == '*'){
        skipM_comment(in);
    }
}

//skips comments with /
void skipS_comment(FILE* in){
    char str;
    
    int i = 0;
    
    while(i != 1){
        str = fgetc(in);
        if(str =='\n'){
            i = 1;
            break;
        }
    }
}
//skips comments with /*
void skipM_comment(FILE* in){
    char str;
    int i = 0;
    while(i !=1){
        str = fgetc(in);
        if(str == '*'){
            str = fgetc(in);
            i = 1;
            break;
        }
    }
}
