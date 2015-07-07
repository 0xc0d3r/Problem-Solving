#include<stdio.h>

int max(int a,int b){
	return (a>=b) ? a : b;
}

int maxConsecutiveSum(int arr[],int s,int e){
	int prevMax = arr[s-1],curMax = arr[s-1],i;
	for(i=s;i<e;i++){
		curMax = max(arr[i],curMax+arr[i]);
		prevMax = max(prevMax,curMax);
	}
	return prevMax;
}

int main(void) {
	int n,M,i,choice,x,y;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&M);
	while(M--){
		scanf("%d %d %d",&choice,&x,&y);
		if(choice) printf("%d\n", maxConsecutiveSum(a,x,y));
		else a[x-1] = y;
	}
	return 0;
}