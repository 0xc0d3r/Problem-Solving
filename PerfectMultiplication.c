#include<stdio.h>

int length(int n){
	int len=0;
	do{
		n/=10;
		len++;
	}while(n);
	return len;
}

void printChar(char c,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%c", c);
	}
}

int max(int a,int b){
	return (a>=b) ?  a : b;
}
void perfectMultiplication(int num1 , int num2){
	int len1,len2,res = num1 * num2,rlen;
	len1 = length(num1);
	len2 = length(num2)+1;
	rlen = length(res);

	printChar(' ',rlen - len1);
	printf("%d\n",num1);
	printChar(' ',rlen - len2);
	printf("*%d\n", num2);

	printChar(' ', rlen - max(len1,len2) );
	printChar('-', max(len1,len2) );
	printf("\n");

	while(num2){
		int tempRes,tempLen;
		tempRes = num1 * (num2 % 10);
		tempLen = tempRes ? length(tempRes) : len1;
		num2/=10;

		printChar(' ', rlen-- - tempLen);
		if(tempRes) 
			printf("%d\n", tempRes);
		else {
			printChar('0',tempLen);
			printf("\n");
		}
	}

	printChar('-',length(res));
	printf("\n%d\n",res);
}
int main(void) {
	int num1,num2;
	scanf("%d %d",&num1,&num2);
	perfectMultiplication(num1,num2);
	
	return 0;
}
