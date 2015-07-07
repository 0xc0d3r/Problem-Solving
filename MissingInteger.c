#include<stdio.h>
int main(void) {
	int n,i,sum1=0,min=9999,sum2=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n-1;i++){
		scanf("%d",&a[i]);
		sum1+=a[i];
		if(a[i]<=min) min = a[i];
	}
	for(i=min;i<min+n;i++){
		sum2 += i;
	}
	printf("%d",sum2-sum1);
	return 0;
}