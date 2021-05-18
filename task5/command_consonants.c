#include <stdio.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    

    
    if(argc>1){
        for (int i=1; i<argc; i++){
            printf("Input: %s\n", argv[i]);
            printf("Output: ");
        
       char *ch=argv[i];
    

    while( *ch != '\0')
    {
        if(isalpha(*ch))
            if(*ch != 65 && *ch != 69 && *ch != 73 && *ch != 79 && *ch != 85 && *ch != 97 && *ch != 101 && *ch != 105 && *ch != 111 && *ch != 117)
                 printf("%c", *ch);
		 ch++;
    }
  }
}
else{
        printf("Usage: ./a.out input");
    }
	printf("\n");
    
    return 0;


}
