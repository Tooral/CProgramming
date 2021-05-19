// Tural Hagverdiyev 
// This programs checks the output or random chars to see if the output is
// strong or not
// there have been used many methods, such as calling functions, if statements
// comparisions for loop and etc
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
        void generate_values (int a[], int size)
   
{
                 srand (time (NULL));
                 int i;
                 
                 for (i = 0; i < size; i++)// this is the loop to check every number

             {
                 a[i]= ((rand () % 94) + 33);
                 printf ("%c", a[i]);
             }
         return;
    }
    
    
     int is_strong_password(int a[], int size)//funtion
      {
         int condition1, condition2, condition3, condition4;
         int i;
         
        for(i=0;i<size;i++){ //loop to check every number
            if(a[i]=='<'|| a[i]=='>')
            {
                return 0;
            }
                
            if(a[i]>='a'&&a[i]<='z')// if statement to check given conditons
            {
                     condition1 = 1; 
            }
                    
            else if(a[i]>='A'&&a[i]<= 'Z'){
                
                      condition2 = 1; 
            }
                     
            else if(a[i] >= '0' && a[i] <= '9'){
                      condition3 = 1; 
            }
                      
            else{
                      condition4=1;
            }
        }
         
         if(condition1==1&&condition2==1&&condition3==1&&condition4==1)
                return 1;
         else 
                return 0;

        
    }
    
    
     

        int main ()// main function for randomziing the arrays
    {

            int length;
          
            

                srand (time (NULL));


                length = ((rand () % 8) + 8);
                 int a[length];
                 
                 
                 generate_values (a, length);
                 int result = is_strong_password(a, length);
                if( result==1){
                    printf("\n Password is strong");
                }
                else{
                    printf("\n Password is not strong");
                } 
                 
            
      return 0;
    }
    
   
