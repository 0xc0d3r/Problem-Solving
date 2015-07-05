#include<stdio.h>
int getDigitsSum(int n){
	int sum=0;
	while(n){
		sum += (n%10);
		n/=10;
	}
	return sum;
}
int main(void) {
	int n;
	scanf("%d",&n);
	printf("%d",getDigitsSum(n));
	return 0;
}
