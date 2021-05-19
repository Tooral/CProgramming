// Tural Hagverdiyev 
// This program gets random numbers to get the length on array after that
// program gets random numbers to find the correct AScii table matches of the
// chars that it got, there have been used many things
// such as calling functions, for loops, if statements,  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_values (int a[], int size)
    {
            srand (time (NULL));
                int i;
             for (i = 0; i < size; i++)// loop to check every condition
             {
                 a[i]= ((rand () % 94) + 33);
                 printf ("%c", a[i])
             }
       
                 return;
    }
        

int main ()
{
  
int length;


  srand (time (NULL));// to get random numbers
  

  length = ((rand () % 8) + 8);
   int a[length];
 
generate_values(a, length);// calling function
  
return 0;
}
        
