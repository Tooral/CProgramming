//Tural Hagverdiyev 
// In this Program, It basically calculates the total amount of rent fee
// but it gives attenton to some points
// it exits the program when written less than 1 for months and etc.
// i have used if else statement instead of switch but both would work
// i have only used if else statement and some doubles, integers 
//and basic math


#include <stdio.h>

int main (void)
{
  int num, months_rented, amount_due=0;
  int sofa1 = 20, loveseat=15,post_bed=25,dresser=10,kitchen_table=25;
  int sofa_max=100, loveseat_max=80,post_bed_max=105,dresser_max=50,kitchen_table_max=120;

  printf("Please select from the following menu: 1. Sofa, 2. Loveseat, 3. 4 Post Bed, 4. Dresser 5. Kitchen Table \n");
  printf("Enter furniture selection: ");
  scanf("%d", &num);
 if (num<1 || num>5)
 { 
	printf("You made wrong selection \n");
	return 0;
}
 printf ("Enter months rented: ");
  scanf ("%d", &months_rented);
 if(months_rented<1){
	printf("Wrong number \n");
	return 0;
	} 
   
  if (num == 5){
    if(months_rented>=12){
	int num_years = months_rented/12;
	int remainder = months_rented%12;
	int addition;
      amount_due=num_years* kitchen_table_max;
	addition= 10*remainder;
	if(addition>kitchen_table_max){
	addition = kitchen_table_max;
	}
	amount_due+=addition;
    }
    else{
      amount_due = kitchen_table + 10*(months_rented-1);;
 if(amount_due> kitchen_table_max){
                        amount_due=kitchen_table_max;
                 }   
 }
  }
  else if (num==4){
    if(months_rented>=12){
 	int num_years =months_rented/12;
        int remainder =	months_rented%12;
        int addition;

	amount_due=num_years* dresser_max;
	 addition=5*remainder;
        if(addition>dresser_max){ 
        addition = dresser_max;
        }
        amount_due+=addition;
        
     }
     else{
        amount_due = dresser + 5*(months_rented-1);
          if(amount_due> dresser_max){
                        amount_due=dresser_max;
                 }
     }
  }  
  else if (num == 3){
    if(months_rented>=12){
         int num_years =months_rented/12;
        int remainder =	months_rented%12;
        int addition;

        amount_due=num_years* post_bed_max;
	 addition= 8*remainder;
        if(addition>post_bed_max){ 
        addition = post_bed_max;
        }
        amount_due+=addition;
     }
     else{
        amount_due = post_bed+ 8*(months_rented-1);
	 if(amount_due> post_bed_max){
                        amount_due=post_bed_max;
                 }
     }
  }
  else if (num == 2){
   if(months_rented>=12){
         int num_years =months_rented/12;
        int remainder =	months_rented%12;
        int addition;

        amount_due=num_years* loveseat_max;
	 addition= 10*remainder;
        if(addition>loveseat_max){ 
        addition = loveseat_max;
        }
        amount_due+=addition;
      }
      else{
         amount_due = loveseat+ 10*(months_rented-1);
if(amount_due>loveseat_max){
                        amount_due=loveseat_max;
                 }
      }
  }

  else if (num == 1){
    if(months_rented>=12){
         int num_years =months_rented/12;
        int remainder =	months_rented%12;
        int addition;

        amount_due=num_years*sofa_max;
	 addition= 12*remainder;
        if(addition>sofa_max){ 
        addition = sofa_max;
        }
        amount_due+=addition;
      }
      else{
        amount_due = sofa1+12*(months_rented-1);
if(amount_due>sofa_max){
                        amount_due=sofa_max;
                 }

      }
    }

  else{
    printf ("You made wrong selection \n");
    }
    
  
    
       
printf("Amount due ($): %d \n", amount_due);
  return 0;
}

