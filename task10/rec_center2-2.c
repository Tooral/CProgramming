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

struct request *add(struct request *list);
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
int main(void)
{
  char code;

  struct request *wait_list = NULL;  
  printf("Operation Code: a for adding to the ordered list,"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': wait_list = add(wait_list);
		break;
      case 'p': printList(wait_list);
                break;
      case 'q': clearList(wait_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct request *add(struct request *list){
 // Tural hagverdiyev U10263909
	//this add function uses linked lists to provide the desired outcome for user   
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

    struct request *node = (struct request*) malloc(sizeof(struct request));
	strcpy(node->email, email_address);
	strcpy(node->class, class_name1);
	strcpy(node->first, name);
	strcpy(node->last, lastName1);
	
	if(list == NULL)
	{
	    node->next=NULL; 
	    return node;
	}
	
    struct request *search;
    for(search = list; search != NULL; search = search->next){
        if(strcmp(node->class,search->class)==0){
            if(strcmp(node->last,search->last)==1){
            node->next=search;
            return list;
            }
            if(strcmp(node->last,search->last)==-1){
            node->next=search->next;
            search->next=node;
            return list;
            }
          }
        else if(strcmp(node->class,search->class)==1){
                node->next=search;
                return list;
        }
        else if(strcmp(node->class,search->class)==-1){
                 node->next=search->next;
                 search->next=node;
                 return list;
        }
    }
	return list;
}

/**********************************************************
 * printList: print the data  in the linked list passed   *
 * in as parameter                                        *
 **********************************************************/


void printList(struct request *list){

  struct request *p;

  printf("\nEmail\t\t\t\t\t\tFirst Name\tLast Name\t\t"
         "class\n");
  for (p =list; p != NULL; p = p->next)
    printf("%-50s%-15s%-15s%15s\n", p->email, p->first,p->last,
           p->class);

}

/*************************************************************
 * clearList: release the memory in the linked list passed   *
 * in as parameter                                           *
 *************************************************************/


void clearList(struct request *list)
{

 
  struct request *p;

  while(list!=NULL)
  {
         p = list;
         list = list->next;
         if(p!=NULL)
            free(p);
  }


}

int read_line(char str[], int n)
{
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

