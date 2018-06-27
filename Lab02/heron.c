#include <stdio.h>
#include <math.h>

    int main (int argc, char *argv[]) {
	
	float a, b, c, s, area, q;	
	
	printf("Enter sidelengths of a triangle:\n");
	scanf("%f %f %f", &a, &b, &c);
	if(a+b>c && a+c>b && b+c>a) {
		s = (a + b + c)/2; 
		q = s*(s-a)*(s-b)*(s-c);
		area = sqrt(q);
		printf("Area = %.2f\n", area);
    	} 
    	else {
		printf("wrong input\n");
        }//on new line 
	

	return 0;
    }
