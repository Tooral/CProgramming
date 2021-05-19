//Tural Hagverdiyev 
// this program asks user to input some charachters with * and gets the output of the first two 
#include <stdio.h>
#define STR_LEN 1000// setting the length to 1000
// using readLine fucntion with pointer to get the input from user
    int readLine(char *str, int n);
// search function gets the locations of stars and stores them into s2 as required
    int search (char *s1, char *s2);

    int main(void)
    {
        int chars;
        char str[STR_LEN + 1],str2[STR_LEN + 1];
        printf("Enter some integers(symbols,characters) : ");
        readLine(str, STR_LEN+1);//to get input from user
        chars = search(str, str2);//to get the output 
       
        
       if( chars == 1){
            printf("output is: %s", str2);
        }
        else {
            printf("Two * characters not found");
        }
     	printf("\n");
        return 0;
    }

    int readLine(char *str, int n)// it asks user to put input enter some symbols
    {
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {  
        if (i < n) {
            *str++ = ch;
            i++;
        }
    }
   *str = '\0';

   return i;
    }
    
    int search(char *s1, char *s2)
    {
	// initializing some ints to find the loactions of stars
        char *firstStar,*secondStar=0;
        int foundFirst=0;
        char *p=s1;
        
	// loop to find if inputs starts with null or not
        while(*p!='\0'){
            if (*p== '*'){
		//Finding the location of first and second star storing them into p
                    if(foundFirst==0){
                        foundFirst=1;
                        firstStar=p;
                    }
                    else{
                        secondStar=p;
                        break;
                    }
                }
            p++;
        }
        char *output=s2;
// this stores the output to s2
        for(p=firstStar+1; p<secondStar; p++){
            *output=*p;
             output++;
        }
       
        

        if( foundFirst!=0){
            return 1;
        }
        else {
            return 0;
            
        }
        
    }// end of the function of search
