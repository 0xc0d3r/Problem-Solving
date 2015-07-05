#include<stdio.h>
#include<math.h>
main(int argc,char *argv[],char *env[]) {
	int num,isPrime=0,i;
	printf("\nEnter Any Positive Integer : ");
	if(scanf("%d",&num) && num > 1) {
	    if(num == 1) isPrime = 0;
	    else if(num == 2) isPrime = 1;
	    else{
		    for(i=3;i<=sqrt(num);i+=2) {
			    if(!(num%i)) {	
				    isPrime = 1;
				    break;
			    } 
		    }
	    }
		if(isPrime) printf("\n%d is not a prime number.\n\n",num);
		else printf("\n%d is a prime number.\n\n",num);
	}
	else printf("\nValueError : Positive integer expected, invalid input is given.\n\n");
}
