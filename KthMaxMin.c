#include<stdio.h>
int QuickSelect(int A[],int n,int k){
	int r=0,si=0,li=0,A1[n],A2[n];
	int pivot = A[r],i;
	for(i=0;i<n;i++){
		if(A[i] < pivot) {
			A1[si++] = A[i];
		}
		else if(A[i] > pivot) {
			A2[li++] = A[i];
		}
	}
	if(k<=si){
		return QuickSelect(A1,si,k);
	}
	else if(k > (n-li)){
		return QuickSelect(A2,li,k-(n-li));
	}
	else
		return pivot;

}
int main(void) {
	int n,k,i;
	scanf("%d %d",&n,&k);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d\n",QuickSelect(a,n,k));
	return 0;
}
