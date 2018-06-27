#include <stdio.h>
#include <math.h>

int main (int argc,char *argv[]){

 int x, i=0, sum = 0;
	
 printf("Enter number:");
 scanf ("%d",&x);
 printf("The factors of %d are:\n",x);

	while (i<x){ 	
		i=i+1; 
  		if(x%i ==0) {
			printf("%d\n",i);
			sum = sum + i;
		}
	}
	
	sum = sum - x;	
	printf("Sum of factors = %d\n",sum);
	
	if(sum ==x) {
	printf("%d is a perfect number.\n",x);
	}
	else {
	printf("%d is not a perfect number.\n",x);
	}
	
	return 0;
}
 
	




	
