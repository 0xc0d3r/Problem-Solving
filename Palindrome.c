#include<stdio.h>
int reverse(int n){
	int sum=0;
	while(n){
		sum = sum*10 + n%10;
		n/=10;
	}
	return sum;
}
int main(void) {
	int n,temp;
	scanf("%d",&n);
	temp = reverse(n);
	puts( (n == temp) ? "Yes" : "No");
	return 0;
}
