//Tural Hagverdiyev 
//This program using more advanced techqniues to develop a normal program to store names and other thing(linked lists)
//this program is using the header files and other things for making it easire to run the code and get the desired outputs
#include "request.h"
#include "read_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CLASS_LEN 100
#define NAME_LEN 30
#define EMAIL_LEN 50



int main(void) {
	char code;
	struct request *wait_list = load();
	printf("Operation Code: d for removing from the list, a for appending to the list," ", p for printing the list; q for quit.\n");
	for (;;) {
		printf("Enter operation code: ");
    		scanf(" %c", &code);
    		while (getchar() != '\n') /* skips to end of line */
      		;
    		switch (code) {
      			case 'd': wait_list = delete(wait_list);
                		break;
      			case 'a': wait_list = append(wait_list);
				break;
      			case 'p': printList(wait_list);
                		break;
      			case 'q': save(wait_list);
				clearList(wait_list);
				return 0;
      			default: printf("Illegal code\n");
    		}
    		printf("\n");
  	}
}


