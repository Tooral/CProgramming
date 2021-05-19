//Tural Hagverdiyev 
//this code reads a file and asks user to input the name of file
//then gets the desired output from the file and writes it into new file
#include <stdio.h>
#include <string.h>
#define  MAX_LINE_LEN 100
void extract_phone(char *input, char *phone); //function that gets numbers
int main()
{
    char file_name[100];
    FILE *fp, *fp2; //file function to open and write files
    
    printf("Enter file name: ");
    scanf("%s", file_name);//asks user to input the name of file
    
    if (( fopen(file_name, "r")) == NULL) { //loop that gets the file and reads it
        printf("Error opening file : %s\n", file_name);
        return -1;
    }
    fp = fopen(file_name, "r"); //to open the file to read
    
    char output_file[100]= "phone_";
    strcat(output_file, file_name);
    
    fp2 = fopen(output_file, "w");
    char new_lines[100], phone_numbers[100];
	//While loop to get the every line of the file
    while(fgets(new_lines, MAX_LINE_LEN, fp) != NULL ){
        extract_phone(new_lines, phone_numbers);
        fputs(phone_numbers,fp2);
    }
        printf("Output File Name: %s", output_file);  
	fclose(fp);
	fclose(fp2);
        return 0; 
}//end of the main 

void extract_phone(char *input, char *phone){
    char *firstNum;
        int foundFirst=0;
        char *p=input;
	//in thisfunction we will find the numbers and store it into output
        while(*p!= '\0'){
            if (*p== '('){
                    if(foundFirst==0){
                        foundFirst=1;
                        firstNum=p;
                    }
                    
                }
            p++;
        }
        char *output=phone;
        for(p=firstNum+1; *p!= '\0'; p++){
            *output=*p;
             output++;
        }

}// end of the function



