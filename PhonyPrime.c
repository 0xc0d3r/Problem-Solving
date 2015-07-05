#include<stdio.h>
#include<math.h>
#define MAX 128

int primes[MAX],primeCount=1;
void print_array(int arr[],int len) {
	int i;
	for(i=0;i<len;i++){
		printf("%d\n",arr[i]);
	}
}

int isPrime(int n){
	if(n<=0) return 0;
	if(n==1 || n==2) return 1;
	if( !(n&1) ) return 0;
	int i;
	for(i=3;i<=sqrt(n);i+=2){
		if(n%i == 0) return 0;
	}
	return 1;
}

void prime_factorization(int n){
	int i,j,factor=0;
	primes[0] = 2;
	for(i=3;i<=n;i+=2){
		factor=0;
		for(j=0;j<primeCount;j++){
			if( !(i%primes[j]) ) {
				factor=1;
				break;
			}
		}
		if(!factor) primes[primeCount++] = i;
	}
}

void phonyPrimes(int s,int e){
	prime_factorization(e);
	int num,pi,tmp,sq;
	for(num=s;num<=e;num++){
		if(isPrime(num)) 
			continue;
		sq = sqrt(num);
		int isPhony = 1;
		for(pi=0;pi<sq;pi++){
			tmp = primes[pi];
			if( num%(tmp*tmp) )
				continue;
			isPhony = 0;
		}
		if(isPhony) printf("%d\n", num);
	}
}
int main() {
	int s,e;
	scanf("%d %d",&s,&e);
	phonyPrimes(s,e);
	return 0;
}
