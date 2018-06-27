#include<stdio.h>
#include<math.h>
	int main (int argc, char *argv[]){
	
	int a, b, c, d, e, f, g, h, i, k, l, m, p,year,E,D;
	printf("Enter Year:\n");
	scanf("%d", &year);
 

	a=year%19;
	b=year/100;
	c=year%100;
	d=b/4;
	e=b%4;
	f=(b+8)/25;
	g=(b-f+1)/3;
	h=(19*a+b-d-g+15)%30;
	i=c/4;
	k=c%4;
	l=(32+2*e+2*i-h-k)%7;
	m=(a+11*h+22*l)/451;

	E=(h+l-7*m+114)/31;  //[3=March, 4=April]
	p=(h+l-7*m+114)%31;

	D=p+1;     //(date in Easter Month)
	

	if 		( E==1) {
		printf(" In %d, the easter is January %d\n",year,D);
	}
		else if ( E==2) {
		printf(" In %d, the easter is Febuary %d\n",year,D);
	}
		else if (  E==3) {
		printf(" In %d, the easter is March %d\n",year,D);
	}
		
		else if (  E==4) {
		printf(" In %d, the easter is April %d\n",year,D);
	}
		
		else if (  E==5) {
		printf(" In %d, the easter is May %d\n",year,D);
	}
		
		else if  ( E==6) {
		printf(" In %d, the easter is June %d\n",year,D);
	}

		else if  (E==7) {

		printf(" In %d, the easter is July %d\n",year,D);
	}

		else if  (E==8) {
		printf(" In %d, the easter is Augustr %d\n",year,D);
	
	}
		else if  (E==9) {
		printf(" In %d, the easter is September %d\n",year,D);
	}
		else if  (E==10) {
		printf(" In %d, the easter is Octomber %d\n",year,D);
	}
		else if (E==11) {
 		
		printf(" In %d, the easter is  November %d\n",year,D);
	}
		else {
		printf(" In %d, the easter is December %d\n",year,D);
	}
	return 0;
}
