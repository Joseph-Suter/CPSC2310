/*
 ***********************
    *Joseph Suter
    *CPSC 2311 Sp22 Section 004
    *jfsuter@g.clemson.edu
 ***********************
*/
 
#include <stdio.h>
#include "Lab3Fscan.h"

void start(FILE* in){
	char str;
	//Loop to scan till EOF
		while(fscanf(in, "%c", &str)== 1){
		
			if(str == '/'){
				str = ' ';
				rcomment(in);
			}
			printf("%c", str);

		
		}
	printf("\n");
}

//Detects comment
void rcomment(FILE *in){
	char str; 
	fscanf(in, "%c", &str);
	if(str == '/'){
		skipS_comment(in);
	}

	if(str == '*'){
		skipM_comment(in);
	}
}

void skipS_comment(FILE* in){
	char str;
	int i = 0;

	while(i != 1){
		fscanf(in, "%c", &str);
		if(str == '\n'){
			break;
		}
	}
}

void skipM_comment(FILE* in){
	char str;
	int i = 0;

	while( i != 1){
		fscanf(in, "%c", &str);
		if(str == '*'){
			fscanf(in, "%c", &str);
			i = 1;
			break;
		}
	}
}

