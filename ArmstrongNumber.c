#include<stdio.h>
int isArmstrong(int n){
	int i,sum=0,rem,temp = n;
	while(n){
		rem = n%10;
		sum += (rem*rem*rem);
		n/=10;
	}
	return (sum == temp) ? 1 : 0; 
}
int main(void) {
	int n;
	scanf("%d",&n);
	puts(isArmstrong(n) ? "Yes" : "No");
	return 0;
}
