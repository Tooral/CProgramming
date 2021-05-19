//Tural Hagverdiyev 
//This file reads the input of the user
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readline.h"//for calling the header file and using it 

int read_line(char str[], int n) {
  	int ch, i = 0;
  	while (isspace(ch = getchar()))
    	;
  	str[i++] = ch;
  	while ((ch = getchar()) != '\n') {
    		if (i < n)
      			str[i++] = ch;
    	}
   	str[i] = '\0';
   	return i;
}

