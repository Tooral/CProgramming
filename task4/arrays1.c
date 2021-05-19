// Tural Hagverdiyev 
// this code asks user to enter length and elements of an array 
// the this code gets the 2 arrays, 1st one before zero
// 2nd one after zero and prints out them
#include <stdio.h>


int compute(int *a, int n)// the function we get the zero and arrays
         {
            int *p; 
            for(p = a; p < a+n; p++){// loop to read each elements of array
                if(*p==0){
                    return (p-a);
                }
                
            }
            return 0;
         }
int main()
{
    int i;
    int N;
    
    
    printf("Enter the length of the array: ");// the print out statements asks user to input length on array with help of scanf function
    scanf("%d",&N);
   
    int arr[N];
    
    printf("Enter the elements of the array: ");
     for(i=0; i<N;i++){// uisng loop to enter the elements of array for each section of actual array
       scanf("%d", &arr[i]);
     }
     
     
    int t = compute(arr,N);// calling the function

    
    int z = N-t-1;
    int array1[t], array2[z];
    
    for(i=0;i<t;i++){// loop to get and printout array 1
        array1[i] = arr[i];
    }
        
        printf("Array 1:");
        for(i=0;i<t;i++){
            printf(" %d ",array1[i]);
            
        }
        
    printf("\n");
    
   
    
        for(i=0;i<z;i++){
        array2[i]=arr[i+t+1];
         }
         
    printf("Array 2: ");// printing out array 2
        for(i=0;i<z;i++){
            printf("%d ",array2[i]);
        }
    return 0;
}
 
 

