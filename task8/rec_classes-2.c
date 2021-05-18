//Tural Hagverdiyev U10263909 
//This program using more advanced techqniues to develop a normal program to store names and other thing(linked lists)
//Here I modified the given program and added append, delete and clearlist to make program work perfectly as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CLASS_LEN 100
#define NAME_LEN 30
#define EMAIL_LEN 50

struct request{
	char class[CLASS_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];;
	struct request *next;
};

struct request *load();
void save(struct request *list);
struct request *append(struct request *list);
struct request *delete(struct request *list); 
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n); 

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/

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
/**********************************************************
 * load: read file "waiting_list.txt" and store the data  *
 *       in a linked list and returns the linked list     *
 **********************************************************/

struct request *load(){
	struct request * list= NULL;
	struct request *prev, *new_node;
	char f_name[NAME_LEN+1];
	char l_name[NAME_LEN+1];
	char e_address[EMAIL_LEN+1];
	char class_name[CLASS_LEN+1];
	
	FILE *pFile;
        pFile = fopen("waiting_list.txt", "r");
	
	if(pFile == NULL)
	{
		printf("Error opening the file\n");
		return NULL;
	}
        while(!feof(pFile)&&!ferror(pFile))
	{
	       if(fscanf(pFile, "%s%s%s%s", e_address, class_name, f_name, l_name)== 4)
		{
 			 new_node = malloc(sizeof(struct request));
 			 if (new_node == NULL) {
    				printf("Database is full; loding error.\n");
    				return NULL;
 			 }
			strcpy(new_node->email, e_address);
			strcpy(new_node->class, class_name);
			strcpy(new_node->first, f_name);
			strcpy(new_node->last, l_name);
			new_node->next = NULL;
			
			if(list == NULL)
				list = new_node;
			else
				prev->next = new_node;
			prev = new_node;	
        	}
	}
	return list;
}
/**********************************************************
 * save: write to file "waiting_list.txt" with the data   *
 *       in the linked list passed in as parameter        *
 **********************************************************/
void save(struct request *list) {
	struct request * p;
	FILE *pFile;
        pFile = fopen("waiting_list.txt", "w");
	
	if(pFile == NULL)
	{
		printf("Error opening the file\n");
		return;
	}
	for (p =list; p != NULL; p = p->next)
    		fprintf(pFile, "%-s %s %s %s\n", p->email, p->class, p->first,p->last);
	fclose(pFile);
}
//this program usiing the linked lists to delete and modify the input on waiting list
struct request *delete(struct request *list) {
        struct request *cur, *prev; 
	char email_address[EMAIL_LEN+1];
	char name[NAME_LEN+1];
	char lastName1[NAME_LEN+1];
	char class_name1[CLASS_LEN+1];

	//asking the user to enter the information by using the readline function 
        printf("Enter student\'s email: ");
	read_line(email_address, EMAIL_LEN+1);
	printf("\nEnter student\'s class name: ");
        read_line(class_name1, CLASS_LEN+1);
	printf("\nEnter student\'s first name: ");
        read_line(name, NAME_LEN+1);
	printf("\nEnter student\'s last name: ");
        read_line(lastName1, NAME_LEN+1);

	//using bypass method here
	for(cur = list, prev = NULL; cur != NULL; prev = cur, cur = cur->next) {
		if((strcmp(email_address, cur->email)==0) && (strcmp(class_name1, cur->class)==0) && (strcmp(name, cur->first)==0) && (strcmp(lastName1, cur->last)==0))
			break;
	}
	if(cur == NULL) { 
		printf("Not found");
		return list;
	}
	if(prev == NULL) {
		list= list->next;
	}
	else {
		prev->next = cur->next;
	}
	free(cur); 
	return list;	           
}//end of the code

//here program using the linked lists to append the input and act as required
struct request *append(struct request *list){
        char email_address[EMAIL_LEN+1];
        char name[NAME_LEN+1];
        char lastName1[NAME_LEN+1];
        char class_name1[CLASS_LEN+1];
	struct request *current;

	//asks the user to enter information  with using provided readline fucntion
	printf("Enter student\'s email: ");
        read_line(email_address, EMAIL_LEN+1);
        printf("\nEnter student\'s class name: ");
        read_line(class_name1, CLASS_LEN+1);
        printf("\nEnter student\'s first name: ");
        read_line(name, NAME_LEN+1);
        printf("\nEnter student\'s last name: ");
        read_line(lastName1, NAME_LEN+1);
	//bypass using here
	for(current = list; current != NULL; current = current->next) {
		if((strcmp(email_address, current->email)==0) && (strcmp(class_name1, current->class)==0) && (strcmp(name, current->first)==0) && (strcmp(lastName1, current->last)==0)) {
			printf("Exists already in the waiting list\n");
			return list;
		}
	}
	//using node linked lists
	struct request *node = (struct request*) malloc(sizeof(struct request));
	strcpy(node->email, email_address);
	strcpy(node->class, class_name1);
	strcpy(node->first, name);
	strcpy(node->last, lastName1);
	node->next = NULL;

	if(list == NULL) {
		return node;
	}
	current = list;
	while(current->next != NULL) 
		current = current->next;
		current->next = node;
	return list;
}//end of the code
/**********************************************************
 * printList: print the data  in the linked list passed   *
 * in as parameter                                        *
 **********************************************************/
void printList(struct request *list){
	struct request *p;
  	for (p =list; p != NULL; p = p->next)
    		printf("%-50s%-15s%-15s%15s\n", p->email, p->first,p->last,p->class);
}
//using clear list adjusted from the  book method, and using it to behave as required
void clearList(struct request *list) {
	struct request *current = list;
	struct request *next;
	while(current != NULL) {
		next = current->next; 
		free(current);
		current = next;
	}
}//end of the function

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

