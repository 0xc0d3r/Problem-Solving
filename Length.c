#include<stdio.h>
#include<math.h>
int main() {
	int n,len=0,ex;
	scanf("%d",&n);
	while(n){
		n/=10;
		len++;
	}
	printf("%d\n",len);
	return 0;
}
