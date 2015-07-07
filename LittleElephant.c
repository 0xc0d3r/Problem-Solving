#include<stdio.h>
#include<string.h>
#define MAX 109

int hash[MAX];

int count(int a[],int lj,int rj){
	int count=0,i;
	memset(hash,0,MAX*sizeof(int));
	for(i=lj;i<=rj;i++)
		hash[a[i]]++;
	for(i=1;i<=MAX;i++){
		if(hash[i] == i) count++;
	}
	return count;
}
int main(void) {
	int size,queries;
	scanf("%d %d",&size,&queries);
	int a[size],i,lj,rj;
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	while(queries--){
		scanf("%d %d",&lj,&rj);
		printf("%d\n",count(a,lj-1,rj-1));
	}
	return 0;
}
