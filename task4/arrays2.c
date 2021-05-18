//Tural Hagverdiyev U10263909
// this code searchs for same consecutive elemenst and prints out them
#include <stdio.h>

void search_three(int *a1, int *a2, int n, int *num_three) // actual function to find the numbers
{
            int *p;
            int *t=a2;
            int numsRepeated=0;// this is variable of zero to let the num_three start from the zero point
            num_three = &numsRepeated; 
            
            for(p = a1; p < a1+n; p++)// loop to search for every array
	        {
	        	if( *p == *(p+1) && *p==*(p+2)){ // if statement to find the consecutive elements
	        	        *t = *p;
	        	         t++;
	        	        (*num_three)++;
	        	}
	        }
	        
	        
	        if(*num_three!=0){     // the statement that prints out consecutive elements
	            printf("The array contains %d of three identical consecutive elements: ", *num_three);
	            for(t=a2; t< a2+(*num_three); t++)
	                 printf("%d ",*t);
	        }
	        else{
	            printf("The array DOES NOT contain of three identical consecutive elements");
	        }  
	           
	  
}            

int main() // main function to get the array, length of it then call the function
{
    int i;
    int N;
    
    
    printf("Enter the length of the array: ");
    scanf("%d",&N);
   
    int arr[N], arr1[N];
    
    printf("Enter the elements of the array: ");
     for(i=0; i<N;i++){ // scanf for loop to get the elements for each section of array
       scanf("%d", &arr[i]);
     }
     
    int *p=0; // the pointer to set to zero for the beginning 
    
    search_three(arr,arr1,N,p);// calling the function that we found the numbers
    
   
    return 0;
}// end of the code
 
 



