#include<stdio.h>
#include<math.h>
int main() {
	int n,len=0,ex;
	scanf("%d",&n);
	int cube=n*n*n,N=n;
	while(n){
		n/=10;
		len++;
	}

	ex = pow(10,len);
	puts( (cube%ex) == N ? "yes" : "no") ;
	return 0;
}
