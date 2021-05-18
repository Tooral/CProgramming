// Tural Hagverdiyev U10263909
// this program evaluates calculation based on random numbers
// after that it prints out the correct output
// in special cases such as 5, 11 it asks forr user to enter output abnd then
// program runs same thing one more time
// if statements, rand function, srand function, do while loop has been used for the program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    int choice;
   
    srand(time(NULL));
    int r;
    do {
         printf("Would you like to play(press 1 to play, 0 to quit)?:");
         scanf("%d",&choice);
         
     if(choice==1){
         r = (rand()%12);
        if (r==0)
                printf("Pizza\n");
        else if (r==1)
                printf("Shirt\n");
        else if (r==2)
                printf("Panel\n");
         else if (r==3)
                printf("Raspberry\n");
         else if (r==4)
                printf("Brown Sugar\n");
         else if (r==6)
                printf("Butter\n");
         else if (r==7)
                printf("Apple\n");
         else if(r==8)
                printf("Blackberry Jelly\n");
         else if (r==9)
                printf("Strawberry Cake\n");
         else if (r==10)
                printf("Bacon\n");
         else if (r==5)
                printf("Congratulations! You have won $4000\n");
         else if (r==11)
                printf("Spin again\n");
     }else{
	printf("Thank you for playing");
	}
   
}while(r==5||r==11);
        
     

    return 0;
}

