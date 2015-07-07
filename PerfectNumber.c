#include<stdio.h>
int isPerfect(int n){
	if(n == 0)
		return 0;
	int i,sum=0;
	for(i=1;i<n;i++){
		if(n%i == 0){
			sum +=i;
		}
	}
	return (sum == n) ? 1 : 0;
}
int main(void) {
	int n;
	scanf("%d",&n);
	puts(isPerfect(n) ? "Yes" : "No");
	return 0;
}
