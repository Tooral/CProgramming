//Tural Hagverdiyev U10263909
// in this program user is asked forr in put and the inputed entered is getting consonants only 
// with help of some special functions
// if statement, gecthar and while loop has been used forr this code
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    printf("Input:");
    ch = getchar();
    printf("Output: ");

    while( ch != '\n')
    {
        if(isalpha(ch))
                       if(ch != 65 && ch != 69 && ch != 73 && ch != 79 && ch != 85 && ch != 97 && ch != 101 && ch != 105 && ch != 111 && ch != 117)
          printf("%c", ch);

        ch = getchar();
           
    }

	printf("\n");
    
    return 0;


}
