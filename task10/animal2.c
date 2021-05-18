//Tural Hagverdiyev U10263909 This program has struct and other functions to read a file and sort the desired output
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define READ_NAME 100 
#define MAX_ITEMS 200

//struct function to define the elements of function
struct animal {
    char name[READ_NAME+1],species[READ_NAME+1],gender[READ_NAME+1];
    int age;
    double weight;
};

//sort function uses loops and other things to sort the file input
int compare_animals(const void *p, const void *q);
int main()
{
   char name[READ_NAME+1], output_file1[] = "sorted_dogs.txt", output_file2[] = "sorted_cats.txt";//strrings
   struct animal array1[MAX_ITEMS];
   printf("Enter file name:");
   scanf("%s", name);

  //opening a file and setting file insturctions for the reading from the file or writing to a file
   FILE *fp = fopen(name,"r"); 
   FILE *fout = fopen(output_file1,"w"); 
   FILE *fout2 = fopen(output_file2,"w"); 
   for( int i=0; i< MAX_ITEMS; i++){
        fscanf(fp, "%s %s %s %d %lf ", array1[i].name, array1[i].species, array1[i].gender, &array1[i].age, &array1[i].weight);
   }
   qsort(array1,MAX_ITEMS,sizeof(struct animal),compare_animals);
   char dogs[] = "dog";
   char cats[] = "cat";
//this is to read through ever line of the array and set the desired output
   for ( int i=0; i< MAX_ITEMS; i++){
       if(strcmp(array1[i].species,dogs)==0)
            fprintf(fout,"%s %s %d %.2lf", array1[i].name, array1[i].gender, array1[i].age, array1[i].weight);
        
       if(strcmp(array1[i].species,cats)==0)
            fprintf(fout2,"%s %s %d %.2lf", array1[i].name, array1[i].gender, array1[i].age, array1[i].weight);
   }
   printf("Output file names %s\n%s", output_file1, output_file2);
   fclose (fp);//closing files
   fclose (fout);
   fclose (fout2);
   return 0;
}//end of the code
//sort functions, just sorts out the input file by the age

int compare_animals(const void *p, const void *q)
{
const struct animal *p1 = p;
const struct animal *q1 = q;

if (p1->age < q1->age)
   return -1;
else if (p1->age == q1->age)
   return 0;
else 
   return 1;
}


